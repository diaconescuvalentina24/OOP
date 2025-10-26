
#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
using namespace std; //permite folosirea cout, endl, string fara std::, :: este global namespace
 


class Medicament {
private:
	const int idMedicament;
	static int contorMedicament; //l-am creat pentru a numara toate obiectele de tip Medicament
	static const int termenDeValabilitate = 36; //luni
	char* denumireComerciala = nullptr;
	float pret;
	int* concentratiiDisponibile = nullptr;
	int numarConcentratii;
	string formaFarmaceutica;

public:

//cream constructorul default
Medicament() : idMedicament(contorMedicament) { //facem o lista de initializare, este obligatorie pt atributele const
	Medicament::contorMedicament++; //utilizam :: pentru ca contorMedicament este un atribut static, nu apartine unei singure clase
	//initializam pointerii cu nullptr
	this->denumireComerciala = nullptr;
	this->concentratiiDisponibile = nullptr;

	//initializam restul membrilor cu valori default

	this->pret = 0.0;
	this->formaFarmaceutica = " comprimate nefilmate ";
	this->numarConcentratii = 1;
}

Medicament(const char* denumireComerciala) : idMedicament(contorMedicament) { //in main vreau sa fac obiect cu orice contructor si la orice constructor
	//trebuie setat idMedicament
	Medicament::contorMedicament++; //am incrementat contorMedicamente, atribut static, nu apartine unei singure clase, folosm ::

	this->denumireComerciala = new char[strlen(denumireComerciala)+1]; //se aloca memorie
	strcpy(this->denumireComerciala, denumireComerciala); //copiat denumire comerciala din Sursa in Destinatie this->denumireComerciala;
	
	// vom initializa si restul membrilor cu valori default

	this->pret = 0.0;
	this->concentratiiDisponibile = nullptr;
	this->formaFarmaceutica = " comprimate nefilmate ";
	this->numarConcentratii = 1;


}

//vom crea constructor cu toti parametrii

Medicament (const char* denumire, float pret, int* concentratiiDisponibile, string formaFarmaceutica, int nrConcentratii) 
: idMedicament(contorMedicament){

	//trebuie setat idMedicament, imediat ce s-a apelat constructorul pt a fi incrementat contorMedicament 
	//care va da un id unic fiecarui obiect

	Medicament::contorMedicament++;

	//facem copiere pt denumireaComerciala pt ca e pointer

	this->denumireComerciala = new char[strlen(denumire) + 1];
	strcpy(this->denumireComerciala, denumire);

	//vom initializa si restul membrilor cu valori default

	this->pret = pret;
	this->formaFarmaceutica = formaFarmaceutica;
	this->numarConcentratii = nrConcentratii;

	this->concentratiiDisponibile = new int[this->numarConcentratii];

	for (int i = 0; i < this->numarConcentratii; i++) {
		this->concentratiiDisponibile[i] = concentratiiDisponibile[i];

	}

}

~Medicament() {
	cout << "acum se apeleaza destructorul" << endl;

	if (this->denumireComerciala != nullptr) {
		delete[] this->denumireComerciala; //eliberam memoria pt denumire
		this->denumireComerciala = nullptr; //initializam memoria pt denumire cu nullptr
	}

	if (this->concentratiiDisponibile != nullptr) {
		delete[] this->concentratiiDisponibile;
		this->concentratiiDisponibile = nullptr;
	}
}

//vom crea o metoda de afisare

void afisare() {
	cout << "ID Medicament: " << this->idMedicament << endl;
	if (this->denumireComerciala != nullptr) {
		cout << "Denumire comerciala: " << this->denumireComerciala << endl;
	}
	cout << "Pret: " << this->pret << endl;
	cout << "Forma farmaceutica a produsului:" << this->formaFarmaceutica << endl;
	cout << "Termen de valabilitate:" << this->termenDeValabilitate <<" luni." << endl;

	if (this->numarConcentratii > 0 && this->concentratiiDisponibile != nullptr) {
		cout << "Concentratiile disponibile pt acest produs sunt: " << endl;
		for (int i = 0; i < this->numarConcentratii; i++) {

			cout << this->concentratiiDisponibile[i] << " mg";
		}
		cout << endl;
	}
}




};


int Medicament::contorMedicament = 0; //am initializat atributul static


void main() {
	//Apelam constructorul default
	Medicament ibuprofen;
	ibuprofen.afisare(); //da eroare. nvm

	Medicament m2 = Medicament("faringo");
	m2.afisare();

	//const char* denumire, float pret, int* concentratiiDisponibile, string formaFarmaceutica, int nrConcentratii)
	int concentratiiPtIbusinus[] = { 15, 50, 100, 200 };
	Medicament m3 = Medicament("ibusinus", 9.99, concentratiiPtIbusinus, "comprimate filmate", 4);
	m3.afisare();


	//Medicament betahistina = Medicament(); // contruim un obiect prin apelarea constructorului implicit
	//Medicament::contorMedicament++;

	//Medicament atomoxetina; // am mai contruit un obiect aici
	//Medicament::contorMedicament++;

	////am setat atributele
	//betahistina.pret = 47.77;
	//betahistina.concentratiiDisponibile = new int [3]; //alocam memorie pentru 3 int-uri
	//betahistina.concentratiiDisponibile[0] = 12;
	//betahistina.concentratiiDisponibile[1] = 20;
	//betahistina.concentratiiDisponibile[2] = 50;

	//betahistina.formaFarmaceutica = "capsule";

	//betahistina.denumireComerciala = new char[strlen("Betina")+1]; //alocam memorie in HEAP pt atributul pointer
	//strcpy(betahistina.denumireComerciala, "Betina"); //am copiat datele in spatiul alocat

	//cout << "Pretul pt produsul farmaceutic " << betahistina.denumireComerciala << " este " << betahistina.pret << " RON." << endl;
	//cout << "Produsul exista sub forma de" << betahistina.formaFarmaceutica << " cu concentratia de " 
	//	<< betahistina.concentratiiDisponibile[0] << " mg/cpr, " << *(betahistina.concentratiiDisponibile + 1) << " mg/cpr, " 
	//	<< *(betahistina.concentratiiDisponibile + 2) << " mg/cpr " << endl;
	//


	////am setat atributele
	//atomoxetina.pret = 87.77;
	//atomoxetina.concentratiiDisponibile = new int[3]; //alocam memorie pentru 3 int-uri
	//atomoxetina.concentratiiDisponibile[0] = 100;
	//atomoxetina.concentratiiDisponibile[1] = 150;
	//atomoxetina.concentratiiDisponibile[2] = 200;

	//atomoxetina.formaFarmaceutica = "comprimate filmate";

	//atomoxetina.denumireComerciala = new char[strlen("Exotrima") + 1]; //alocam memorie in HEAP pt atributul pointer
	//strcpy(atomoxetina.denumireComerciala, "Exotrima"); //am copiat datele in spatiul alocat

	//cout << "Pretul pt produsul farmaceutic " << atomoxetina.denumireComerciala << " este " << atomoxetina.pret << " RON." << endl;
	//cout << "Produsul exista sub forma de " << atomoxetina.formaFarmaceutica << " cu concentratia de "
	//	<< atomoxetina.concentratiiDisponibile[0] << " mg/cpr, " << *(atomoxetina.concentratiiDisponibile + 1) << " mg/cpr, "
	//	<< *(atomoxetina.concentratiiDisponibile + 2) << " mg/cpr " << endl;
	//cout << "Valoarea atributului static contorMedicament este  " << Medicament::contorMedicament << " .";

	////am dezalocat memorie
	//delete[] betahistina.denumireComerciala;
	//betahistina.denumireComerciala = nullptr;
	//delete[] betahistina.concentratiiDisponibile;
	//betahistina.concentratiiDisponibile = nullptr;
	//delete[] atomoxetina.denumireComerciala;
	//atomoxetina.denumireComerciala = nullptr;
	//delete[] atomoxetina.concentratiiDisponibile;
	//atomoxetina.concentratiiDisponibile = nullptr;

};

