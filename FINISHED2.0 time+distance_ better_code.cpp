#include "mbed.h"    

Serial pc(USBTX, USBRX); // tx, rx

DigitalOut RedLED(LED1);
DigitalOut GreenLED(LED2);
DigitalOut BlueLED(LED3);



int main() {
	// it seems when decalred, they are auto-turned on

	RedLED = 1;
	GreenLED = 1;
	BlueLED = 1;

	int Times[3];
	int Colours[3];


	while(1) { // it really didnt like while true

		pc.printf("Please enter the times for each colour\n");

		for (int index = 0; index < 3; ++index) {
			pc.scanf("%i", &Times[index]);
			pc.printf("Time to wait = %i \n", Times[index]);
		}

		////////////////////////////////////////////////////

		pc.printf("Please enter the colours (R,G,B only as inputs)\n");

		for (int index = 0; index < 3; ++index) {
			pc.scanf("%i", &Colours[index]);
			pc.printf("Colour Specified (1:R,2:G,3:B) = %i \n", Colours[index]);
		}


		for (int index = 0; index < 3; ++index) {
			//each = Colours[index]

			char each = Colours[index];

			if (each == 1) {
				RedLED = 0;
			}
			else if (each == 2) {
				GreenLED = 0;
			}
			else if (each == 3) {
				BlueLED = 0;
			}

			wait(Times[index]);
		}

		RedLED = 1;
		GreenLED = 1;
		BlueLED = 1;

	}
}

