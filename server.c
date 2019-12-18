/***********server code ****************/

#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <string.h>
#include <stdio.h>

int main()
{	
	int welcomeSocket, newSocket;
	char buffer[1024];
	struct sockaddr_in serverAddr;
	struct sockaddr_storage serverStorage;
	socklen_t addr_size;
	char message[] = "Hello world";

/*-------Create the socket. The three arguments are: --------*/
/* 1. Internet domain  2. Stream socket  3. Default protocol (TCP/IP)*/

	welcomeSocket = socket(PF_INET, SOCK_STREAM, 0);

/*---Configure settings of the server adress struct----*/


/*Adress family = Internet*/

	serverAddr.sin_family = AF_INET;

/* Set port number, using htons to use proper byte order*/
	
	serverAddr.sin_port = htons(7891);
	
/* SET IP adress to localhost*/

	serverAddr.sin_addr.s_addr = inet_addr("127.0.0.1");

/*Set all bits of the padding field to 0 */

	memset(serverAddr.sin_zero,'\0', sizeof(serverAddr.sin_zero));

/*----Bind the adress struckt to the socket ------*/

	bind(welcomeSocket,(struct sockaddr *) &serverAddr, sizeof(serverAddr));
	
/*----Listen on the socket, with max 5 connection requests queued----*/

	if (listen(welcomeSocket,5) == 0)
		printf("Listening\n");
	else
		printf("Error\n");

/*-----Accept call creates a new socket for the incoming connection----*/

	addr_size = sizeof(serverStorage);
	newSocket = accept(welcomeSocket, (struct sockaddr *)&serverStorage, &addr_size);

/*----Send message to the socket of the incoming connection---*/

	strcpy(buffer, "Hello world\n");
	send(newSocket, buffer,13,0);

	return 0;
}
