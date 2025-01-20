// Plik: Pharmacy.cpp
// Autor: Mateusz Lewosiński
// Data: 19.12.2024
// Opis: Implementacja metod klasy Pharmacy, zarządzającej lekami i ich kosztami.

#include "Pharmacy.h"

#include <iostream>

double Pharmacy::getMedicineCost(std::string medicine) {
    // Wyszukiwanie kosztu leku w mapie 'medicines'
    return medicines[medicine];
}

bool Pharmacy::hasMedicine(std::string medicine) {
    return medicines.contains(medicine);
}

void Pharmacy::addMedicine(std::string medicine, double cost) {
    // Przypisanie kosztu leku do mapy 'medicines'
    medicines[medicine] = cost;
}

void Pharmacy::removeMedicine(std::string medicine) {
    // Usuwanie leku z mapy 'medicines'
    medicines.erase(medicine);
}

void Pharmacy::printMedicines() {
    std::cout << "Dostepne leki: ";

    for (auto &medicine : medicines) {
        std::cout << " - " << medicine.first << " - " << medicine.second << std::endl;
    }
}
