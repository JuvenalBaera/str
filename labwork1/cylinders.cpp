#include "cylinders.h"



// given a byte value, returns the value of its bit n
int getBitValue(uInt8 value, uInt8 bit_n) {
	return(value & (1 << bit_n));
}

// given a byte value, set the n bit to value
void setBitValue(uInt8* variable, int n_bit, int new_value_bit) {
	uInt8 mask_on = (uInt8)(1 << n_bit);
	uInt8 mask_off = ~mask_on;
	if (new_value_bit) *variable |= mask_on;
	else *variable &= mask_off;
}


// CILINDRO START
void moveCylinderStartFront() {
	uInt8 p = readDigitalU8(2); // read port 2
	setBitValue(&p, 0, 0); // set bit 0 to low level 0000 0000
	setBitValue(&p, 1, 1); // set bit 1 to high level 0000 0010
	writeDigitalU8(2, p); // update port 2
}

void moveCylinderStartBack() {
	uInt8 p = readDigitalU8(2); // read port 2
	setBitValue(&p, 1, 0); // set bit 1 to low level 0000 0000
	setBitValue(&p, 0, 1); // set bit 0 to high level 0000 0001
	writeDigitalU8(2, p); // update port 2
}

void stopCylinderStart() {
	uInt8 p = readDigitalU8(2); // read port 2
	setBitValue(&p, 0, 0); // set bit 0 to low level 
	setBitValue(&p, 1, 0); // set bit 1 to low level
	writeDigitalU8(2, p); // update port 2
}

int getCylinderStartPosition() {
	uInt8 p0 = readDigitalU8(0);
	if (getBitValue(p0, 6))// 0100 0000 
		return 0;
	if (getBitValue(p0, 5))// 0010 0000
		return 1;
	return(-1);
}


// TODO
void gotoCylinderStart(int pos) {
	moveCylinderStartFront();
	while (true) {
		if (pos == 0 || pos == 1) {
			stopCylinderStart();
			break;
		}
	}
}


// CILINDRO 1
void moveCylinder1Front() {
	uInt8 p = readDigitalU8(2); // read port 2
	setBitValue(&p, 3, 0); // set bit 3 to low level
	setBitValue(&p, 4, 1); // set bit 4 to high level
	writeDigitalU8(2, p); // update port 2
}

void moveCylinder1Back() {
	uInt8 p = readDigitalU8(2); // read port 2
	setBitValue(&p, 4, 0); // set bit 4 to low level [active low]
	setBitValue(&p, 3, 1); // set bit 3 to high level
	writeDigitalU8(2, p); // update port 2
}

void stopCylinder1() {
	uInt8 p = readDigitalU8(2); // read port 2
	setBitValue(&p, 3, 0); // set bit 3 to low level
	setBitValue(&p, 4, 0); // set bit 4 to low level
	writeDigitalU8(2, p); // update port 2
}

int getCylinder1Position() {
	uInt8 p0 = readDigitalU8(0);
	if (!getBitValue(p0, 4))
		return 0;
	if (!getBitValue(p0, 3))
		return 1;
	return(-1);
}

void gotoCylinder1(int pos) {
	moveCylinder1Front();
	while (true) {
		if (getCylinder1Position() == pos) {
			stopCylinder1();
			break;
		}
		if (getCylinder1Position() == 1)
			moveCylinder1Back();
	}
}

// CILINDRO 2
void moveCylinder2Front() {
	uInt8 p = readDigitalU8(2); // read port 2
	setBitValue(&p, 5, 0); // set bit 3 to low level
	setBitValue(&p, 6, 1); // set bit 4 to high level
	writeDigitalU8(2, p); // update port 2
}

void moveCylinder2Back() {
	uInt8 p = readDigitalU8(2); // read port 2
	setBitValue(&p, 6, 0); // set bit 4 to low level
	setBitValue(&p, 5, 1); // set bit 3 to high level
	writeDigitalU8(2, p); // update port 2
}

void stopCylinder2() {
	uInt8 p = readDigitalU8(2); // read port 2
	setBitValue(&p, 5, 0); // set bit 3 to low level
	setBitValue(&p, 6, 0); // set bit 4 to low level
	writeDigitalU8(2, p); // update port 2
}

int getCylinder2Position() {
	uInt8 p0 = readDigitalU8(0);
	if (!getBitValue(p0, 2))
		return 0;
	if (!getBitValue(p0, 1))
		return 1;
	return(-1);
}

// CONVEYOR / ESTEIRA
void moveConveyor() {
	uInt8 p = readDigitalU8(2);
	setBitValue(&p, 2, 1);
	writeDigitalU8(2, p);
}

void stopConveyor() {
	uInt8 p = readDigitalU8(2);
	setBitValue(&p, 2, 0);
	writeDigitalU8(2, p);
}