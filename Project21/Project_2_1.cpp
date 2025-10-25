
#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
using namespace std; //permite folosirea cout, endl, string fara std::, :: este global namespace
 


class Medicament {
public:
	static int contorMedicament; //l-am creat pentru a numara toate obiectele de tip Medicament
	static const int termenDeValabilitate = 36; //luni
	char* denumireComerciala = nullptr;
	float pret;
	int* concentratiiDisponibile = nullptr;
	string formaFarmaceutica;



};

int Medicament::contorMedicament = 0; //am initializat atributul static

void main() {

	Medicament betahistina = Medicament(); // contruim un obiect prin apelarea constructorului implicit
	Medicament::contorMedicament++;

	Medicament atomoxetina; // am mai contruit un obiect aici
	Medicament::contorMedicament++;

	//am setat atributele
	betahistina.pret = 47.77;
	betahistina.concentratiiDisponibile = new int [3]; //alocam memorie pentru 3 int-uri
	betahistina.concentratiiDisponibile[0] = 12;
	betahistina.concentratiiDisponibile[1] = 20;
	betahistina.concentratiiDisponibile[2] = 50;

	betahistina.formaFarmaceutica = "capsule";

	betahistina.denumireComerciala = new char[strlen("Betina")+1]; //alocam memorie in HEAP pt atributul pointer
	strcpy(betahistina.denumireComerciala, "Betina"); //am copiat datele in spatiul alocat

	cout << "Pretul pt produsul farmaceutic " << betahistina.denumireComerciala << " este " << betahistina.pret << " RON." << endl;
	cout << "Produsul exista sub forma de" << betahistina.formaFarmaceutica << " cu concentratia de " 
		<< betahistina.concentratiiDisponibile[0] << " mg/cpr, " << *(betahistina.concentratiiDisponibile + 1) << " mg/cpr, " 
		<< *(betahistina.concentratiiDisponibile + 2) << " mg/cpr " << endl;
	


	//am setat atributele
	atomoxetina.pret = 87.77;
	atomoxetina.concentratiiDisponibile = new int[3]; //alocam memorie pentru 3 int-uri
	atomoxetina.concentratiiDisponibile[0] = 100;
	atomoxetina.concentratiiDisponibile[1] = 150;
	atomoxetina.concentratiiDisponibile[2] = 200;

	atomoxetina.formaFarmaceutica = "comprimate filmate";

	atomoxetina.denumireComerciala = new char[strlen("Exotrima") + 1]; //alocam memorie in HEAP pt atributul pointer
	strcpy(atomoxetina.denumireComerciala, "Exotrima"); //am copiat datele in spatiul alocat

	cout << "Pretul pt produsul farmaceutic " << atomoxetina.denumireComerciala << " este " << atomoxetina.pret << " RON." << endl;
	cout << "Produsul exista sub forma de " << atomoxetina.formaFarmaceutica << " cu concentratia de "
		<< atomoxetina.concentratiiDisponibile[0] << " mg/cpr, " << *(atomoxetina.concentratiiDisponibile + 1) << " mg/cpr, "
		<< *(atomoxetina.concentratiiDisponibile + 2) << " mg/cpr " << endl;
	cout << "Valoarea atributului static contorMedicament este " << Medicament::contorMedicament << ".";

};

