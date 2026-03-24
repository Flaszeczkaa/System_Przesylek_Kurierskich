#include <iostream>
#include "przesylki.h"
#include <iomanip>

using namespace std;


cPrzesylka::cPrzesylka(double w){
    waga = w;
}

double cPrzesylka::pobierzWage(){
    return waga;
}


cList::cList(double waga) : cPrzesylka(waga) {}

double cList::ObliczKoszt(){
    return 5.0 + (pobierzWage() * 0.5);
}

void cList::WyswietlInfo(){
    cout << "[Zwykly List] Waga: " << pobierzWage() << " kg | Cena: " << ObliczKoszt() << " PLN" << endl;
}


cPaczka::cPaczka(double waga) : cPrzesylka(waga) {}

double cPaczka::ObliczKoszt(){
    return 10.0 + (pobierzWage() * 0.5);
}

void cPaczka::WyswietlInfo(){
    cout << "[Paczka Standardowa] Waga: " << pobierzWage() << " kg | Cena: " << ObliczKoszt() << " PLN" << endl;
}

cListPriorytetowy::cListPriorytetowy(double waga) : cList(waga){}

double cListPriorytetowy::ObliczKoszt(){
    return cList::ObliczKoszt() + 6.0;
}

void cListPriorytetowy::WyswietlInfo(){
    cout << "[List Priorytetowy] Waga: " << pobierzWage() << " kg | Cena: " << ObliczKoszt() << " PLN" << endl;
}


cPaczkaGabarytowa::cPaczkaGabarytowa(double waga, double wysokosc, double szerokosc, double dlugosc) : cPaczka(waga){
    double objetosc = wysokosc * szerokosc * dlugosc;
    doplata = (objetosc / 1000.0) * 0.01;
}

double cPaczkaGabarytowa::ObliczKoszt(){
    return cPaczka::ObliczKoszt() + doplata;
}

void cPaczkaGabarytowa::WyswietlInfo(){
    cout << "[Gabaryt] Waga: " << pobierzWage() << " kg | Cena: " << fixed << setprecision(2) << ObliczKoszt() << " PLN" << endl;
}