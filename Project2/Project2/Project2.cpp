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
	int* dataUrmatoareiCalificari = nullptr;		//aici as vrea sa construiesc data pe baza unui vector
	float costulUltimeiCalificari = 0.0;			//costul in lei
	char* id = nullptr;

public:
	//facem metode cu care setam valorile atributelor

	void setTipEchipament(const char* tip) {
		delete[] tipEchipament;
		tipEchipament = new char[strlen(tip) + 1];
		strcpy(tipEchipament, tip);					//copiez in atribut ce am in variabila tip
	}
	void afisare() {
		if (tipEchipament != nullptr) {
		cout << "Tip echipament: " << tipEchipament << endl;	//metoda pentru a afisa atributul

		}
		cout << "Statusul calificarii este: " << (statusCalificare ? "calificat" : "necalificat") << " pentru echipamentul " << id << endl;
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
	void setIdEchipament(const char* newId) { //am setat atributul id din clasa
		delete[] id;
		id = new char[strlen(newId) + 1];
		strcpy(id, newId);
	}
	void setDataUrmCal(int zi, int luna, int an) {
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
		char temp[256];				//variabila temporara in care se stocheaza ce introduce user-ul
		cin.getline(temp, 256);		//citeste un sir de caractere
		setTipEchipament(temp);		//ce introduce utilizatorul se duce in memoria obiectului
	}
};

class AnalistChimist {

};

class Proba {

};

int main() {
	cout << "Vali este in laborator." << endl;;
	Echipament e1;
	//e1.setTipEchipament("Reometru DHR-20");			//am creat un obiect din Clasa Echipament si am setat tipul acestuia
	//e1.citeste();										//apel fct citeste care ia de la user tip echi si il seteaza pt obiectul e1
	e1.setIdEchipament("#0001");
	e1.setStatusCalificare(true);
	e1.setDataUrmCal(01, 11, 2025);
	e1.setCostCalificare(6899.99);
	e1.afisare(); 									//am apelat functia afisare din clasa Echipament pentru obiectul e1
	return 0;
 }
