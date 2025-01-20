// Plik: Utility.h
// Autor: Filip Dudzik
// Data: 11.01.2025
// Opis: Plik nagłówkowy dla funkcji pomocniczych, które ułatwiają wprowadzanie danych przez użytkownika.

#ifndef UTILITY_H
#define UTILITY_H
#include <string>


int inputInt(const std::string& text, int min, int max);

double inputDouble(const std::string& text, double min, double max);

std::string inputString(const std::string& text, int minLength);

std::string inputLine(const std::string& text, int minLength);



#endif //UTILITY_H
