#include <iostream>
#include <cstring>
using namespace std;

class Film {
private:
    string titlu;
    char* regizor;
    float* rating;
    int nrRatinguri;
    int anLansare;

public:

    Film() {
        titlu = "Necunoscut";

        regizor = new char[9];
        strcpy_s(regizor, 9, "Anonim");

        nrRatinguri = 0;
        rating = nullptr;
        anLansare = 2000;
    }

    Film(string titlu, const char* regizor, int anLansare, float* ratinguri, int n) {
        this->titlu = titlu;

        this->regizor = new char[strlen(regizor) + 1];
        strcpy_s(this->regizor, strlen(regizor) + 1, regizor);

        nrRatinguri = n;
        if (n > 0) {
            rating = new float[n];
            for (int i = 0; i < n; i++)
                rating[i] = ratinguri[i];
        }
        else {
            rating = nullptr;
        }

        this->anLansare = anLansare;
    }

    Film(const Film& f) {
        titlu = f.titlu;

        if (f.regizor != nullptr) {
            regizor = new char[strlen(f.regizor) + 1];
            strcpy_s(regizor, strlen(f.regizor) + 1, f.regizor);
        }
        else {
            regizor = nullptr;
        }

        nrRatinguri = f.nrRatinguri;

        if (f.rating != nullptr && f.nrRatinguri > 0) {
            rating = new float[f.nrRatinguri];
            for (int i = 0; i < f.nrRatinguri; i++)
                rating[i] = f.rating[i];
        }
        else {
            rating = nullptr;
        }
        anLansare = f.anLansare;
    }

    Film& operator=(const Film& f) {
        if (this != &f) {

            if (regizor != nullptr)
                delete[] regizor;

            if (rating != nullptr)
                delete[] rating;

            titlu = f.titlu;
            anLansare = f.anLansare;

            if (f.regizor != nullptr) {
                regizor = new char[strlen(f.regizor) + 1];
                strcpy_s(regizor, strlen(f.regizor) + 1, f.regizor);
            }
            else {
                regizor = nullptr;
            }

            nrRatinguri = f.nrRatinguri;
            if (f.rating != nullptr && f.nrRatinguri > 0) {
                rating = new float[f.nrRatinguri];
                for (int i = 0; i < f.nrRatinguri; i++)
                    rating[i] = f.rating[i];
            }
            else {
                rating = nullptr;
            }
        }
        return *this;
    }

    ~Film() {
        if (regizor != nullptr)
            delete[] regizor;

        if (rating != nullptr)
            delete[] rating;
    }

    string getTitlu() const { return titlu; }

    const char* getRegizor() const { return regizor; }

    float* getRatinguri() const { return rating; }

    int getNrRatinguri() const { return nrRatinguri; }

    void setTitlu(string t) {
        if (!t.empty()) titlu = t;
    }

    void setRegizor(const char* r) {
        if (r == nullptr) return;

        if (regizor != nullptr)
            delete[] regizor;

        regizor = new char[strlen(r) + 1];
        strcpy_s(regizor, strlen(r) + 1, r);
    }

    void setRatinguri(float* vect, int n) {
        if (rating != nullptr)
            delete[] rating;

        nrRatinguri = n;

        if (n > 0) {
            rating = new float[n];
            for (int i = 0; i < n; i++)
                rating[i] = vect[i];
        }
        else {
            rating = nullptr;
        }
    }

    void afisare() {
        cout << "\nTitlu: " << this->titlu;
        cout << "\nRegizor: " << (this->regizor ? this->regizor : "NULL");
        cout << "\nRatinguri (" << this->nrRatinguri << "): ";
        cout << "\nAn lansare: " << this->anLansare << endl;;

        if (this->rating != nullptr)
            for (int i = 0; i < this->nrRatinguri; i++)
                cout << this->rating[i] << " ";
        else
            cout << "Niciun rating";

     }

    float getMedieRating() const {
        if (rating == nullptr || nrRatinguri == 0) {
            return 0;
        }
        float suma = 0;
        for (int i = 0; i < nrRatinguri; i++) {
            suma += rating[i];
        }
        return suma / nrRatinguri;
    }

    float getRatingLaPozitie(int poz) const {
        if (poz >= 0 && poz < nrRatinguri && rating != nullptr) {
            return rating[poz];
        }
        else {
            throw "Pozitia ratingului nu este valida!";
        }
    }

    bool operator<(const Film& f) {
        return this->getMedieRating() < f.getMedieRating();
    }

    bool operator>(const Film& f) {
        return this->getMedieRating() > f.getMedieRating();
    }

    float operator()(int pozitie) {
        return this->getRatingLaPozitie(pozitie);
    }

    char& operator[](int index) {
        if (regizor != nullptr &&
            index >= 0 &&
            index < (int)strlen(this->regizor)) {
            return this->regizor[index];
        }
        else {
            throw "Index invalid.";
        }
    }

    Film operator++(int) {
        Film copie = *this;
        this->anLansare++;
        return copie;
    }

    Film operator++() {
        this->anLansare++;
        return *this;
    }

    friend void operator<<(ostream& consola, Film f) {
        consola << endl << "Titlu: " << f.titlu;
        consola << endl << (f.regizor != nullptr ? "Regizor: " + string(f.regizor) : "Regizor nespecificat");
        consola << endl << "An lansare: " << f.anLansare;
        consola << endl << "Nr. ratinguri: " << f.nrRatinguri;
        if (f.rating != nullptr && f.nrRatinguri > 0) {
            consola << endl << "Ratinguri: ";
            for (int i = 0; i < f.nrRatinguri - 1; i++) {
                consola << f.rating[i] << ", ";
            }
            consola << f.rating[f.nrRatinguri - 1] << ".";
            consola << endl << "Media ratingurilor: " << f.getMedieRating();
        }
        else {
            consola << endl << "Fara ratinguri.";
        }
    }

    friend void operator>>(istream& in, Film& f);

};

void operator>>(istream& in, Film& f) {
    cout << endl << "Titlu: ";
    in >> f.titlu;

    cout << endl << "Regizor (un singur cuvant): ";
    if (f.regizor != nullptr) {
        delete[] f.regizor;
        f.regizor = nullptr;
    }
    char buffer[50];
    in >> buffer;
    f.regizor = new char[strlen(buffer) + 1];
    strcpy_s(f.regizor, strlen(buffer) + 1, buffer);

    cout << endl << "An lansare: ";
    in >> f.anLansare;

    cout << endl << "Nr. ratinguri: ";
    in >> f.nrRatinguri;

    if (f.rating != nullptr) {
        delete[] f.rating;
        f.rating = nullptr;
    }

    if (f.nrRatinguri > 0) {
        f.rating = new float[f.nrRatinguri];
        cout << endl << "Introdu ratingurile: ";
        for (int i = 0; i < f.nrRatinguri; i++) {
            cout << endl << "rating[" << i << "]: ";
            in >> f.rating[i];
        }
    }
}

int main() {

    float r1[] = { 8.5f, 9.2f, 7.8f };

    Film f1("Inception", "ChristopherNolan", 2000, r1, 3);
    f1.afisare();

    Film f2 = f1;
    f2.afisare();

    cout << "\n\nf1 < f2 ? " << (f1 < f2 ? "DA" : "NU");
    cout << "\nf1 > f2 ? " << (f1 > f2 ? "DA" : "NU");

    cout << "\n\nRatingul f1 de pe pozitia 1: " << f1(1);

    cout << "\nLitera a 2-a din numele regizorului f1: " << f1[1];

    cout << "\n\nAn lansare f1 inainte de f1++: ";
    operator<<(cout, f1);
    f1++;
    cout << "\nDupa f1++: ";
    operator<<(cout, f1);
    ++f1;
    cout << "\nDupa ++f1: ";
    operator<<(cout, f1);

    Film f3;
    f3 = f1;
    f3.afisare();

    float r2[] = { 9.1f, 8.9f };
    f3.setRatinguri(r2, 2);
    f3.setTitlu("Interstellar");
    f3.setRegizor("Nolan");

    f3.afisare();

    Film f4;
    cin >> f4;
    cout << f4;

    return 0;
}
