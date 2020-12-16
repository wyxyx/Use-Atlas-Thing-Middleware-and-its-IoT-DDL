#include<stdio.h>
#include<iostream>
#include<string.h>	//strlen
#include<sys/socket.h>
#include<arpa/inet.h>	//inet_addr

int main(int argc, char* argv[])
{
	int socket_desc;
	struct sockaddr_in server;
	//Create socket
	socket_desc = socket(AF_INET, SOCK_STREAM, 0);
	if (socket_desc == -1)
	{
		printf("Could not create socket.\n");
	}

	server.sin_addr.s_addr = inet_addr("127.0.0.1");
	server.sin_family = AF_INET;
	server.sin_port = htons(6668);

	//Connect to remote server
	if (connect(socket_desc, (struct sockaddr*)&server, sizeof(server)) < 0)
	{
		puts("Connect error.\n");
		return 1;
	}

	puts("Connected.\n");

	//Send data
	char message1[] = 
    "{ \"Tweet Type\" : \"Service call\",\"Thing ID\" : \"MySmartThing01\",\"Space ID\" : \"MySmartSpace\",\"Service Name\" : \"buzzerRing\",\"Service Inputs\" : \"()\" }";
	char message2[] = 
    "{ \"Tweet Type\" : \"Service call\",\"Thing ID\" : \"MySmartThing01\",\"Space ID\" : \"MySmartSpace\",\"Service Name\" : \"buzzerMusic\",\"Service Inputs\" : \"()\" }";
	char message3[] = 
    "{ \"Tweet Type\" : \"Service call\",\"Thing ID\" : \"MySmartThing01\",\"Space ID\" : \"MySmartSpace\",\"Service Name\" : \"sound\",\"Service Inputs\" : \"()\" }";
	char message4[] = 
    "{ \"Tweet Type\" : \"Service call\",\"Thing ID\" : \"MySmartThing01\",\"Space ID\" : \"MySmartSpace\",\"Service Name\" : \"rapidSound\",\"Service Inputs\" : \"()\" }";

    std::cout<<"Send successfully.\n";

    //chang the name of "message1" to one of the four services you want to execute
    //"message1" to "message4"
	if (send(socket_desc, message1, strlen(message1), 0) < 0)
	{
		puts("Send failed.\n");
		return 1;
	}
	puts("Send data.\n");

	return 0;
}
