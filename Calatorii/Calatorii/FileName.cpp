#include<iostream>
using namespace std;

class CartelaTransport {
	const string serieCartela;
	string numePosesor;
	int nrZileUtilizare;
	float sumaPortofel;
	int nrCalatorii;
	float* valoriCalatorii;
	static float valoareaMinCalatorie;

public:
	//constructor default
	CartelaTransport() :serieCartela("valoare default") {
		this->numePosesor = "nu este cunoscut numele posesorului ";
		this->nrZileUtilizare = 0;
		this->sumaPortofel = 0.0;
		this->nrCalatorii = 0;
		this->valoriCalatorii = nullptr;
	}
	//getteri

	string getNumePosesor() {
		return this->numePosesor;
	}
	float* getValoriCalatorii() {
		return this->valoriCalatorii;
	 }

	//setteri

	void setNumePosesor(string numePosesor) {
		
		if (numePosesor.length() > 0) {
			this->numePosesor = numePosesor;

		}
	}

	void setValoriCalatorii(int nrCalatorii, float* valoriCalatorii) {
		if (nrCalatorii > 0) {
			this->nrCalatorii = nrCalatorii;
			if (this->valoriCalatorii != nullptr) {
				delete[] this->valoriCalatorii;
			}
			this->valoriCalatorii = new float[nrCalatorii];
			for (int i = 0; i < nrCalatorii; i++) {
				this->valoriCalatorii[i] = valoriCalatorii[i];

			}

		}

		
	}



	//constructor cu parametri
	CartelaTransport(string numePosesor,int nrZileUtilizare, float sumaPortofel, int nrCalatorii, const float* valoriCalatorii, const string serieCartela) : serieCartela(serieCartela) {
		if (numePosesor.length() > 0) {
		this->numePosesor = numePosesor;

		}
		if (nrZileUtilizare > 0) {
		this->nrZileUtilizare = nrZileUtilizare;

		}
		if (sumaPortofel > 0) {
		this->sumaPortofel = sumaPortofel;

		}
		if (nrCalatorii > 0) {
		this->nrCalatorii = nrCalatorii;

		}
		if (valoriCalatorii != nullptr) {
		this->valoriCalatorii = new float[nrCalatorii];
		for (int i = 0; i < nrCalatorii; i++) {
			this->valoriCalatorii[i] = valoriCalatorii[i];

		}
		}
	}

	//constructor de copiere

	CartelaTransport( const CartelaTransport& copie):serieCartela(copie.serieCartela) {
		if (copie.numePosesor.length() > 0) {
			this->numePosesor = copie.numePosesor;

		}
		if (copie.nrZileUtilizare > 0) {
			this->nrZileUtilizare = copie.nrZileUtilizare;

		}
		if (copie.sumaPortofel > 0) {
			this->sumaPortofel = copie.sumaPortofel;

		}
		if (copie.nrCalatorii > 0) {
			this->nrCalatorii = copie.nrCalatorii;

		}
		if (copie.valoriCalatorii != nullptr) {
			this->valoriCalatorii = new float[copie.nrCalatorii];
			for (int i = 0; i < copie.nrCalatorii; i++) {
				this->valoriCalatorii[i] = copie.valoriCalatorii[i];

			}
		}
	}

	//operator=

void operator=(const CartelaTransport& copie) {
		if (copie.numePosesor.length() > 0) {
			this->numePosesor = copie.numePosesor;

		}
		if (copie.nrZileUtilizare > 0) {
			this->nrZileUtilizare = copie.nrZileUtilizare;

		}
		if (copie.sumaPortofel > 0) {
			this->sumaPortofel = copie.sumaPortofel;

		}
		if (copie.nrCalatorii > 0) {
			this->nrCalatorii = copie.nrCalatorii;

		}
		if (this->valoriCalatorii != nullptr) {
			delete[] this->valoriCalatorii;
			this->valoriCalatorii = nullptr;
		 }

		if (copie.valoriCalatorii != nullptr) {
			this->valoriCalatorii = new float[copie.nrCalatorii];
			for (int i = 0; i < copie.nrCalatorii; i++) {
				this->valoriCalatorii[i] = copie.valoriCalatorii[i];

			}
		}
	}

	
	void afisare() {
		cout << this->nrCalatorii << "numarul de calatorii " << endl;
		cout << this->nrZileUtilizare << "numarul de zile utilizate " << endl;
		cout << this->numePosesor << "- Nume posesor." << endl;
		cout << this->sumaPortofel << "- suma portofel." << endl;
		if (this->valoriCalatorii != nullptr && nrCalatorii>0) {
			for (int i = 0; i < this->nrCalatorii; i++) {
				cout << this->valoriCalatorii[i] << "- valoarea calatoriei- " << i << endl;
			}
		}
		cout << this->serieCartela << " - seria cartelei " << endl;
	}

};
float CartelaTransport::valoareaMinCalatorie = 0;

void main() {

	float* valori = new float[2] {5.5, 4.5};
	float*valori1= new float[3] {5.5, 4.5, 5.0};

	CartelaTransport cartela1("Costel", 31, 99.99, 2, valori, "abcd");
	cartela1.afisare();
	//cartela1.setNumePosesor("Marcel");
	cout << cartela1.getNumePosesor() << " test get/set-nume. "<<endl;
	cartela1.setValoriCalatorii(3, valori1);
	cout << cartela1.getValoriCalatorii()[0] << " test get/set -valoriCalatorii."<<endl;

	CartelaTransport cartela2 = cartela1;
	cartela2.afisare();
	CartelaTransport cartela3;
	cartela3 = cartela1;
	cartela3.afisare();
	


}