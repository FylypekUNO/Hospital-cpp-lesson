// Plik: Randomiser.h
// Autor: Filip Dudzik
// Data: 11.01.2025
// Opis: Plik nagłówkowy dla klasy Randomiser, która generuje losowe imiona i choroby.

#ifndef RANDOMISER_H
#define RANDOMISER_H
#include <string>


struct Randomiser {
    // Metoda zwracająca losowe męskie/damskie imię
    static std::string randomName(bool isMen);
    // Metoda zwracająca losowe schorzenie
    static std::string randomIllness();
};



#endif //RANDOMISER_H
