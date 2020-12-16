#include <stdio.h>
#include <wiringPi.h>
#include <iostream>

using namespace std;
#define BeepPin 17
#define LED   18
#define BTN  27
int main(void)
{
	wiringPiSetupGpio();

	pinMode(BeepPin, OUTPUT);
	pinMode(LED, OUTPUT);
	pinMode(BTN, INPUT);
	
	bool button_state = false;
	bool last_state = false;

	while (1) {
		button_state = digitalRead(BTN);
		if (button_state != last_state)
		{
	        delay(20);
			if (button_state == HIGH)
			{
				digitalWrite(BeepPin, HIGH);
				digitalWrite(LED, HIGH);
			}
			else{
				digitalWrite(BeepPin, LOW);
				digitalWrite(LED, LOW);
			}
		}
		last_state = button_state;
	}
	return 0;
}

