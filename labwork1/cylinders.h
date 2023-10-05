#ifndef CYLINDERS_H_
#define CYLINDERS_H_

#include <iostream>
#include <conio.h>
#include <stdlib.h>

const std::string CSF = "CSF";
const std::string CSB = "CSB";
const std::string CSS = "CSS";

const std::string C1F = "C1F";
const std::string C1B = "C1B";
const std::string C1S = "C1S";

const std::string C2F = "C2F";
const std::string C2B = "C2B";
const std::string C2S = "C2S";

const std::string MC = "MC";
const std::string SC = "SC";

const std::string QUIT = "Q";

extern "C" {
	#include <interface.h>
}


// given a byte value, returns the value of its bit n
int getBitValue(uInt8 value, uInt8 bit_n);
// given a byte value, set the n bit to value
void setBitValue(uInt8* variable, int n_bit, int new_value_bit);


// CILINDRO START
void moveCylinderStartFront();
void moveCylinderStartBack();
void stopCylinderStart();
int getCylinderStartPosition();
void gotoCylinderStart(int pos);


// CILINDRO 1
void moveCylinder1Front();
void moveCylinder1Back();
void stopCylinder1();
int getCylinder1Position();
void gotoCylinder1(int pos);


// CILINDRO 2
void moveCylinder2Front();
void moveCylinder2Back();
void stopCylinder2();
int getCylinder2Position();


// CONVEYOR / ESTEIRA
void moveConveyor();
void stopConveyor();

#endif // !CYLINDERS_H_
