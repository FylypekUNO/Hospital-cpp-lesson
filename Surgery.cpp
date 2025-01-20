// Plik: Surgery.cpp
// Autor: Bartosz Gnaciński
// Data: 20.12.2024
// Opis: Implementacja metod klasy Surgery, która przechowuje dane o kosztach różnych operacji.

#include "Surgery.h"
#include <iostream>

// Funkcja zwraca koszt operacji na podstawie jej nazwy, jeśli operacja jest w zapisanej liście, zwróci jej koszt, jeśli jej nie ma, zwróci 0.0
double Surgery::getSurgeryCost(std::string surgery) {
    return surgeries[surgery];
}

bool Surgery::hasSurgery(std::string surgery) {
    return surgeries.contains(surgery);
}

// Funkcja dodaje nową operację i jej koszt do listy, jeśli operacja już jest, zaktualizuje jej koszt
void Surgery::addSurgery(std::string surgery, double cost) {
    surgeries[surgery] = cost;
}

// Funkcja usuwa operację z listy na podstawie jej nazwy
void Surgery::removeSurgery(std::string surgery) {
    surgeries.erase(surgery);
}

// Funkcja wypisuje wszystkie operacje oraz ich koszty, dla każdej operacji w zapisanej liście pokazuje jej nazwę i koszt
void Surgery::printSurgeries() {
    std::cout << "Dostepne operacje: ";

    // Dla każdej operacji w zapisanej liście wypisuje jej nazwę i koszt
    for (auto &surgery : surgeries) {
        std::cout << " - " << surgery.first << " - " << surgery.second << std::endl;
    }
}
