/****************Client program********************************/

/* client_tcp.c is on zeus.cs.txstate.edu
   open a window on zeus.
   compile:
   $gcc -o c client_tcp.c
   $./c eros.cs.txstate.edu
*/

#include <stdio.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <string.h>
#include <netdb.h>

int main(int argc, char **argv){
  int clientSocket;
  char buffer[1024];
  struct sockaddr_in serverAddr;
  socklen_t addr_size;
  unsigned short port;
  struct hostent *hostnm;

  uint32_t num, cnum;
  char msg[30];

  /*---- Create the socket. The three arguments are: ----*/
  /* 1) Internet domain 2) Stream socket 3) Default protocol (TCP in this case) */
  clientSocket = socket(PF_INET, SOCK_STREAM, 0);
  
  /*---- Configure settings of the server address struct ----*/
  /* Address family = Internet */
  serverAddr.sin_family = AF_INET;
  serverAddr.sin_port = htons(8000);

  /* Set IP address to localhost */
  hostnm = gethostbyname(argv[1]);
  serverAddr.sin_addr.s_addr = *((unsigned long *)hostnm->h_addr); 
/* Set all bits of the padding field to 0 */
  memset(serverAddr.sin_zero, '\0', sizeof serverAddr.sin_zero);  

  /*---- Connect the socket to the server using the address struct ----*/
  addr_size = sizeof serverAddr;
  connect(clientSocket, (struct sockaddr *) &serverAddr, addr_size);


// communication starts from here

   // send an integer to the server
  printf("enter an integer:");
  scanf("%d", &num);
  cnum = htonl(num);
  send(clientSocket, &cnum, sizeof(cnum), 0);

  // receive a reply message from the server
  recv(clientSocket, msg, sizeof(msg), 0);
  printf("%s\n", msg);

  close(clientSocket);

  return 0;
}

