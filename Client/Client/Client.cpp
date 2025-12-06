#include <iostream>
#include <string>
#include <fstream>
#include <cstring>

using namespace std;

class Client {
private:
    string nume = "Necunoscut";
    char* adresa = nullptr;
    int varsta = 0;
    bool estePersoanaJuridica = false;

public:
    Client() {}

    Client(string nume, const char* adresa, int varsta, bool estePersoanaJuridica) {
        this->nume = nume;
        this->varsta = varsta;
        this->estePersoanaJuridica = estePersoanaJuridica;

        this->adresa = new char[strlen(adresa) + 1];
        strcpy_s(this->adresa, strlen(adresa) + 1, adresa);
    }

    ~Client() {
        if (this->adresa != nullptr) {
            delete[] this->adresa;
        }
    }

    Client(const Client& copie) {
        this->nume = copie.nume;
        this->varsta = copie.varsta;
        this->estePersoanaJuridica = copie.estePersoanaJuridica;

        if (copie.adresa != nullptr) {
            this->adresa = new char[strlen(copie.adresa) + 1];
            memcpy(this->adresa, copie.adresa, strlen(copie.adresa) + 1);
        }
        else {
            this->adresa = nullptr;
        }
    }

    bool operator!() const {
        return !this->estePersoanaJuridica;
    }

    operator int() const {
        return this->varsta;
    }

    Client operator+(const char* sufix) const {
        Client copie(*this);

        if (copie.adresa != nullptr) {
            char* nouaAdresa = new char[strlen(copie.adresa) + strlen(sufix) + 1];
            strcpy_s(nouaAdresa, strlen(copie.adresa) + strlen(sufix) + 1, copie.adresa);
            strcat_s(nouaAdresa, strlen(copie.adresa) + strlen(sufix) + 1, sufix);

            delete[] copie.adresa;
            copie.adresa = nouaAdresa;
        }

        return copie;
    }

    friend ostream& operator<<(ostream& out, const Client& c) {
        out << endl << "Nume: " << c.nume;
        out << endl << "Varsta: " << c.varsta;
        out << endl << (c.estePersoanaJuridica ? "Persoana juridica" : "Persoana fizica");
        out << endl << (c.adresa != nullptr ? "Adresa: " + string(c.adresa) : "Adresa default");
        return out;
    }

    friend fstream& operator<<(fstream& outFile, const Client& c) {
        outFile << c.nume << endl;
        outFile << c.varsta << endl;
        outFile << c.estePersoanaJuridica << endl;
        outFile << (c.adresa != nullptr ? c.adresa : "NULL") << endl;
        return outFile;
    }

    friend ifstream& operator>>(ifstream& inFile, Client& c) {
        inFile >> c.nume;
        inFile >> c.varsta;
        inFile >> c.estePersoanaJuridica;

        if (c.adresa != nullptr) {
            delete[] c.adresa;
            c.adresa = nullptr;
        }

        char buffer[100];
        inFile >> buffer;

        c.adresa = new char[strlen(buffer) + 1];
        strcpy_s(c.adresa, strlen(buffer) + 1, buffer);

        return inFile;
    }
};

void main() {

    Client client1("Vali", "Str", 29, false);

    fstream fileStream("Client.txt", ios::out);
    fileStream << client1;
    fileStream.close();

    Client clientCopie;
    cout << clientCopie;

    ifstream inputFileStream("Client.txt", ios::in);
    inputFileStream >> clientCopie;
    inputFileStream.close();

    cout << clientCopie;

    cout << endl << "Operator ! : " << (!clientCopie ? "Persoana fizica" : "Persoana juridica");

    int varsta = clientCopie;
    cout << endl << "Varsta obtinuta prin cast: " << varsta;

    Client clientModificat = clientCopie + "newStr";
    cout << endl << "Client cu adresa modificata: " << clientModificat;
}
