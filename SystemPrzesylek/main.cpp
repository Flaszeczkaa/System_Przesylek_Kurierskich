#include <iostream>
#include <vector>
#include <limits>
#include "przesylki.h" 
#include <iomanip>

using namespace std;

// Funkcja pomocnicza do sprawdzania czy wpisano liczbe
double WczytajLiczbe()
{
    double liczba;
    while (!(cin >> liczba))
    {
        cout << ">>> BLAD: Podano tekst zamiast liczby! Sprobuj ponownie: ";
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
    }
    return liczba;
}

int main()
{
    vector<cPrzesylka*> mojePrzesylki;
    int wybor = 0;

    cout << "--- SYSTEM FIRMY KURIERSKIEJ ---" << endl;

    while (wybor != 5)
    {
        cout << "\n1. Dodaj Zwykly List (max 2 kg)" << endl;
        cout << "2. Dodaj List Priorytetowy (max 2 kg)" << endl;
        cout << "3. Dodaj Paczke Standardowa (max 30 kg)" << endl;
        cout << "4. Dodaj Paczke Gabarytowa (max 100 kg)" << endl;
        cout << "5. Wylicz koszty i zakoncz" << endl;
        cout << "Wybierz opcje: ";

        wybor = (int)WczytajLiczbe();

        if (wybor >= 1 && wybor <= 4)
        {
            double podanaWaga;
            bool wagaPoprawna = false;

            // Sprawdzanie poprawnosci wagi
            do
            {
                cout << "Podaj wage przesylki (kg): ";
                podanaWaga = WczytajLiczbe();

                if (podanaWaga <= 0)
                {
                    cout << ">>> BLAD: Waga musi byc wieksza od zera!" << endl;
                }
                else if ((wybor == 1 || wybor == 2) && podanaWaga > 2.0)
                {
                    cout << ">>> BLAD: List to max 2 kg!" << endl;
                }
                else if (wybor == 3 && podanaWaga > 30.0)
                {
                    cout << ">>> BLAD: Paczka to max 30 kg." << endl;
                }
                else if (wybor == 4 && podanaWaga > 100.0)
                {
                    cout << ">>> BLAD: Max 100 kg!" << endl;
                }
                else
                {
                    wagaPoprawna = true;
                }
            } while (wagaPoprawna == false);

            // Tworzenie obiektow dynamicznie
            if (wybor == 1)
            {
                mojePrzesylki.push_back(new cList(podanaWaga));
            }
            else if (wybor == 2)
            {
                mojePrzesylki.push_back(new cListPriorytetowy(podanaWaga));
            }
            else if (wybor == 3)
            {
                mojePrzesylki.push_back(new cPaczka(podanaWaga));
            }
            else if (wybor == 4)
            {
                double x, y, z;
                cout << "Szerokosc (cm): "; x = WczytajLiczbe();
                cout << "Dlugosc (cm):   "; y = WczytajLiczbe();
                cout << "Wysokosc (cm):  "; z = WczytajLiczbe();
                mojePrzesylki.push_back(new cPaczkaGabarytowa(podanaWaga, x, y, z));
            }
            cout << "=> Dodano do koszyka!" << endl;
        }
    }

    cout << "\n--- PODSUMOWANIE TWOICH PRZESYLEK ---" << endl;
    double sumaCalkowita = 0;

    for (int i = 0; i < mojePrzesylki.size(); i++)
    {
        mojePrzesylki[i]->WyswietlInfo();
        sumaCalkowita = sumaCalkowita + mojePrzesylki[i]->ObliczKoszt();
    }

    cout << "-------------------------------------" << endl;
    cout << "Laczny koszt do zaplaty: " << fixed << setprecision(2) << sumaCalkowita << " PLN" << endl;

    // Sprzatanie pamieci 
    for (int i = 0; i < mojePrzesylki.size(); i++)
    {
        delete mojePrzesylki[i];
    }
    mojePrzesylki.clear();

    cout << "\nNacisnij dowolny klawisz, aby wyjsc...";
    cin.get(); 

    return 0;
}