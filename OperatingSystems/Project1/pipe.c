//Dylan Messerly

#include<sys/types.h>
#include<stdlib.h>
#include<stdio.h>
#include<unistd.h>

int main(){

	int my_pipe[2];

	if (pipe(my_pipe) < 0){
		perror("pipe call");
		exit(1);
	}

	pid_t pid = fork();

	if (pid < 0) {
		perror("fork call");
		exit(2);
	} else if (pid == 0){
		close(0);
		dup(my_pipe[0]);
		close(my_pipe[0]);
		close(my_pipe[1]);
		execl("./sort","./sort",NULL);
	} else {
		close(1);
		dup(my_pipe[1]);
		close(my_pipe[1]);
		close(my_pipe[0]);
		execl("./pre","./pre",NULL);	
	}
	
}//end main
