/****************Client program********************************/

/* client_tcp.c is on zeus.cs.txstate.edu
   open a window on zeus.
   compile:
   $gcc -o c client_tcp.c
   $./c eros.cs.txstate.edu
*/

//Dylan Messerly CS4310 Project 1

#include <stdio.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <string.h>
#include <netdb.h>
#include <stdlib.h>
#include <stdbool.h>

void menu_display();

int main(int argc, char **argv){
  const int MAX = 1024;
  int clientSocket;
  char buffer[MAX];
  struct sockaddr_in serverAddr;
  socklen_t addr_size;
  unsigned short port;
  struct hostent *hostnm;

  uint32_t num, cnum;
  char msg[MAX];

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

  bool valid;

  while(1) {
  	valid = false;
	menu_display();
	
  	scanf("%d", &num); // get users input for menu option
	
	while(valid == false) {	
		valid = true;
		switch(num){
			case 1:
				printf("Add student\n"
				"Please enter ID fname lname score\n");
				break;
			case 2:
				printf("Search by ID\n"
				"Please enter 6 digit ID: ");
				break;
			case 3:
				printf("Search by score\n"
				"Please enter a score between 0-100: ");
				break;
			case 4:
				printf("Display all\n");
				break;
			case 5:
				printf("Delete by ID\n"
				"Please enter 6 digit ID: ");
				break;
			case 6:
				break;	
			default:
				printf("Invalid entry, input a number 1-6: ");
				valid = false;		
			//	getchar();
  				scanf("%d", &num); // get users input for menu option
		}// end switch
	}
	
  	cnum = htonl(num);
  	send(clientSocket, &cnum, sizeof(cnum), 0); // send to server 
	
	if(num == 6){
		printf("client exiting\n");
		break;
	}

	if(num != 4){
		getchar(); //used to get rid of trailing newline charachter in stdin buffer
		fgets(buffer, MAX, stdin);
    		//  cnum = htonl(num);
		send(clientSocket, &buffer, sizeof(buffer), 0);
	}

	// receive a reply message from the server
	recv(clientSocket, msg, sizeof(msg), 0);
	printf("\n%s\n", msg);
 
  } //end while loop

  close(clientSocket);

  return 0;
}

void menu_display(){
	printf(
	"Menu options: \n"
	"1 - Add a student\n"
	"2 - Display a student's info by ID\n"
	"3 - Display students by score\n"
	"4 - Display all students info\n"
	"5 - Delete a student's info by ID\n"
	"6 - Exit program\n\n"
	"Input an integer to select option: "
	);

}


