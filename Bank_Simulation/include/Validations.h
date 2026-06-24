#ifndef VALIDATIONS_H
#define VALIDATIONS_H

#include <string>

int getValidChoice(int min, int max);
double getValidAmount();

std::string getValidUserName();
std::string getValidPassword();


bool isNumber(std::string& input);

#endif