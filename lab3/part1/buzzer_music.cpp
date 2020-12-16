#include <stdio.h>
#include <wiringPi.h>
#include <iostream>

using namespace std;
//reference website:https://www.freva.com/2019/06/05/buzzer-on-raspberry-pi-playing-a-melody/
#define BeepPin 17
//#define BTNPin 22
void beep(unsigned int note, unsigned int duration)
{
	//This is the semiperiod of each note.
	long beepDelay = (long)(1000000 / note);
	//This is how much time we need to spend on the note.
	long time = (long)((duration * 1000) / (beepDelay * 2));
	for (int i = 0; i < time; i++)
	{
		//1st semiperiod
		digitalWrite(BeepPin, HIGH);
		delayMicroseconds(beepDelay);
		//2nd semiperiod
		digitalWrite(BeepPin, LOW);
		delayMicroseconds(beepDelay);
	}
	//Add a little delay to separate the single notes
	digitalWrite(BeepPin, LOW);
	delay(20);
}
void play()
{
	
	int notes[] = { 262,294,330,262,262,294,330,262,330,349,392,330,349,392,392,440,392,349,330,262,392,440,392,349,330,262,262,196,262,262,196,262};
	float duration[] = { 0.5,0.5,0.5,0.5,0.5,0.5,0.5,0.5,0.5,0.5,1,0.5,0.5,1,0.25,0.25,0.25,0.25,0.5,0.5,0.25,0.25,0.25,0.25,0.5,0.5,0.5,0.5,1,0.5,0.5,1 };
	for (int i = 0; i < sizeof(notes)/sizeof(int); i++)
	{
		beep(notes[i],duration[i]*1000);
	}
}
int main(void)
{
	wiringPiSetupGpio();

	pinMode(BeepPin, OUTPUT);
	//pinMode(BTNPin, INPUT);
	play();
	return 0;
}

