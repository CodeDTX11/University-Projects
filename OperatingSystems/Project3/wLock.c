//Dylan Messerly

#include <stdio.h>
#include <pthread.h>

#define TIMES 5
#define LOOPS 10
#define N 1 

void *printA();
void *printB();

pthread_mutex_t mutex;

int main(){
  int i;
  pthread_t tid;

  pthread_setconcurrency(2);

  pthread_create(&tid, NULL, (void *(*)(void *))printA, NULL  );
  pthread_create(&tid, NULL, (void *(*)(void *))printB, NULL );

 pthread_exit(0);

}

void *printA(){
 int i,j;

 for (j = 1; j< LOOPS+1; j++) {
 	pthread_mutex_lock(&mutex);  
	printf("\n");

	for (i = 0; i < TIMES; i++)
  		printf("%i:AAAAAAAAAA\n", j);

	pthread_mutex_unlock(&mutex);
	usleep(N);
}
}

void *printB(){

int i,j;

 for (j = 1; j< LOOPS+1; j++) {
	pthread_mutex_lock(&mutex);  
	printf("\n");

	for (i = 0; i < TIMES; i++)
 	     printf("%i:BBBBBBBBBB\n", j);

	pthread_mutex_unlock(&mutex);

	usleep(N);

 }
 
}

