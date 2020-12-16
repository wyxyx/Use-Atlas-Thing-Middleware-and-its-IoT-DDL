#include <stdio.h>
#include <wiringPi.h>
#include <iostream>

using namespace std;

#define Pin 22
int main()
{
	wiringPiSetupGpio();
	pinMode(Pin,INPUT);
	while (1) {
		if (digitalRead(Pin) == HIGH)
		{	
			std::cout<<"Make a sound.\n";
			
		}
		else
			std::cout << "no sound\n";
		delay(200);
	}
	return 0;
}

