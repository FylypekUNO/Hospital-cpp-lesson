// Plik: main.cpp
// Autor: Filip Dudzik
// Data: 20.01.2025
// Opis: Główny plik programu, Caly interfejs użytkownika znajduje się w tym pliku.

#include <iostream>
#include <vector>

#include "PatientAccount.h"
#include "Pharmacy.h"
#include "Randomiser.h"
#include "Surgery.h"
#include "Utility.h"

// Struktura globalna do przechowywania leków i operacji
struct {
    Pharmacy pharmacy;
    Surgery surgery;
} global;

// 1. Przyjmij pacjenta

// 1.2. Podaj lek pacjentowi
void giveMedicine(PatientAccount& patient) {
    using namespace std;

    global.pharmacy.printMedicines();

    string name;
    do {
        name = inputLine("Podaj nazwe leku >", 1);
    } while (!global.pharmacy.hasMedicine(name));

    double cost = global.pharmacy.getMedicineCost(name);

    patient.addCost(cost);
    printf("Podano lek: %s o cenie: %.2f\n", name.c_str(), cost);
}

// 1.3. Poddaj pacjenta operacji
void giveSurgery(PatientAccount& patient) {
    using namespace std;

    global.surgery.printSurgeries();

    string name;
    do {
        name = inputLine("Podaj nazwe operacji >", 1);
    } while (!global.surgery.surgeries.contains(name));

    double cost = global.surgery.getSurgeryCost(name);

    patient.addCost(cost);
    printf("Poddano operacji: %s o cenie: %.2f\n", name.c_str(), cost);
}

void printPatientMenu() {
    printf("######### Menu pacjenta ################\n");
    printf("# 1. Nastepny dzien                    #\n");
    printf("# 2. Podaj lek pacjentowi              #\n");
    printf("# 3. Poddaj pacjenta operacji          #\n");
    printf("# 4. Podaj aktualny koszt              #\n");
    printf("# 5. Wypusc pacjenta i wymagaj zaplaty #\n");
    printf("########################################\n");
}

PatientAccount newPatient() {
    using namespace std;

    bool isMen = rand() % 2 == 0;
    string name = Randomiser::randomName(isMen);
    string illness = Randomiser::randomIllness();

    PatientAccount patient;
    patient.name = name;
    patient.illness = illness;
    patient.days = 0;
    patient.totalCost = 0;

    if (isMen) {
        printf("Nowy pacjent: %s\n", name.c_str());
        printf("Chory na: %s\n", illness.c_str());
    } else {
        printf("Nowa pacjentka: %s\n", name.c_str());
        printf("Chora na: %s\n", illness.c_str());
    }

    printPatientMenu();

    do {
        int choice = inputInt(">", 1, 5);

        switch (choice) {
            case 1:
                patient.nextDay();
                printf("Mija dzien %d\n", patient.days);
                break;
            case 2:
                giveMedicine(patient);
                break;
            case 3:
                giveSurgery(patient);
                break;
            case 4:
                printf("Aktualny koszt: %.2f\n", patient.totalCost);
                break;
            case 5:
                patient.discharge();
                return patient;
            default: continue;
        }

        printPatientMenu();
    } while (true);
}

// 3. Dodaj lek
void addMedicine() {
    using namespace std;

    string name;

    do {
        name = inputLine("Podaj nazwe leku >", 1);
    } while (global.pharmacy.medicines.contains(name));

    double cost = inputDouble("Podaj cene leku > ", 0.01, 1000.00);

    printf("Dodano lek: %s o cenie: %.2f\n", name.c_str(), cost);
    global.pharmacy.addMedicine(name, cost);
}

// 5. Dodaj operacje
void addSurgery() {
    using namespace std;

    string name;

    do {
        name = inputLine("Podaj nazwe operacji >", 1);
    } while (global.surgery.surgeries.contains(name));

    double cost = inputDouble("Podaj cene operacji > ", 0.01, 1000000.00);

    global.surgery.addSurgery(name, cost);
    printf("Dodano operacje: %s o cenie: %.2f\n", name.c_str(), cost);
}

void printMainMenu() {
    printf("######### Glowne menu ############\n");
    printf("# 1. Przyjmij pacjenta           #\n");
    printf("# 2. Wyswietl historie pacjentow #\n");
    printf("# 3. Dodaj lek                   #\n");
    printf("# 4. Wyswietl liste lekow        #\n");
    printf("# 5. Dodaj operacje              #\n");
    printf("# 6. Wyswietl liste operacji     #\n");
    printf("# 7. Wyjscie                     #\n");
    printf("##################################\n");
}

// Główna pętla programu
void mainLoop() {
    using namespace std;

    vector<PatientAccount> patients;

    printMainMenu();

    do {
        int choice = inputInt(">", 1, 7);

        switch (choice) {
            case 1:
                patients.push_back(newPatient());
                break;
            case 2:
                printf("Historia pacjentow:\n");
                for (auto& patient : patients) {
                    patient.discharge();
                }
                break;
            case 3:
                addMedicine();
                break;
            case 4:
                printf("Lista lekow:\n");
                global.pharmacy.printMedicines();
                break;
            case 5:
                addSurgery();
                break;
            case 6:
                printf("Lista operacji:\n");
                global.surgery.printSurgeries();
                break;
            case 7: return;
            default: continue;
        }

        printMainMenu();
    } while (true);
}

int main() {
    global.pharmacy.addMedicine("Apap", 19.99);
    global.pharmacy.addMedicine("Ibuprom", 17.99);
    global.pharmacy.addMedicine("Rutinoscorbin", 12.99);
    global.pharmacy.addMedicine("Voltaren", 15.99);
    global.pharmacy.addMedicine("Witamina A", 10.99);

    global.surgery.addSurgery("Wyciecie wyrostka", 1000.00);
    global.surgery.addSurgery("Wyciecie kawalka watroby", 1500.00);
    global.surgery.addSurgery("Transplant serca", 1000000.00);
    global.surgery.addSurgery("Wymiana mozgu", 500000.00);
    global.surgery.addSurgery("Amputacja nogi", 500.00);

    mainLoop();

    return 0;
}