//   Author of program: Dylan Messerly
//   id: dm1478

/* server_udp.c is on eros.cs.txstate.edu
   open a window on eros.
   compile and run the server program first:
   $gcc -o s server_udp.c
   $./s
*/

#include <stdio.h>
#include <string.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <netdb.h>
#include <sys/types.h>
#include <stdlib.h>
#include <stdbool.h>

main(int argc, char **argv)
{
  int s, namelen, client_address_size;
  struct sockaddr_in server, client;

  const int C_SIZE = 128;
  const int S_SIZE = 1024;
  int num;
  char msg[S_SIZE];
  char message[S_SIZE];
  char buffer[C_SIZE];

  FILE *fptr;

  /* Create a datagram socket in the internet domain and 
   use the UDP protocol. */
   s = socket(AF_INET, SOCK_DGRAM, 0);

   server.sin_family = AF_INET; /* Server is in Internet Domain */
   server.sin_port = htons(8007); /* port */
   server.sin_addr.s_addr = INADDR_ANY; /* Server's Internet Address */

   bind(s, (struct sockaddr *)&server, sizeof(server));

// communication starts from here

   client_address_size = sizeof(client);

  // open file
  if ((fptr = fopen("database.txt", "r+")) == NULL){
    	printf("Error! file not found, exiting");
        // Program exits if the file pointer returns NULL.
        exit(1);
  }

  bool found_ID;
  bool found_score;
  bool duplicate_ID;
  int stud_score;
  int filter_score;

	printf("***Server is now online***\n\n");

    while(1){

    recvfrom(s, &num, sizeof(num), 0, (struct sockaddr *)&client, &client_address_size); 
	
	printf("Menu option received: %d\n\n", num);
	if(num == 6){
		printf("***Server exiting***\n");	
		break;
	}
	
	switch(num) {
		case 1:	//add student
      		recvfrom(s, &buffer, sizeof(buffer), 0, (struct sockaddr *)&client, &client_address_size); 
			duplicate_ID = false;
			while(fgets(msg, S_SIZE, fptr) != NULL) {
				if(strncmp(msg, buffer, 6) == 0) { //check for duplicate IDs, IDs must be uniqe
					strcpy(message, "From server: Duplicate ID (IDs must be unique!), student not added\n");
					duplicate_ID = true;
				}
			}
			
			if(duplicate_ID == false){
				fprintf(fptr, "%s", buffer);
				strcpy(message, "From server: Student added\n");
			}
			rewind(fptr);
			break;
		case 2: //display student by ID
			found_ID = false;
			//recv(newSocket, &buffer, sizeof(buffer), 0);
      		recvfrom(s, &buffer, sizeof(buffer), 0, (struct sockaddr *)&client, &client_address_size); 
			strcpy(message, "From server: Student found\n");
			while(fgets(msg, S_SIZE, fptr) != NULL) {
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
			//recv(newSocket, &buffer, sizeof(buffer), 0);
     		recvfrom(s, &buffer, sizeof(buffer), 0, (struct sockaddr *)&client, &client_address_size); 
			filter_score = atoi(buffer);

			strcpy(message, "From server: Displaying students who have"
			" score equal or higher than sent score\n");

			while(fgets(msg, S_SIZE, fptr) != NULL) {
				sscanf(msg, "%*s %*s %*s %d", &stud_score);
				if(stud_score >= filter_score){
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
			while(fgets(msg, S_SIZE, fptr) != NULL){
				strcat(message, msg);		
			}
			rewind(fptr);
			break;
		case 5: // delete student by ID
			found_ID = false;
			//recv(newSocket, &buffer, sizeof(buffer), 0);
      		recvfrom(s, &buffer, sizeof(buffer), 0, (struct sockaddr *)&client, &client_address_size); 
			
      		while(fgets(msg, S_SIZE, fptr) != NULL) {
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

	//send(newSocket, message, sizeof(message), 0);
   sendto(s, message, sizeof(message), 0, (struct sockaddr *)&client, sizeof(client));
	strcpy(message, "");

} //end while loop

  fclose(fptr); //close file
  
  close(s);

  return 0;

}