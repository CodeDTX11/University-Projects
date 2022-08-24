//Dylan Messerly

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

main() {

char *path, *argv[20], buf[80], n, *p;
int m, status, inword, continu;

while(1) {

	inword = 0;
	p = buf;
	m = 0;
	continu=0;
	printf( "\nshhh> ");

	while ( ( n = getchar() ) != '\n'  || continu ) {
	   	if ( n ==  ' ' ) { 
	    		if ( inword ) {
				inword = 0;
				*p++ = 0;
	    		} 
	   	}
		else if ( n == '\n' )
			continu = 0;

		else if ( n == '\\' && !inword )
			continu = 1;
		else {
	    		if ( !inword ) {
				 inword = 1;
		 	 	 argv[m++] = p;
		 	 	 *p++ = n;
	     		}
	    		 else 
				 *p++ = n;
		}
	}	

	*p++ = 0;
	argv[m] = 0;
//xxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxx

	if ( strcmp(argv[0],"exit") == 0 )
		exit (0);
	
	int i = 0;
	int pipes = 0; 
	int k[20];
	k[0] = 0;
	int spot = 1;
	int l_fd[2], r_fd[2];
	char infile[30];
	char outfile[30];
	int input_redir, output_redir = 0;

	for ( i = 0; i < m; i++ ) {
		if ( strcmp( argv[i], "|") == 0 ) {	
			argv[i] = 0;
			k[spot] = i+1;
			spot++;
			pipes++;
		} else if ( strcmp( argv[i], "<") == 0 ) {//input red
			strcpy(infile, argv[i+1]);		
			argv[i] = 0;
			input_redir = 1;
		} else if ( strcmp( argv[i], ">") == 0 ) {//output red
			strcpy(outfile, argv[i+1]);		
			argv[i] = 0;
			output_redir = 1;
		}
	}

	int j = 0;
	int pipectr = pipes;
	int file; 
	int pid;
	FILE *inf;

	for ( j = 0; j <= pipes; j++ ) {
		if ( pipes != 0 ) 
			pipe(r_fd);

		pid = fork();

		if ( pid > 0) {
			if ( j > 0 ) {
				close(l_fd[0]);
				close(l_fd[1]);
			}
			l_fd[0] = r_fd[0];
			l_fd[1] = r_fd[1];
		} else if( pid == 0) {

			if (input_redir == 1 && j == 0 ) {
				if ((inf = fopen(infile, "r")) == NULL){
					 perror("Could not open input file");
					 exit(-1);
				}
				close(0);
				dup(inf);
				close(inf);
				fclose(inf);
			}
			if ( pipes ) {
				
				if( j == 0) { // right pipe

					close(1);
					dup(r_fd[1]);
					close(r_fd[0]);
					close(r_fd[1]);
				} else if (j == pipes) { // left pipe
					close(0);
					dup(l_fd[0]);
					close(l_fd[0]);
					close(l_fd[1]);
				} else { // both way pipe
				
					close(1);
					dup(r_fd[1]);
					close(r_fd[0]);
					close(r_fd[1]);

					close(0);
					dup(l_fd[0]);
					close(l_fd[0]);
					close(l_fd[1]);
				}
			}
			if ( output_redir && j == pipes ) {
				if ((file = creat(outfile, 0750)) < 0)
					exit(-1);
				close(1);
				dup(file);
				close(file);
			}
			execvp(argv[k[j]], argv);

			close(inf);
			if ( fork() == 0 )
			{
				execvp( argv[0], argv );
				printf ( " didn't exec \n ");
			}
		}

	wait(&status);
	}
}//end while 1
}//end main

