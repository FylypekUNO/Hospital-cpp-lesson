// Plik: Pharmacy.h
// Autor: Mateusz Lewosiński
// Data: 19.12.2024
// Opis: Plik nagłówkowy dla klasy Pharmacy, która przechowuje informacje o lekach i ich kosztach.

#ifndef PHARMACY_H
#define PHARMACY_H
#include <string>
#include <unordered_map>

// Klasa Pharmacy przechowuje informacje o lekach i ich kosztach.
class Pharmacy {
public:
    std::unordered_map<std::string, double> medicines;

    // Funkcja zwraca koszt leku na podstawie jego nazwy.
    double getMedicineCost(std::string medicine);

    bool hasMedicine(std::string medicine);

    // Funkcja dodaje nowy lek do apteki z określoną ceną.
    void addMedicine(std::string medicine, double cost);

    // Funkcja usuwa lek z apteki na podstawie jego nazwy.
    void removeMedicine(std::string medicine);

    // Funkcja wypisuje wszystkie dostępne leki w aptece oraz ich ceny.
    void printMedicines();
};



#endif //PHARMACY_H
