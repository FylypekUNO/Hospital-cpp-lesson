// Plik: Surgery.h
// Autor: Bartosz Gnaciński
// Data: 20.12.2024
// Opis: Nagłówek klasy Surgery, która zarządza kosztami różnych zabiegów chirurgicznych.

#ifndef SURGERY_H
#define SURGERY_H
#include <string>
#include <unordered_map>

// Klasa Surgery przechowuje dane o kosztach zabiegów chirurgicznych i pozwala na dodawanie, usuwanie oraz pobieranie kosztów tych zabiegów.
class Surgery {
public:
    // Mapowanie nazwy zabiegu na jego koszt
    std::unordered_map<std::string, double> surgeries;

    // Funkcja pobierająca koszt zabiegu o podanej nazwie, zwraca koszt zabiegu, jeśli istnieje, w przeciwnym razie wartość domyślną.
    double getSurgeryCost(std::string surgery);

    bool hasSurgery(std::string surgery);

    // Funkcja dodająca nowy zabieg do mapy z kosztami, dodaje parę {nazwa zabiegu, koszt}.
    void addSurgery(std::string surgery, double cost);

    // Funkcja usuwająca zabieg o podanej nazwie z mapy kosztów
    void removeSurgery(std::string surgery);

    // Funkcja wypisująca wszystkie zabiegi i ich koszty
    void printSurgeries();
};

#endif //SURGERY_H
