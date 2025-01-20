// Plik: Randomiser.cpp
// Autor: Filip Dudzik
// Data: 11.01.2025
// Opis: Implementacja metod klasy Randomiser, która generuje losowe imiona i choroby.

#include "Randomiser.h"

#include <random>

std::string Randomiser::randomName(const bool isMen) {
    std::string menNames[] = {"Adam", "Bartosz", "Cezary", "Dawid", "Edward", "Filip", "Grzegorz", "Henryk", "Igor", "Jan"};
    std::string womenNames[] = {"Anna", "Barbara", "Celina", "Dorota", "Ewa", "Felicja", "Grazyna", "Halina", "Irena", "Jadwiga"};
    return isMen ? menNames[rand() % 10] : womenNames[rand() % 10];
}

std::string Randomiser::randomIllness() {
    std::string illnesses[] = {"Grypa", "Zlamanie", "Ospa", "Zapalenie płuc", "Zapalenie oskrzeli", "Zapalenie ucha", "Zapalenie zatok", "Zapalenie opon mózgowych", "Zapalenie otrzewnej", "Zapalenie wyrostka robaczkowego"};
    return illnesses[rand() % 10];
}