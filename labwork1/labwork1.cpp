#include <iostream>
#include <conio.h>
#include <stdlib.h>
#include <windows.h> // for the Sleep function

#include "util.h"
#include "messages.h"
#include "cylinders.h"

/*
*	Estamos a contar bits de 0 - 7
	Sensores:
		p0:
			cilindro start: bit 6 (back)
			cilindro start: bit 5 (front)

			cilindro 1: bit 4 (back) [active low]
			cilindro 1: bit 3 (front) [active low]

			cilindro 2: bit 2 (back) [active low]
			cilindro 2: bit 1 (front) [active low]

			bloco no cilindro 1: bit 0
		p1:
			Doca 1: bit 4
			Doca 2: bit 3
			Doca end: bit 2

			bloco 2: bit 6
			bloco 3: bit 5
	Atuador:
		p2:
			cilindro start: bit 0 (back)
			cilindro start: bit 1 (front)

			cilindro 1: bit 3 (back)
			cilindro 1: bit 4 (front)

			cilindro 2: bit 5 (back)
			cilindro 2: bit 6 (front)

			LED: bit 7

			esteira: bit 2
*/

extern "C" {
	#include <interface.h>
}


int main(int argc, char** argv) {
	createDigitalInput(0);
	createDigitalInput(1);
	createDigitalOutput(2);
	uInt8 p0 = 0;
	uInt8 p1 = 0;
	uInt8 p2 = 0;


	//writeDigitalU8(2, 0x2); // start moving cylinder start front

	//writeDigitalU8(2, 0x4);

	//moveCylinder1Front();
	//moveCylinder2Front();

	moveConveyor();

	while (!_kbhit()) { //do until a key is pressed
		std::string option;
		p0 = readDigitalU8(0);
		p1 = readDigitalU8(1);
		p2 = readDigitalU8(2);

		if (getBitValue(p0, 0) == 1) {
			stopConveyor();
			moveCylinder1Front();
		}
		
		option = mainMenu();
		newLine();
		option = "idk";

		for (int i = 0; i < option.length(); i++) {
			option[i] = toupper(option[i]);
		}
		
		if (option == QUIT) {
			showMessageSuccess(EXIT_MSG);
			exit(EXIT_SUCCESS);
		}
		else if (option == CSF) {
			std::cout << "Comecei a mover para frente\n";
			moveCylinderStartFront();
			while (true) {
				if (getCylinderStartPosition() == 1) { //chegou no sensor de frente
					stopCylinderStart();
					break;
				}
			}
		}
		else if (option == CSB) {
			std::cout << "Comecei a mover para tras\n";
			moveCylinderStartBack();
			while (true) {
				if (getCylinderStartPosition() == 0) { //chegou no sensor de trás
					stopCylinderStart();
					break;
				}
			}
		}
		else if (option == C1F) {
			moveCylinder1Front();
			while (true) {
				if (getCylinder1Position() == 1) {
					stopCylinder1();
					break;
				}
			}
		}
		else if (option == C1B) {
			moveCylinder1Back();
			while (true) {
				if (getCylinder1Position() == 0) {
					stopCylinder1();
					break;
				}
			}
		}
		else if (option == C2F) {
			moveCylinder2Front();
			while (true) {
				if (getCylinder2Position() == 1) {
					stopCylinder2();
					break;
				}
			}
		}
		else if (option == C2B) {
			moveCylinder2Back();
			while (true) {
				if (getCylinder2Position() == 0) {
					stopCylinder2();
					break;
				}
			}
		}
		else if (option == MC) {
			moveConveyor();
		}
		else if (option == SC) {
			stopConveyor();
		}
		else {
			showMessageError("\nInvalid Option\n\n");
		}
	}
	writeDigitalU8(2, 0);
	Sleep(5000);
	closeChannels();
}