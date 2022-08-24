//Dylan Messerly
//

#include <stdio.h>
#include <unistd.h>
#include<stdlib.h>

main(int argc,char *argv[]) {
	
	pid_t pid = fork();
	
	if (pid < 0) {
                perror("fork call");
                exit(1);
	} else if (pid == 0){
		execvp(argv[1],&argv[1]);
	} else {
		printf("Parent id: %u\n", getppid() );
		printf("Child id: %u\n", getpid() );
		wait(NULL);
	}
	
}
