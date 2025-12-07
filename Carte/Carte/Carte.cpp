#include <iostream>
#include <string>
#include <fstream>
#include <cstring>

using namespace std;

class Carte {
private:
    string titlu = "Necunoscut";
    string autor = "Anonim";
    int nrPagini = 0;
    int nrExemplare = 0;
    float rating = 0.0f;
    char* gen = nullptr;

public:
    Carte() {}

    Carte(string titlu, string autor, int nrPagini,
        int nrExemplare, float rating, const char* gen) {
        this->titlu = titlu;
        this->autor = autor;
        this->nrPagini = nrPagini;
        this->nrExemplare = nrExemplare;
        this->rating = rating;

        this->gen = new char[strlen(gen) + 1];
        strcpy_s(this->gen, strlen(gen) + 1, gen);
    }

    ~Carte() {
        if (this->gen != nullptr) {
            delete[] this->gen;
        }
    }

    Carte(const Carte& c) {
        this->titlu = c.titlu;
        this->autor = c.autor;
        this->nrPagini = c.nrPagini;
        this->nrExemplare = c.nrExemplare;
        this->rating = c.rating;

        if (c.gen != nullptr) {
            this->gen = new char[strlen(c.gen) + 1];
            strcpy_s(this->gen, strlen(c.gen) + 1, c.gen);
        }
        else {
            this->gen = nullptr;
        }
    }

    double operator/(int nrSesiuni) const {
        if (nrSesiuni <= 0) {
            return 0;
        }
        return (double)this->nrPagini / nrSesiuni;
    }

    int operator%(int n) const {
        if (n == 0) {
            return 0;
        }
        return this->nrPagini % n;
    }

    bool operator>(const Carte& alta) const {
        return this->rating > alta.rating;
    }

    friend ostream& operator<<(ostream& out, const Carte& c) {
        out << endl << "Titlu: " << c.titlu;
        out << endl << "Autor: " << c.autor;
        out << endl << "Nr pagini: " << c.nrPagini;
        out << endl << "Nr exemplare: " << c.nrExemplare;
        out << endl << "Rating: " << c.rating;
        out << endl << "Gen: " << (c.gen != nullptr ? c.gen : "Necunoscut");
        return out;
    }

    friend fstream& operator<<(fstream& outFile, const Carte& c) {
        outFile << c.titlu << endl;
        outFile << c.autor << endl;
        outFile << c.nrPagini << endl;
        outFile << c.nrExemplare << endl;
        outFile << c.rating << endl;
        outFile << (c.gen != nullptr ? c.gen : "NULL") << endl;
        return outFile;
    }

    friend ifstream& operator>>(ifstream& inFile, Carte& c) {
        if (c.gen != nullptr) {
            delete[] c.gen;
            c.gen = nullptr;
        }

        inFile >> c.titlu;
        inFile >> c.autor;
        inFile >> c.nrPagini;
        inFile >> c.nrExemplare;
        inFile >> c.rating;

        char buffer[100];
        inFile >> buffer;

        c.gen = new char[strlen(buffer) + 1];
        strcpy_s(c.gen, strlen(buffer) + 1, buffer);

        return inFile;
    }
};

void main() {

    Carte c1("FundamentePOO", "Popescu", 350, 10, 4.6f, "Educatie");

    fstream fileStream("Carte.txt", ios::out);
    fileStream << c1;
    fileStream.close();

    Carte copie;
    cout << copie;

    ifstream inputFileStream("Carte.txt", ios::in);
    inputFileStream >> copie;
    inputFileStream.close();

    cout << copie;

    Carte c2("RomanPolitisit", "Ionescu", 220, 5, 3.9f, "Fictiune");

    cout << "\n\nc1 are rating mai mare decat c2? "
        << (c1 > c2 ? "DA" : "NU");

    int sesiuni = 7;
    double paginiPerSesiune = copie / sesiuni;
    cout << "\nPagini per sesiune (" << sesiuni
        << " sesiuni): " << paginiPerSesiune;

    int pachet = 50;
    int rest = copie % pachet;
    cout << "\nRestul paginilor la gruparea in pachete de "
        << pachet << " pagini: " << rest << endl;
}
