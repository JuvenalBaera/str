#include "util.h"


#include <iostream>
#include <string.h>
#include <string>

#include "util.h"
#include "messages.h"

void newLine() { std::cout << "\n"; }

std::string readString() {
    std::string str;
    std::getline(std::cin >> std::ws, str);
    return str;
}

int readInteger(std::string msg) {
    int num;
    char* read = (char*)malloc(sizeof(char) * 30);
    bool yesNo = false;
    do {
        std::cout << msg;
        fgets(read, 30, stdin);
        read[strlen(read) - 1] = '\0';
        for (int i = 0; i < strlen(read); i++) {
            if (read[i] < '0' || read[i] > '9') {
                redColor();
                std::cout << NUMBER_ALLOW;
                read[0] = '\0';
                resetColor();
                yesNo = true;
                break;
            }
        }
    } while (yesNo == true);
    num = atoi(read);
    free(read);
    return num;
}
void greenColor() { std::cout << GREEN_COLOR; }
void redColor() { std::cout << RED_COLOR; }
void yellowColor() { std::cout << YELLOW_COLOR; }
void blueColor() { std::cout << BLUE_COLOR; }
void resetColor() { std::cout << RESET_COLOR; }

void showMessageSuccess(std::string msg) {
    yellowColor();
    std::cout << msg;
    resetColor();
}
void showMessageError(std::string msg) {
    redColor();
    std::cout << msg;
    resetColor();
}

bool isInRange(int num, int min, int max) {
    return num >= min && num <= max ? true : false;
}


std::string getOptionString() {
	std::string option;

	std::cout << "\nChoose an option: ";
	std::cin >> option;
	return option;
}


std::string mainMenu() {
	std::cout << "CSF\t-\tMove cylinder start front\n";
	std::cout << "CSB\t-\tMove cylinder start back\n";
	std::cout << "CSS\t-\tStop cylinder start\n\n";

	std::cout << "C1F\t-\tMove cylinder 1 front\n";
	std::cout << "C1B\t-\tMove cylinder 1 back\n";
	std::cout << "C1S\t-\tStop cylinder 1\n\n";

	std::cout << "C2F\t-\tMove cylinder 2 front\n";
	std::cout << "C2B\t-\tMove cylinder 2 back\n";
	std::cout << "C2S\t-\tStop cylinder 2\n\n";

    std::cout << "MC\t-\tMove Conveyor\n";
    std::cout << "SC\t-\tStop Conveyor\n\n";

    std::cout << "B2\t-\tBrick 2\n";
    std::cout << "B3\t-\tBrick 3\n\n";

    std::cout << "q\t-\tQuit\n";

    return getOptionString();
}
