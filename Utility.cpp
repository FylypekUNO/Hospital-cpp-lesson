// Plik: Utility.cpp
// Autor: Filip Dudzik
// Data: 17.01.2025
// Opis: Implementacja funkcji pomocniczych, które ułatwiają wprowadzanie danych przez użytkownika.

#include "Utility.h"

#include <iostream>
#include <limits>

int inputInt(const std::string& text, const int min, const int max) {
    int input;

    do {
        std::cout << text;
        std::cin >> input;
        std::cin.clear();
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
    } while (input < min || input > max);

    return input;
}

double inputDouble(const std::string& text, const double min, const double max) {
    double input;

    do {
        std::cout << text;
        std::cin >> input;
        std::cin.clear();
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
    } while (input < min || input > max);

    return input;
}

std::string inputString(const std::string& text, const int minLength) {
    std::string input;

    do {
        std::cout << text;
        std::cin >> input;
    } while (input.length() < minLength);

    return input;
}

std::string inputLine(const std::string& text, const int minLength) {
    std::string input;

    do {
        std::cout << text;
        std::cin.clear();
        std::getline(std::cin, input);
    } while (input.length() < minLength);

    return input;
}