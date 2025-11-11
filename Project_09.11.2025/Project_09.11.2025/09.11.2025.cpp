#define _CRT_SECURE_NO_WARNINGS //pt a permite strcpy 
#include<iostream>
using namespace std; //pentru a permite cout, endl, string

class Vin {
	//atribut static 
	// contor pt numara cate sticle de vin avem (partajat de toate obiectele clasei)
	static int nrTotalEticheteVin;

	//atribut constant, static const, care va fi initializat in clasa, nu poste fi modificat, partajat de toate obiectele clasei
	static const float taxaAlcool;

	//atribut pointer pentru alocare in HEAP
	char* numeSoi = nullptr; 
	string producator= "Nu exista";
	int anRecolta = 1900;
	float pretSticla = 0.0;
	const int idVin;

public:
	//Getters si setters pentru a citi datele din private, acces controlat
	//atributele sunt private->exteriorul clasei nu poate accesa direct
	//get-erii doar returneaza o valoare deja existenta
	int getIdVin() const { //punem const dupa parametrii pentru ca nu modifica niciun atribut
		return this->idVin;

	}
	//tipul metodei este constant, nu parametrii; metodele nu modifica obiectul

	static int getNrTotatlEticheteVin() { //get-er pt atribut static
		return Vin::nrTotalEticheteVin;
	}
	char* getNumeSoi() const {
		return this->numeSoi;
	}

	string getProducator() const {
		return this->producator;
	}

	int getAnRecolta() const {
		return this->anRecolta;
	}
	float getPretSticla() const {
		return this->pretSticla;
	}

	//facem SETTERS pentru a modifica valoarea atributelor private
	//scopul set-erului este sa modifice obiectul
	//set-erii nu pot fi const
	void setNumeSoi(const char* numeSoiNou) {//aici punem const pt ca adresa nu tb modificata
		if (numeSoiNou != nullptr && strlen(numeSoiNou) > 2) {//nu punem * pentru ca avem nevoie de valoarea parametrului
			if (this->numeSoi != nullptr) {
				delete[] this->numeSoi;//am sters ce aveam in atribut
			}
			//alocam memorie pt a seta noua valoare a atributului
			this->numeSoi = new char[strlen(numeSoiNou) + 1];
			//copiem datele in atribut
			strcpy(this->numeSoi, numeSoiNou);
		}
	}

	//SETTER pentru string
	void setProducator(string producatorNou) {
		if (producatorNou.length() > 3) {
			this->producator = producatorNou;
		}
	}

	//SETTER pt float
	void setPretSticla(float pretNou) {
		if (pretNou > 0) {
			this->pretSticla = pretNou;
		}
	 }
	
	//constructor default

	Vin() :idVin(nrTotalEticheteVin) { //facem o lista de initializare, este obligatorie pt atributele const
		//lista de initializare este locul unde atributele sunt initializate
		//atributele se initializeaza direct
		//variabilele const nu pot fi modificate in corpul constructorului
		Vin::nrTotalEticheteVin++; //utilizam :: pt ca nrTotalEticheteVIn este
		//un atribut static, nu apartine unei singure clase

		this->numeSoi = nullptr; //am nitializat pointerul cu nullptr
		this->producator = "Necunoscut";//am initializat restul membrilor cu valori default
		this->anRecolta = 1900;
		this->pretSticla = 0.0;
	}

	//constructorul cu toti parametrii

	Vin(const char* numeSoi, string producator, int anRecolta, float pretSticla) 
		:idVin(nrTotalEticheteVin), numeSoi(nullptr) {
		Vin::nrTotalEticheteVin++;

		this->numeSoi = new char[strlen(numeSoi) + 1];
		strcpy(this->numeSoi, numeSoi);

		this->producator = producator;
		this->anRecolta = anRecolta;
		this->pretSticla = pretSticla;

	}
	//CONSTRUCTORUL DE COPIERE, se apeleaza cand v2=v1

	Vin(const Vin& copie) :idVin(nrTotalEticheteVin) { //facem o lista de initializare, este obligatorie pt atributele const
		Vin::nrTotalEticheteVin++; //utilizam :: pt ca nrTotalEticheteVIn este
		

		this->producator = copie.producator;
		this->anRecolta = copie.anRecolta;
		this->pretSticla = copie.pretSticla;

		if (copie.numeSoi != nullptr) {
			this->numeSoi = new char[strlen(copie.numeSoi) + 1];
			strcpy(this->numeSoi, copie.numeSoi);
		}
		else {
			this->numeSoi = nullptr;
		}
	}

	//SUPRAINCARCARE operator =, se apeleaza la v_default = v2
	Vin& operator=(const Vin& copie) {
		cout << "Se apeleaza operatorul = " << endl;
		//verificare pentru auto-atribuire, v1=v1

		if (this != &copie) {
			this->producator = copie.producator;
			this->anRecolta = copie.anRecolta;
			this->pretSticla = copie.pretSticla;

			//eliberam memorie
			if (this->numeSoi != nullptr) {
				delete[] this->numeSoi;
				this->numeSoi = nullptr;
			}

			//alocam memorie si copiem din "copie"

			if (copie.numeSoi != nullptr) {
				this->numeSoi = new char[strlen(copie.numeSoi) + 1];
				strcpy(this->numeSoi, copie.numeSoi);
			}else {
				this->numeSoi = nullptr;
			}
		}
		return *this;
	}



	//destructorul
	~Vin() {
		if (this->numeSoi != nullptr) {
			delete[] this->numeSoi;
			this->numeSoi = nullptr;
		}
	}

	void afisare() {
		cout << "--ID Vin-- " << this->idVin << endl;
		cout << "Producator " << this->producator << endl;
		cout << "an: " << this->anRecolta << endl;
		cout << "Pret: " << this->pretSticla <<" lei." << endl;

		cout << "Soi: " << (this->numeSoi != nullptr ? this->numeSoi : "N/A") << endl;
		cout << "Taxa vin: " << Vin::taxaAlcool << endl;
	}
};

class Crama {
	const int idCrama;
	static int nrTotalCrame;
	static const int temperaturaMinCrama = 8; // in grade
	
	char* numeCrama = nullptr;
	string regiune = "regiune neindentificata";
	float suprafataHectare = 0;
	bool producatorBio = false; // da sau nu
	//Crama* this;


public:
	// GETTERS
	int getIdCrama() const {
		return (*this).idCrama;
		//return this->idCrama;
	}
	static int getNrTotalCrame() {
		return Crama::nrTotalCrame;
	}
	char* getNumeCrama()const {
		return this->numeCrama;
	}
	string getRegiune() const {
		return this->regiune;
	}
	float getSuprafata() const {
		return this->suprafataHectare;
	}
	bool isProducatorBio() {
		return this->producatorBio;
	}

	//SETTERS
	void setNumeCrama(const char* numeNou) {
		if (numeNou != nullptr && strlen(numeNou) > 2) {
			if (this->numeCrama != nullptr) {
				delete[] this->numeCrama;
			}
			this->numeCrama = new char[strlen(numeNou) + 1];//alocam memorie
			strcpy(this->numeCrama, numeNou);
		}
	}

	void setSuprafata(float suprafataNoua) {
		if (suprafataNoua > 0) {
			this->suprafataHectare = suprafataNoua;
		}
	}

	void setRegiune(string regiuneNoua) {
		if (regiuneNoua.length() > 3) {
			this->regiune = regiuneNoua;
		}	
	}

	//constructor Default
	Crama() :idCrama(nrTotalCrame) {
		Crama::nrTotalCrame++;
		this->numeCrama = nullptr;
		this->regiune = "Necunoscuta";
		this->suprafataHectare = 0.0;
		this->producatorBio = false;
	}

	//Constructor cu un parametru
	Crama(const char* numeCrama) :idCrama(nrTotalCrame) {
		Crama::nrTotalCrame++;
		this->numeCrama = new char[strlen(numeCrama) + 1];
		strcpy(this->numeCrama, numeCrama);
		this->regiune = "Necunoscuta";
		this->suprafataHectare = 0.0;
		this->producatorBio = false;
	}

	//constructor cu toti parametrii
	Crama(const char* numeCrama, string regiune, float suprafata, bool produceBio)
		:idCrama(nrTotalCrame){
		Crama::nrTotalCrame++;
		this->numeCrama = new char[strlen(numeCrama) + 1];
		strcpy(this->numeCrama, numeCrama);
		this->regiune = regiune;
		this->suprafataHectare = suprafata;
		this->producatorBio = produceBio;
	}

	// constructorul de copiere
	Crama(const Crama& copie): idCrama(nrTotalCrame) {
		//primeste referinta la obiect de tip Crama; const pentru ca nu modificam obiectul sursa (copie)
		Crama::nrTotalCrame++;
		if (copie.numeCrama != nullptr) {
			this->numeCrama = new char[strlen(copie.numeCrama) + 1];
			strcpy(this->numeCrama, copie.numeCrama);
		}//cand numele parametrului este identic cu numele atributului, compilerul nu stie la ce te referi
		else {
			this->numeCrama = nullptr;
		}
		this->regiune = copie.regiune;
		this->suprafataHectare = copie.suprafataHectare;
		this->producatorBio = copie.producatorBio;
	}

	//operator=
	void operator=(const Crama& copie) {//intoarcem o referinta la obiectul curent
		//operatorul de atribuire este suprascris
		//nu este modificat obj sursa, se primeste ca si referinta Crama&, copie este numele obiectului din care copiem
		if (this != &copie) { //pointerul la obj curent != de adresa copiei, sa nu facem auto-atribuire (copia si destinatia au aceeasi adresa!!!!)
			if (this->numeCrama != nullptr) {//verificam daca obiectul curent are deja memorie alocata
				delete[] this->numeCrama;
				this->numeCrama = nullptr;
			}
			//sageata se pune mereu doar la pointeri (dereferentiere + accesare)
			if (copie.numeCrama != nullptr) {
				this->numeCrama = new char[strlen(copie.numeCrama) + 1];//alocam memorie in heap pentru numele cramei
				strcpy(this->numeCrama, copie.numeCrama);
			}
			else {
				this->numeCrama = nullptr;
			}
			//copiem restul atributelor
			this->regiune = copie.regiune;
			this->suprafataHectare = copie.suprafataHectare;
			this->producatorBio = copie.producatorBio;
			//return *this;
		}
	}

	~Crama(){
		cout << "Am apelat destructorul! " << endl;
		if (this->numeCrama != nullptr) {
			delete[] this->numeCrama;
			this->numeCrama = nullptr;
		}
	}

	void afisare() {
		//static int nrTotalCrame;
		//string regiune = "regiune neindentificata";
		//float suprafataHectare = 0;
		//bool producatorBio = false; // da sau nu

		if (this->numeCrama != nullptr) {
			cout << "Nume crama: " << this->numeCrama<<endl;
		}
		else cout << "N/A. "<<endl;
		cout << "Id-ul cramei este: " << getIdCrama()<<endl; 
		cout << "Temperatura minima in crama este setata la: " << this->temperaturaMinCrama << " grade C." << endl;
		cout << "Suprafata hectare: " << suprafataHectare << endl;
		cout << "Bio status: " << producatorBio << endl;
	}
};


class Comanda {

public:
	float greutateComanda ;
	char* numeComanda ;
	int idComanda = 0; //nu vreau sa fie static pt ca este specific unui singur obiect
	string adresaLivrare ;
	int* idVinuriComanda ; //pentru a identifica produsele din comanda
	static int nrComenzi;
	int nrIdVinuriComanda;
	//GET-eri

	float getGreutateComanda() const {
		return this->greutateComanda;
	}
	int getIdComanda() const {
		return this->idComanda;
	}
	string getAdresaLivrare()const {
		return this->adresaLivrare;
	}
	char* getNumeComanda() const {
		return this->numeComanda;
	}
	int* getIdVinuriComanda()const {
		return this->idVinuriComanda;
	}
	int getNrIdVinuriComanda() const {
		return this->nrIdVinuriComanda;
	}
	//nu trebuie getteri pt atibutele statice

	//SET-eri
	void setGreutateComanda(float greutateComanda) {
		if (greutateComanda > 0) {
			this->greutateComanda = greutateComanda;
		}

	}
	void setIdComanda(int idComanda) {
		if (idComanda > 0) {
			this->idComanda = idComanda;
		}
	}

	void setNumeComanda(const char* numeComanda) {
		if (numeComanda != nullptr) {
			this->numeComanda = new char[strlen(numeComanda) + 1];
			strcpy(this->numeComanda, numeComanda);
		}

	}

	void setAdresaLivrare(string adresaLivrare) {
		if ((adresaLivrare.length()) > 2) {
			this->adresaLivrare = adresaLivrare;
		}

	}
	void setIdVinuriComanda(int* idVinuriComanda) {
		this->idVinuriComanda = idVinuriComanda;

	}
	void setnrIdVinuriComanda(int nrIdVinuriComanda) {
		this->nrIdVinuriComanda = nrIdVinuriComanda;
	}
	//constructor Default
	Comanda():idComanda(nrComenzi++) {//atributul static intre paranteze
		//la id comanda vrem sa setam valoarea nrComenzi si apoi sa o incrementam
		//id-ul e diferit pt fiecare obiect
		this->adresaLivrare = "Nu este specificata adresa";
		this->greutateComanda = 0;
		this->idVinuriComanda = nullptr;
		this->numeComanda = nullptr;
		this->nrIdVinuriComanda = 0;
		//in constructorul default nu trebuie alocata memorie pt pointeri
		//nu facem delete[], nu facem strcpy()
	}

	//constructor cu un parametru
	Comanda(const char* numeComanda) :idComanda(nrComenzi) {
		Comanda::nrComenzi++;
		this->numeComanda = new char[strlen(numeComanda) + 1];
		strcpy(this->numeComanda, numeComanda);
		this->adresaLivrare = "Nu este specificata adresa. ";
			this->greutateComanda = 0.0;
			this->idVinuriComanda = nullptr;
			this->nrIdVinuriComanda = 0;

	}

	//constructor cu toti parametrii

	Comanda(const char* numeComanda, float greutateComanda, string adresaLivrare, int* idVinuriComanda):idComanda(nrComenzi++) {
		this->numeComanda = new char[strlen(numeComanda) + 1];
		strcpy(this->numeComanda, numeComanda);
		this->greutateComanda = greutateComanda;
		this->adresaLivrare = adresaLivrare;

	}

	void afisareComanda(){
		cout << "Adresa de livrare este:" << this->adresaLivrare<<endl;
		cout << "Greutatea comenzii este: " << this->greutateComanda<<endl;
		if (this->numeComanda != nullptr) {
		cout << "Numele comenzii: " << this->numeComanda<<endl;
		}
		for (int i = 0; i < nrIdVinuriComanda;i++) {
			cout << "prosusele comendate au urmatoarele id: " << idVinuriComanda[i] << endl;
		}
		cout << "Id-ul comenzii este: " << this->idComanda << endl;
		cout << "Aveti un numar de " << this->nrIdVinuriComanda << " produse comandate." << endl;
	}

	friend ostream& operator<<(ostream& consola, const Comanda& c) {
		consola << endl << "Id comanda: " << c.idComanda;
		consola << endl << "Nume comanda: "
			<< (c.numeComanda != nullptr ? c.numeComanda : "Nespecificat");
		consola << endl << "Greutate: " << c.greutateComanda;
		consola << endl << "Adresa livrare: " << c.adresaLivrare;
		consola << endl << "Nr. produse: " << c.nrIdVinuriComanda;

		if (c.idVinuriComanda != nullptr && c.nrIdVinuriComanda > 0) {
			consola << endl << "Id-uri vinuri: ";
			for (int i = 0; i < c.nrIdVinuriComanda - 1; i++) {
				consola << c.idVinuriComanda[i] << ", ";
			}
			consola << c.idVinuriComanda[c.nrIdVinuriComanda - 1] << ".";
		}
		else {
			consola << endl << "Id-uri vinuri nespecificate";
		}

		return consola;
	}


	// ++comanda (prefix)
	Comanda operator++() {         
		this->nrIdVinuriComanda++;
		return *this;
	}

	// comanda++ (postfix)
	Comanda operator++(int) {       
		Comanda copie = *this;
		this->nrIdVinuriComanda++;
		return copie;
	}

	// cast la int
	explicit operator int() const {
		return this->idComanda;
	}

	bool operator!() const {
		return this->nrIdVinuriComanda == 0;
	}

};

int Comanda::nrComenzi = 0;


//initializam atributele statice in afara claselor, global
const float Vin::taxaAlcool = 1.5; //nu a putut fi initializat in clasa Vin
int Vin::nrTotalEticheteVin = 0;
int Crama::nrTotalCrame = 0;


void main() {
	//Testare getters si setters
	Vin v_test;
	//cout << "Pret initial: " << v_test.getPretSticla() << endl;

	//v_test.setPretSticla(50.5); //se apeleaza setter-ul
	//v_test.setNumeSoi("Merlot");

	//cout << "Pret nou: " << v_test.getPretSticla() << endl;
	//cout << "Soi nou: " << v_test.getNumeSoi() << endl;

	//v_test.afisare();

	//testare constructor de copiere
	Vin v2 = v_test;
	//v2.afisare();


	//v_test.setNumeSoi("Pinot noir");
	//v_test.afisare();//originalul schimbat
	//v2.afisare(); //copia tb sa ramana Merlot


	Vin v1_default; //apel constructor default;
	//Vin* v1_pointer = &v1_default;
	//v1_pointer->afisare();
	//(*v1_pointer).afisare();

	v1_default = v2; // se apeleaza op =
	Vin v2_complet("Tamaioasa", "Vinuri de Macin", 2022, 45.5); //apel constructor complet

	v1_default.afisare();
	v2_complet.afisare();
	
	Crama c1_test;
	c1_test.afisare();
	Crama c1_1_parametru("Crama vita de vie"); //apel constructor 1 parametru
	c1_1_parametru.afisare();
	Crama c2("Crama Vinul Bun", "Dealu Mare", 12.5f, true);

	Crama c2_copie = c2;
	cout << "Am facut o copie pe care o vom afisa folosind constructorul de copiere." << endl;
	c2_copie.afisare();

	//modific originalul, copia trebuie sa ramana neschimbata
	c2.setNumeCrama("Crama lui Bogdan");
	c2.setSuprafata(20.0f);

	cout << "Am modifcat obiectul original pe care il vom afisa impreuna cu copia acestuia." << endl;
	c2.afisare();
	c2_copie.afisare();

	//Crama c3 = (c2 = c2_copie);
	//c3.afisare();

	cout << Crama::getNrTotalCrame();
	//cout << c1_test.getNrTtalCrame;
	

	Comanda comanda1;
	//comanda1.setGreutateComanda(3.76);
	//cout << comanda1.getGreutateComanda() << endl;
	//comanda1.setNumeComanda("Comanda 1");
	//cout << comanda1.getNumeComanda() << endl;
	//comanda1.setAdresaLivrare("Braila, str Cocorilor nr. 25");
	//cout<< comanda1.getAdresaLivrare() << endl;
	int* idVinuri = new int[3];
	idVinuri[0] = 11;
	idVinuri[1] = 7;
	idVinuri[2] = 23;
	comanda1.setIdVinuriComanda(idVinuri);
	cout << comanda1.getIdVinuriComanda()[2] << endl;
	Comanda comanda2; 
	comanda2.afisareComanda();
	Comanda comanda_3("Comanda se numeste asa.");
	comanda_3.afisareComanda();

	Comanda c;
	cout << "Id comanda: " << (int)c << endl;   // foloseste operator de cast int()

	if (!c) {
		cout << "Comanda este goala.\n";
	}

	Comanda cmd2 = c++;
	cout << "Nr produse: " << cmd2.getNrIdVinuriComanda() << endl;
	Comanda cmd3 = ++c;    // creste din nou nrIdVinuriComanda
	cout << "Nr produse: " << cmd3.getNrIdVinuriComanda() << endl;

	cout << comanda1;
};