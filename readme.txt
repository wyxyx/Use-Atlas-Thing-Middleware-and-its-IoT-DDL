In part 1, there are four cpp files which represent four different services respectively.
I use two sensors/actuator (a buzzer module and a small sound module) in addition to a button and a LED.
The buzzer module provides two services, one of which is making buzzer play a song, the other is pressing a button to make buzzer buzzering intermittently and at the same time the led will light.
The sound moudule provides two services, one of which is detecting the sound, the other is detecting the rapid sound, and I define the rapid sound is making more than 2 sound per second. 
Some information will be printed when running the program.
And I realize these four services in four c++ files seperately.
We can use command like: g++ -o main main.cpp -lwiringPi to execute these programs.
And the "buzzer_music.cpp" refers to website:https://www.freva.com/2019/06/05/buzzer-on-raspberry-pi-playing-a-melody/

In part 2, there are two files. The "Atlas_IoTDDL.xml" file using the builder tool to generate four services.
The "client.cpp" file is the code for the demo IoT Application I have developed to use the services.
We can use command: g++ -o client client.cpp to execute the program and connect to the IP using socket.
In this cpp file, I build four char array named "message1", "message2", "message3" and "message4" to call 4 services separately. You can change the name of the char array to call these services.
