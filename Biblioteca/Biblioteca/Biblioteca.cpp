#include<iostream>

using namespace std;

class Biblioteca {
private:
    string numeBiblioteca = "DEFAULT";
    char* oras = nullptr;
    int numarCititori = 0;
    int* cartiImprumutatePerCititor = nullptr;
public:
    Biblioteca() {

    }

    void setNumarCititori(int numarCititori) {
        this->numarCititori = numarCititori;
    }

    int getNumarCititori() {
        return this->numarCititori;
    }

    void setCartiImprumutatePerCititor(int* cartiImprumutatePerCititor, int numarCititori) {
        this->numarCititori = numarCititori;
        this -> cartiImprumutatePerCititor = new int[numarCititori];
        for (int i = 0; i < numarCititori; i++) {
            this->cartiImprumutatePerCititor[i] = cartiImprumutatePerCititor[i];
        }
    }

    int* getCartiImprumutatePerCititor() {
        return this->cartiImprumutatePerCititor;
    }

    void setNumeBiblioteca(string numeBiblioteca) {
        this->numeBiblioteca = numeBiblioteca;
    }

    string getNumeBiblioteca() {
        return this->numeBiblioteca;
    }

    char* getOras() {
        return this->oras;
    }

    void setOras(const char* oras) {
        if (this->oras != nullptr) {
            delete[] this->oras;
        }
        this->oras = new char[strlen(oras) + 1];
        strcpy_s(this->oras,strlen(oras) + 1, oras);
    }

    void afisare() {
        cout << "Nume: " << this->numeBiblioteca << endl;
        if (this->oras != nullptr) {
            cout << "Oras: " << this->oras << endl;
        }
        cout << "Nr cititori: " << this->numarCititori << endl;
        cout << "Carti imprumutate per cititor:" << endl;
        for (int i = 0; i < numarCititori; i++) {
            cout << "Cititorul " << i << " a imprumutat " << this->cartiImprumutatePerCititor[i] << endl;
        }
        cout << "=======" <<endl;
    }

    Biblioteca(string nume, const char* oras, int numarCititori, int* cartiImprumutatePerCititor) {
        this->numeBiblioteca = nume;
        this->numarCititori = numarCititori;
        if (oras != nullptr) {
            setOras(oras);
        }

        setCartiImprumutatePerCititor(cartiImprumutatePerCititor, numarCititori);
    }

    void operator=(Biblioteca& copie) {
        this->numeBiblioteca = copie.numeBiblioteca;
        if (copie.oras != nullptr) {
            setOras(copie.oras);
        }

        if (copie.cartiImprumutatePerCititor != nullptr) {
            setCartiImprumutatePerCititor(copie.cartiImprumutatePerCititor, copie.numarCititori);
        }
    }

    void operator+=(string nume) {
        this->numeBiblioteca += nume;
    }

    void operator+=(Biblioteca& biblioteca) {
        this->numeBiblioteca += biblioteca.numeBiblioteca;
    }

    //implementare operator functie
    int operator()(int pozitie) {
        return this->cartiImprumutatePerCititor[pozitie];
    }

     char& operator[](int pozitie) {
         return this->numeBiblioteca[pozitie];
    }
};


void main() {
    Biblioteca b1;
    int* c = new int[3] {1, 2, 3};

    b1.setNumarCititori(3);
    b1.setCartiImprumutatePerCititor(c, 3);

    b1.setOras("Roman");

    b1.afisare();

    Biblioteca b2("Biblioteca universitara", "Braila", 3, new int[3] {5, 6, 7});

    b2.afisare();

    b1 = b2;
    b1.afisare();

    //operator += pe string
    b1 += "testing";
    b1.afisare();

    b1.setNumeBiblioteca("Biblioteca centrala");
    //operator += pe obiecte
    b1 += b2;
    b1.afisare();

    //operator functie
    cout << "Cititorul 2 a imprumutat nr de carti: " <<  b1(2) <<endl;
    cout << "Litera de pe pozitia 2 din numele bibliotecii este: " << b1[2] << endl;

    b1[0] = 'A';
    cout << "Nume " << b1.getNumeBiblioteca();
}