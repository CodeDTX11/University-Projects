/***************Server program**************************/

/* server_tcp.c is on eros.cs.txstate.edu
   open a window on eros.
   compile and run the server program first:
   $gcc -o s server_tcp.c
   $./s
*/

//Dylan Messerly CS4310 project 1

#include <stdio.h>
#include <stdlib.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <string.h>
#include <stdbool.h>

int main(int argc, char **argv){
  const int MAX = 1024;
  int welcomeSocket, newSocket;
  char buffer[MAX];
  struct sockaddr_in serverAddr;
  struct sockaddr_storage serverStorage;
  socklen_t addr_size;
  unsigned short port; /* port server binds to */

  uint32_t num;
  char msg[MAX];
  char message[MAX];

  FILE *fptr;

  /*---- Create the socket. The three arguments are: ----*/
  /* 1) Internet domain 2) Stream socket 3) Default protocol (TCP in this case) */
  welcomeSocket = socket(PF_INET, SOCK_STREAM, 0);
  
  /*---- Configure settings of the server address struct ----*/
  /* Address family = Internet */
  serverAddr.sin_family = AF_INET;
  /* Set port number, using htons function to use proper byte order */
  serverAddr.sin_port = htons(8000);
  /* Set IP address to localhost */
  serverAddr.sin_addr.s_addr = INADDR_ANY;
  /* Set all bits of the padding field to 0 */
  memset(serverAddr.sin_zero, '\0', sizeof serverAddr.sin_zero);  

  /*---- Bind the address struct to the socket ----*/
  bind(welcomeSocket, (struct sockaddr *) &serverAddr, sizeof(serverAddr));

  /*---- Listen on the socket, with 5 max connection requests queued ----*/
  if(listen(welcomeSocket,5)==0)
    printf("Listening\n");
  else
    printf("Error\n");

  /*---- Accept call creates a new socket for the incoming connection ----*/
  addr_size = sizeof serverStorage;
  newSocket = accept(welcomeSocket, (struct sockaddr *) &serverStorage, &addr_size);

  // communication starts from here
  
  // open file
  if ((fptr = fopen("database.txt", "r+")) == NULL){
    	printf("Error! file not found, exiting");
        // Program exits if the file pointer returns NULL.
        exit(1);
  }

  bool found_ID;
  bool found_score;
  int stud_score;
  int filter_score;

  while(1){

 	recv(newSocket, &num, sizeof(num), 0);
	num = ntohl(num);
	printf("Menu option received: %d\n", num);
	if(num == 6){
		printf("server exiting\n");	
		break;
	}
	
	switch(num) {
		case 1:	//add student
			recv(newSocket, &buffer, sizeof(buffer), 0);
			while(fgets(msg, 100, fptr) != NULL)
				;
			fprintf(fptr, "%s", buffer);
			rewind(fptr);
			strcpy(message, "From server: Student added\n");
			break;
		case 2: //display student by ID
			found_ID = false;
			recv(newSocket, &buffer, sizeof(buffer), 0);
			strcpy(message, "From server: Student found\n");
			while(fgets(msg, 100, fptr) != NULL) {
				if(strncmp(msg, buffer, 6) == 0){
					strcat(message, msg);
					found_ID = true;
					break;
				}
			}
			rewind(fptr);
			if(found_ID == false){
				strcpy(message, "From server: Student ID not found\n");
			}
			break;
		case 3: //display students by score
			found_score = false;
			recv(newSocket, &buffer, sizeof(buffer), 0);
			filter_score = atoi(buffer);

			strcpy(message, "From server: Displaying students who have"
			" score higher than sent score\n");

			while(fgets(msg, 100, fptr) != NULL) {
				sscanf(msg, "%*s %*s %*s %d", &stud_score);
				if(stud_score > filter_score){
					strcat(message, msg);
					found_score = true;
				}
			}
			rewind(fptr);
			if(found_score == false){
				strcpy(message, "From server: No students have that high of score\n");
			}
			break;
		case 4: //display all database
			strcpy(message, "From server: Displaying full database\n");
			while(fgets(msg, 100, fptr) != NULL){
				strcat(message, msg);		
			}
			rewind(fptr);
			break;
		case 5: // delete student by ID
			found_ID = false;
			recv(newSocket, &buffer, sizeof(buffer), 0);

			while(fgets(msg, 100, fptr) != NULL) {
				if(strncmp(msg, buffer, 6) == 0){
					found_ID = true;
				} else {
					strcat(message, msg);
				}
			}
			rewind(fptr);

			if(found_ID == true) {
				fptr = freopen("database.txt", "w", fptr);
				fprintf(fptr, "%s", message);
				fptr = freopen("database.txt", "r+", fptr);
				strcpy(message, "From server: Student successfully deleted\n");
			} else if (found_ID == false) {
				strcpy(message, "From server: Student ID not found, no action taken\n");
			}
			break;
	} // end switch

	send(newSocket, message, sizeof(message), 0);
	strcpy(message, "");

} //end while loop

  fclose(fptr); //close file

  close(newSocket);
  close(welcomeSocket);

  return 0;
}

