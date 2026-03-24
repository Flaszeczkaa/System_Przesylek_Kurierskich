#pragma once
#include <iostream>
#include <string>

using namespace std;

class cPrzesylka
{
    double waga;

public:
    cPrzesylka(double w);

    virtual ~cPrzesylka() {}

    virtual double ObliczKoszt() = 0;
    virtual void WyswietlInfo() = 0;

protected:
    double pobierzWage();
};

class cList : public cPrzesylka
{
public:
    cList(double waga);
    double ObliczKoszt() override;
    void WyswietlInfo() override;
};

class cPaczka : public cPrzesylka
{
public:
    cPaczka(double waga);
    double ObliczKoszt() override;
    void WyswietlInfo() override;
};

class cListPriorytetowy : public cList
{
public:
    cListPriorytetowy(double waga);
    double ObliczKoszt() override;
    void WyswietlInfo() override;
};

class cPaczkaGabarytowa : public cPaczka
{
    double doplata;

public:
    cPaczkaGabarytowa(double waga, double h, double s, double d);
    double ObliczKoszt() override;
    void WyswietlInfo() override;
};