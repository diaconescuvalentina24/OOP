#define _CRT_SECURE_NO_WARNINGS //pt a permite strcpy 
#include<iostream>
using namespace std; //pentru a permite cout, endl, string

class Vin {
public:
	//atribut static (partajat de toate obiectele)
	//pt numara cate sticle de vin avem
	static int nrTotalEticheteVin;

	//atribut constant, static const, care va fi initializat in clasa
	static const float taxaAlcool;

	//atribut pointer pentru alocare in HEAP

	char* numeSoi = nullptr; 
	string producator= "Nu exista";
	int anRecolta = 1900;
	float pretSticla = 0.0;
};

class Crama {
public:
	static int nrTotalCrame;
	static const int temperaturaMinCrama = 8; // in grade
	
	char* numeCrama = nullptr;
	string regiune = "regiune neindentificata";
	float suprafataHectare = 0;
	bool producatorBio = false; // da sau nu
};


class Comanda {
public:
	static int nrTotalComenzi;
	static const double TVA ; // 21%
	char* idComanda = nullptr;

	string numeClient = "Ne pare rau, nu s-a identificat numele clientului ";
	int cantitateComandata = 0;
	float valoareComanda = 0.0;
};

//initializam atributele statice in afara claselor, global
const float Vin::taxaAlcool = 1.5; //nu a putut fi initializat in clasa Vin
int Vin::nrTotalEticheteVin = 0;
int Crama::nrTotalCrame = 0;
int Comanda::nrTotalComenzi = 0;
const double Comanda::TVA = 0.21;// nu a putut fi initializat in clasa Comanda

void main() {
	Vin v1; //am creat un obiect vin v1

	v1.producator = "Cotnari";
	v1.anRecolta = 2015;
	v1.pretSticla = 75.77;// am setat atributele

	//setam atributul pointer cu alocare memorie 

	v1.numeSoi = new char[strlen("Tamaioasa") + 1];//am alocat memorie pt soiul "Tamaioasa"+1 care include terminatorul de sir
	strcpy(v1.numeSoi, "Tamaioasa");//am copiat sirul in atributul specific

	Vin::nrTotalEticheteVin++;

	Crama c1;//am creat un obj
	c1.regiune = "Dobrogea";
	c1.suprafataHectare = 105.5;
	c1.producatorBio = true;

	c1.numeCrama = new char[strlen("Vinuri de Macin") + 1];//am alocat memorie
	strcpy(c1.numeCrama, "Vinuri de macin"); // am copiat in atributul specific obj
	Crama::nrTotalCrame++;

	Comanda co1;

	co1.idComanda = new char[strlen("POP_I_11.09.2025") + 1];
	strcpy(co1.idComanda, "POP_I_11.09.2025");

	co1.numeClient = "Popescu Ion";
	co1.cantitateComandata = 4;
	co1.valoareComanda = 304.5;

	//sa afisam atributele create

	cout << "Soi: " << v1.numeSoi << endl;
	cout << "Producatorul de vin este: " << v1.producator << endl;
	cout << "Pretul unei sticle de vin este: " << v1.pretSticla << endl;

	cout << "Taxa pt alcool: " << v1.taxaAlcool << "lei/litru" << endl;

	cout << "Nume crama: " << c1.numeCrama << endl;
	cout << "Regiune: " << c1.regiune << endl;
	cout << "Suprafata de vie : " << c1.suprafataHectare << endl;
	cout << "Productie BIO? : " << c1.producatorBio << endl;
	cout << "Temperatura minima din crama: " << c1.temperaturaMinCrama << endl;



	cout << "Id-ul comenzii este: " << co1.idComanda << endl;
	cout << "Cantitatea comandata este de: " << co1.cantitateComandata << " sticle" << endl;
	cout << "Valoare comanda: " << co1.valoareComanda << endl;
	cout << "TVA-ul aplicat: " << co1.TVA * 100 << " %" << endl;


	cout << "Numar total etichete vin: " << Vin::nrTotalEticheteVin << endl;
	cout << "Numar toatal crame: " << Crama::nrTotalCrame << endl;
	if (co1.nrTotalComenzi != 0) {

		cout << "Numar toatal comenzi:" << Comanda::nrTotalComenzi << endl;
	};
};