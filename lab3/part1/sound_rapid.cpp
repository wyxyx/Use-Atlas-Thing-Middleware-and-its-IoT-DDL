#include <stdio.h>
#include <wiringPi.h>
#include <iostream>

using namespace std;

#define Pin 22
int main()
{
	wiringPiSetupGpio();
	pinMode(Pin,INPUT);
	std::cout<<digitalRead(Pin)<<"\n";
	int i = 0;
	int m = 0;
	while (1) {
		if (digitalRead(Pin) == HIGH)
		{	
			//std::cout<<"voice\n";
			m++;
		}
		//else
			//std::cout << "no voice\n";
		if(i==5)
		{	
			i = 0;
			if(m > 2)
			{
				std::cout<<"Produce rapid voice.\n";
				m = 0;
			}
		}
		delay(200);
		i++;
	}
	return 0;
}

