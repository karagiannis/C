/***************CLIENT CODE ******************/


#include <stdio.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <string.h>


int main()
{
	int clientSocket;
	char buffer[1024];
	struct sockaddr_in serverAddr;
	socklen_t addr_size;

/*--------Create the socket. The three arguments are:-------*/
/* 1. Internet domain 2. Stream socket 3. Default protocol (TCP)*/
	clientSocket = socket(AF_INET, SOCK_STREAM,0);

/*----Configure settings of the server address struct-----*/
/*Adress family = Internet*/
	serverAddr.sin_family = AF_INET;
	
/*Set port number using htons functions to use proper byte order*/
	serverAddr.sin_port = htons(7891);

/*Set server adress to local host*/
	serverAddr.sin_addr.s_addr = inet_addr("127.0.0.1");

/*Set all bits of the padding field to 0  */
	memset(serverAddr.sin_zero,'\0',sizeof(serverAddr.sin_zero));

/*----Connect the socket to the server using the adress struct----*/
	addr_size = sizeof(serverAddr);
	connect(clientSocket, (struct sockaddr *) &serverAddr, addr_size);

/*-----Read the message from the server into the buffer-------*/
	recv(clientSocket, buffer, 1024,0);

/*-----Print the received buffer-----------*/
	printf("Data received:%s", buffer);

	return 0;
}
 
	
/* Set all bits of the padding field to 0 */


