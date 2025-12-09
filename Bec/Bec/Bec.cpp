#include <iostream>
#include <string>
#include <exception>

using namespace std;

class ExceptieBec : public exception {
public:
    ExceptieBec(const char* mesaj) : exception(mesaj) {}
};

class BecSmart {
private:
    int putere;
    string marca;
    float pret;
    static const float PRET_MINIM;

public:
    BecSmart() {
        this->putere = 0;
        this->marca = "Nedefinita";
        this->pret = 0;
    }

    BecSmart(int putere, string marca, float pret) {
        this->putere = putere;
        this->marca = marca;

        if (pret < PRET_MINIM) {
            throw ExceptieBec("Pretul becului este prea mic!");
        }
        else {
            this->pret = pret;
        }
    }

    void afisare() {
        cout << endl;
        cout << "Marca: " << this->marca;
        cout << endl << "Putere: " << this->putere << " W";
        cout << endl << "Pret: " << this->pret << " lei";
    }
};

const float BecSmart::PRET_MINIM = 5.0f;

class BecSmartRGB : public BecSmart {
private:
    string modLumina;
public:
    BecSmartRGB() : BecSmart() {
        this->modLumina = "Nedefinit";
    }

    BecSmartRGB(int putere, string marca, float pret, string modLumina)
        : BecSmart(putere, marca, pret) {
        this->modLumina = modLumina;
    }

    void afisare() {
        this->BecSmart::afisare();
        cout << endl << "Mod lumina: " << this->modLumina;
    }
};

int main() {
    try {
        BecSmart becIeftin(10, "NoName", 2.5f);
        becIeftin.afisare();
    }
    catch (ExceptieBec e) {
        cout << endl << "Exceptie prinsa: " << e.what();
    }

    BecSmartRGB becRgb(9, "PhilipsHue", 89.99f, "RGB");
    becRgb.afisare();

    cout << endl;
    return 0;
}
