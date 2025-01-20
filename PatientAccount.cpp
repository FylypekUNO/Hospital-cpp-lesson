// Plik: PatientAccount.cpp
// Autor: Wiktoria Adamczyk
// Data: 01.01.2025
// Opis: Definicja metod

#include "PatientAccount.h"

#include <iostream>

double PatientAccount::dailyCharge = 100;

void PatientAccount::addCost(double cost) {
    totalCost += cost;
}

void PatientAccount::nextDay() {
    days++;
    totalCost += dailyCharge;
}

void PatientAccount::discharge() {
    std::cout << name << " - " << illness << " | Calkowity koszt za " << days << " dni: " << totalCost << std::endl;
}
