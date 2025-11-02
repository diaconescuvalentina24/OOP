#define _CRT_SECURE_NO_WARNINGS		//pentru functia strcpy
#include <iostream>
using namespace std;				// ca sa nu mai scriu std::cin/cout/endl
#include <cstring>					//pt strlen si strcpy


	//definim clasele

class Echipament {
private:
	//stabilim ce atribute are clasa si le initializam

	char* tipEchipament = nullptr;					// va fi un text
	bool statusCalificare = false;					//true sau false
	int* dataUrmatoareiCalificari = nullptr;		// [zi, luna, an] -> aici as vrea sa construiesc data pe baza unui vector
	float costulUltimeiCalificari = 0.0f;			//costul in lei
	char* id = nullptr;

public:
	//constructorul implicit
	Echipament() {
		tipEchipament = nullptr;
		statusCalificare = false;
		dataUrmatoareiCalificari = nullptr;
		costulUltimeiCalificari = 0.0f;
		id = nullptr;
	}
	//facem metode cu care setam valorile atributelor

	void setTipEchipament(const char* tip) {					//aici avem pointer spre un text constant
		delete[] tipEchipament;
		tipEchipament = nullptr;								//previne accesul accidental la memeorie sterasa
		if (!tip) return;										// daca variabila tip e nullptr, iesim
		
		tipEchipament = new char[strlen(tip) + 1];				//alocam memorie pentru un text
		strcpy(tipEchipament, tip);								//copiez in atribut ce am in variabila tip
	}
	void afisare() const {														//aceasta metoda nu modifica starea interna a obiectului, const se refera la obiectul pe care se apeleaza metoda
		if (tipEchipament != nullptr) {
		cout << "Tipul echipamentului este: " << tipEchipament << endl;			//metoda pentru a afisa atributul

		}
		cout << "Statusul calificarii este: " << 
			(statusCalificare ? "calificat" : "necalificat")
			<< " pentru echipamentul " << id << endl;

		if (dataUrmatoareiCalificari != nullptr) {

			cout << "Data urmatoarei calificari este: " <<
				dataUrmatoareiCalificari[0] << "." <<
				dataUrmatoareiCalificari[1] << "." <<
				dataUrmatoareiCalificari[2] << " " << endl;
		}
		else {
			cout << "Data urmatoarei calificari nu a fost setata. " << endl;
		}

		cout << "Costul ultimei calificarii a fost de: " << costulUltimeiCalificari << " lei." << endl;
	}
	void setStatusCalificare(bool status) {
		this->statusCalificare = status;
	}
	void setIdEchipament(const char* newId) {					//am setat atributul id din clasa
		delete[] id;
		if (!newId) return;
		id = new char[strlen(newId) + 1];
		strcpy(id, newId);
	}
	void setDataUrmCal(int zi, int luna, int an) {
		if (zi < 1 || zi >31 || luna < 1 || luna >12 || an < 1900) {
			throw invalid_argument("Data calendaristica nu este valida.");
		}
		if (dataUrmatoareiCalificari == nullptr) {
			dataUrmatoareiCalificari = new int[3];
		}
		dataUrmatoareiCalificari[0] = zi;
		dataUrmatoareiCalificari[1] = luna;
		dataUrmatoareiCalificari[2] = an;
	}
	void setCostCalificare(float cost) {
		costulUltimeiCalificari = cost;
	}
	void citeste() {
		cout << "Introduceti tipul echipamentului: ";
		char temp[256];										//variabila temporara in care se stocheaza ce introduce user-ul
		cin.getline(temp, 256);								//citeste un sir de caractere
		setTipEchipament(temp);								//ce introduce utilizatorul se duce in memoria obiectului
	}

	// 1)Constructorul de copiere
	Echipament(const Echipament& copie) {
		statusCalificare = copie.statusCalificare;						//am copiat atributele simple alocate static
		costulUltimeiCalificari = copie.costulUltimeiCalificari;

		//pt char* tipEchipament
		if (copie.tipEchipament) {										//daca atributul obiectului sursa (copie) este alocat si nu avem pointer null
			tipEchipament = new char[strlen(copie.tipEchipament) + 1];
			strcpy(tipEchipament, copie.tipEchipament);					//tip.Echipament este atributul obiectului care se construieste, adica Destinatia
		}
		else tipEchipament = nullptr;

		//pt char* id
		if (copie.id) {
			id = new char[strlen(copie.id) + 1];
			strcpy(id, copie.id);
		}
		else id = nullptr;

		//pentru int* dataUrmatoareiCalificati

		if (copie.dataUrmatoareiCalificari) {
			dataUrmatoareiCalificari = new int[3];
			for (int i = 0; i < 3; ++i) {
				dataUrmatoareiCalificari[i] = copie.dataUrmatoareiCalificari[i];
			}
		}
		else dataUrmatoareiCalificari = nullptr;
	}

		// 2) Operator= , se modifica comportamentul implicit al semnului de egalitate, atribuire pt. obiectele de tip Echipament
	Echipament& operator=(const Echipament& copie) {		//argumentul este de tip echipament sub forma de referinta constanta la sursa
		//auto-atribuire
		if (this == &copie) return *this;					//daca adresele sunt egale functia returneaza obiectul curent *this

		delete[] tipEchipament;
		tipEchipament = nullptr;
		delete[] id;
		id = nullptr;
		delete[] dataUrmatoareiCalificari;
		dataUrmatoareiCalificari = nullptr;

		//copiem atributele simple
		statusCalificare = copie.statusCalificare;
		costulUltimeiCalificari = copie.costulUltimeiCalificari;


		//pt char* tipEchipament
		if (copie.tipEchipament) {										//daca atributul obiectului sursa (copie) este alocat si nu avem pointer null
			tipEchipament = new char[strlen(copie.tipEchipament) + 1];
			strcpy(tipEchipament, copie.tipEchipament);					//tip.Echipament este atributul obiectului care se construieste, adica Destinatia
		}


		//pt char* id
		if (copie.id) {
			id = new char[strlen(copie.id) + 1];
			strcpy(id, copie.id);
		}


		//pentru int* dataUrmatoareiCalificati

		if (copie.dataUrmatoareiCalificari) {
			dataUrmatoareiCalificari = new int[3];
			for (int i = 0; i < 3; ++i) {
				dataUrmatoareiCalificari[i] = copie.dataUrmatoareiCalificari[i];
			}
		}
		return *this;


	}

	~Echipament() {											//destructorul nu are parametri si nu rezturneaza nimic; 
		delete[] tipEchipament;								//elibereaza memoria alocata cu new (tipEchipament, dataUrmatoareiCalificari, id);
		delete[] id;
		delete[] dataUrmatoareiCalificari;
	}
};

class AnalistChimist {

};

class Proba {

};





int main() {
	cout << "Vali este in laborator.\n" << endl;
	Echipament e1;
	//e1.setTipEchipament("Reometru DHR-20");				//am creat un obiect din Clasa Echipament si am setat tipul acestuia
	//e1.citeste();											//apel fct citeste care ia de la user tip echi si il seteaza pt obiectul e1
	e1.setIdEchipament("#0001");
	e1.setStatusCalificare(true);
	e1.setDataUrmCal(01, 11, 2025);
	try {
		e1.setDataUrmCal(32, 11, 2025);
	}
	catch (const exception& ex) {
		cout << "Eroare data: " << ex.what() << "\n";		//what() este o metoda a clasei std::exception - obiectul exceptiei, variabila care contine eroarea
	}														//dupa catch se va pastra ultima data valida: 01.11.2025
	e1.setCostCalificare(6899.99f);
	e1.afisare(); 											//am apelat functia afisare din clasa Echipament pentru obiectul e1
	return 0;
 }
