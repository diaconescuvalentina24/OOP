#include <iostream>
#include <cstring>
using namespace std;

class Film {
private:
    string titlu;
    char* regizor;
    float* rating;
    int nrRatinguri;

public:

    Film() {
        titlu = "Necunoscut";

        regizor = new char[9];
        strcpy_s(regizor, 9, "Anonim");

        nrRatinguri = 0;
        rating = nullptr;
    }

    Film(string titlu, const char* regizor, float* ratinguri, int n) {
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
    }

    Film& operator=(const Film& f) {
        if (this != &f) {

            if (regizor != nullptr)
                delete[] regizor;

            if (rating != nullptr)
                delete[] rating;

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

        if (this->rating != nullptr)
            for (int i = 0; i < this->nrRatinguri; i++)
                cout << this->rating[i] << " ";
        else
            cout << "Niciun rating";

        }
};

int main() {

    float r1[] = { 8.5f, 9.2f, 7.8f };

    Film f1("Inception", "ChristopherNolan", r1, 3);
    f1.afisare();

    Film f2 = f1;
    f2.afisare();

    Film f3;
    f3 = f1;
    f3.afisare();

    float r2[] = { 9.1f, 8.9f };
    f3.setRatinguri(r2, 2);
    f3.setTitlu("Interstellar");
    f3.setRegizor("Nolan");

    f3.afisare();

    return 0;
}
