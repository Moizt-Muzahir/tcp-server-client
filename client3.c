#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/socket.h>

#include <netinet/in.h>
int main() {
	
	char request[256]; 
	char buf[200];
	
	// create the socket
	int sock;
	sock = socket(AF_INET, SOCK_STREAM, 0);
	
	//setup an address
	struct sockaddr_in server_address;
	server_address.sin_family = AF_INET;
	server_address.sin_addr.s_addr = INADDR_ANY;
	server_address.sin_port = htons(3001);

	connect(sock, (struct sockaddr *) &server_address, sizeof(server_address));
	while(1){

	scanf("%[^\n]%*c",request);
	send(sock, request, sizeof(request), 0);
	if(!(strcmp(request,"Exit")))
		break;
	recv(sock, &buf, sizeof(buf), 0);
	if(!(strcmp(buf,"Exit")))
		break;
	printf("Messaged recieved from Server\n %s \n", buf);
	}
	send(sock, "Exit", sizeof("Exit"), 0);
	close(sock);

	return 0;
}
