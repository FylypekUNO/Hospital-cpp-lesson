// Plik: PatientAccount.h
// Autor: Wiktoria Adamczyk
// Data: 01.01.2025
// Opis: Pola i metody klasy PatientAccount

#ifndef PATIENTACCOUNT_H
#define PATIENTACCOUNT_H

#include <string>

using namespace std;


// Klasa PatientAccount przechowuje całkowity koszt leczenia oraz liczbę dni pobytu pacjenta w szpitalu.
class PatientAccount {
public:
    double totalCost;
    int days;
    string name;
    string illness;

    static double dailyCharge;

    // Aktualizuje całkowity koszt leczenia
    void addCost(double cost);

    // Dodaje dzień pobytu i zwiększa całkowity koszt leczenia o dailyCharge
    void nextDay();

    // Wypisuje całkowity koszt pacjenta i dni pobytu
    void discharge();
};



#endif //PATIENTACCOUNT_H
