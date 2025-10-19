// ConsoleApplication1.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

//scrieti un program care permite returnarea produselor dintr-o anumita categorie dintr-un supermarket 
//dintr-o anumita tara care au un pret > 50;
#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
using namespace std;

class Supermarket {
    char* nume; //fields ale clasei
    char* tara;


};

enum CategoriiProduse {
    LACTATE = 1, CARNE = 2, FRUCTE = 3, OUA = 4
};
class Produs {
public: 
    CategoriiProduse categoriiProduse; //am definit un field de tipul categorii produse
    char* nume; 
    float pret;

};



void main()
{
 //declaram o variabila de tip produs pt a stoca info despre produs
    Produs ou;
    //am alocat memorie pentru numele produsului
    ou.nume = new char[strlen("ou") + 1];
    strcpy(ou.nume, "ou"); // am setat field-ul nume din obj ou
    ou.pret = 2;
    ou.categoriiProduse = OUA; //am setat categoria produsului

    Produs cascaval;
    //am alocat memorie pentru numele produsului
    cascaval.nume = new char[strlen("cascaval de vaca") + 1];
    strcpy(cascaval.nume, "cascaval de vaca"); // am setat field-ul nume din obj cascaval
    cascaval.pret = 10;
    cascaval.categoriiProduse = LACTATE; //am setat categoria produsului

    Produs mere;
    //am alocat memorie pentru numele produsului
    mere.nume = new char[strlen("mere") + 1];
    mere.categoriiProduse = FRUCTE; //am setat categoria produsului
    strcpy(mere.nume, "mere"); // am setat field-ul nume din obj cascaval
    mere.pret = 4;

    cout << ou.categoriiProduse << " = categoria produsului" <<"\n"; 
}

