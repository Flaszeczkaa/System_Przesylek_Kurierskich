# System Firmy Kurierskiej (C++)

Prosty system konsolowy do zarządzania przesyłkami i obliczania kosztów transportu, napisany w języku C++. Projekt demonstruje kluczowe założenia programowania obiektowego (OOP).

## 🚀 Funkcje
- Dodawanie różnych typów przesyłek:
  - List zwykły
  - List priorytetowy
  - Paczka standardowa
  - Paczka gabarytowa (z obliczaniem dopłaty na podstawie objętości)
- Walidacja danych wejściowych (zabezpieczenie przed wpisaniem tekstu zamiast liczb).
- Automatyczne obliczanie sumarycznego kosztu koszyka.
- Dynamiczne zarządzanie obiektami.

## 🛠️ Wykorzystane techniki OOP
- **Klasy i Dziedziczenie:** Struktura klas reprezentująca hierarchię przesyłek.
- **Polimorfizm:** Wykorzystanie metod wirtualnych (`ObliczKoszt()`, `WyswietlInfo()`) do obsługi różnych typów obiektów w jednej kolekcji `std::vector`.
- **Abstrakcja:** Klasa bazowa `cPrzesylka` jako klasa abstrakcyjna.
- **Hermetyzacja:** Użycie modyfikatorów dostępu `public`, `protected` i `private`.

## 🖥️ Jak uruchomić
1. Sklonuj repozytorium.
2. Otwórz projekt w środowisku Visual Studio lub skompiluj za pomocą terminala:
   ```bash
   g++ main.cpp przesylki.cpp -o SystemKurierski
   ./SystemKurierski
