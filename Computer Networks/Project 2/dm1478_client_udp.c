/* Author of program: Dylan Messerly
   id: dm1478
*/

/* 
   client_udp.c is on zeus.cs.txstate.edu
   open a window on zeus.
   compile:
   $gcc -o c client_udp.c
   $./c eros.cs.txstate.edu
*/

#include <stdio.h>
#include <netdb.h>
#include <string.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <stdlib.h>
#include <stdbool.h>

void menu_display();
bool check_digit(char*);

main(int argc, char **argv)
{
  int s, server_address_size;
  unsigned short port;
  struct sockaddr_in server;
  struct hostent *hostnm;

  const int C_SIZE = 128;
  const int S_SIZE = 1024;
  int num; 
  char buffer[C_SIZE];
  char msg[S_SIZE];
  char buff[S_SIZE];

  if ((s = socket(AF_INET, SOCK_DGRAM, 0))<0)
   {printf("socket creation error");
   }

  server.sin_family = AF_INET; // Internet domain
  server.sin_port = htons(8007); // port
  hostnm = gethostbyname(argv[1]);  //get server's name
  server.sin_addr.s_addr = *((unsigned long *)hostnm->h_addr); 

// communication starts from here

  server_address_size = sizeof(server);

  bool valid;
  
  char fname[20], lname[20], id[10], score[5], excess[10];

  while(1) {

  	valid = false;
	  menu_display();
	
  	fgets(buff, C_SIZE, stdin);

    num = atoi(buff);
    while(valid == false) {	
     
      valid = true;
      switch(num){
        case 1:
          printf("Add student\n");
          break;
        case 2:
          printf("Search by ID\n");
          break;
        case 3:
          printf("Search by score\n");
         
          break;
        case 4:
          printf("Display all\n");
          break;
        case 5:
          printf("Delete by ID\n");
          break;
        case 6:
          break;	
        default:
          printf("Invalid entry, input a number 1-6: ");
          valid = false;		
          fgets(buff, C_SIZE, stdin);
          num = atoi(buff);

      }// end switch
    }

  sendto(s, &num, sizeof(num), 0, (struct sockaddr *)&server, server_address_size); 
	
	if(num == 6){
		printf("***Client exiting***\n");
		break;
	}

	if(num == 1){

    valid = false;

    do{

      printf("Please enter: ID first_name last_name score\n");

      fgets(buffer, C_SIZE, stdin);

      if(sscanf(buffer, "%s %s %s %s %s", &id, fname, lname, &score, excess) != 4){
        printf("\n***Too few or too many parameters, try again***\n\n");
      
      } else if (strlen(id) != 6) {
         printf("\n***ID must be 6 digits, try again***\n\n");

      } else if (!check_digit(id) ) {
          printf("\n***ID must be numeric, try again***\n\n");
      
      } else if (!check_digit(score) ) {
          printf("\n***Score must be 0-100, try again***\n\n");
      
      } else if ( atoi(score) > 100 || atoi(score) < 0 ) {
        printf("\n***Score must be 0-100, try again***\n\n");
      
      } else {
        valid = true;
      }

    } while (valid == false);

    sendto(s, &buffer, sizeof(buffer), 0, (struct sockaddr *)&server, server_address_size); 

	} else if (num == 3) {

    do{
      valid = false;
      printf("Please enter a score between 0-100: \n");

      fgets(buffer, C_SIZE, stdin);

      if(sscanf(buffer, "%s %s", &score, excess) != 1){
        printf("\n***Too few or too many parameters, try again***\n\n");

      } else if (atoi(score) > 100 || atoi(score) < 0 || !check_digit(score)) {
        printf("\n***Score must be 0-100, try again***\n\n");

      } else {
          valid = true;
      } 
      
    } while (valid == false);

    sendto(s, &buffer, sizeof(buffer), 0, (struct sockaddr *)&server, server_address_size); 

  } else if (num == 2 || num == 5) {
    
    do{
      valid = false;
      printf("Please enter 6 digit ID: \n");
      fgets(buffer, C_SIZE, stdin);

      if(sscanf(buffer, "%s %s", id, excess) != 1){
        printf("\n***Too few or too many parameters, try again***\n\n");

      } else if (strlen(id) != 6 || !check_digit(id)) {
        printf("\n***ID must be 6 numerical digits, try again***\n\n");
      } else {
        valid = true;
      }
      
    } while (valid == false);

    sendto(s, &buffer, sizeof(buffer), 0, (struct sockaddr *)&server, server_address_size); 
  }

  recvfrom(s, msg, sizeof(msg), 0, (struct sockaddr *)&server, &server_address_size);

	printf("\n%s\n", msg);
 
  } //end while loop

  close(s);
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

bool check_digit(char* val){
  bool is_num;
  int i, length;
  is_num = true;
  
  length = strlen(val);

  for(i = 0; i < length; i++){
    if(!isdigit(val[i])){
      is_num = false;
    }
  }
  return is_num;
}
