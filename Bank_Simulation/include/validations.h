#ifndef VALIDATIONS_H
#define VALIDATIONS_H
#include <iostream>
int validChoice(int min, int max);
int validAccountNumber();
double validAmount();
bool isNumber(std::string& input);


bool isLeapYear(int year);
bool isValidDateFormat(const std::string& input);
bool isValidDateValue(int d, int m, int y);
std::string validDate();

#endif