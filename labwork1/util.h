#ifndef UTIL_H_
#define UTIL_H_

#include <iostream>

#define RED_COLOR "\033[1;31m"
#define GREEN_COLOR "\033[1;32m"
#define YELLOW_COLOR "\033[1;33m"
#define BLUE_COLOR "\033[1;34m"
#define RESET_COLOR "\033[0m"

enum MAIN_OPTIONS {
	EXIT,
	ADD_CONTACT,
	VIEW_ALL_CONTACTS,
	SEARCH_CONTACT,
	TOTAL_CONTACTS
};


enum YES_NO_OPTIONS {
	YES = 1,
	NO
};

void newLine();
std::string readString();
int readInteger(std::string msg);
void greenColor();
void redColor();
void yellowColor();
void blueColor();
void resetColor();

void showMessageSuccess(std::string msg);
void showMessageError(std::string msg);
bool isInRange(int num, int min, int max);

std::string getOptionString();
std::string mainMenu();

#endif