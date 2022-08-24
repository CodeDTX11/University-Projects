/* client_udp.c is on zeus.cs.txstate.edu
   open a window on zeus.
   compile:
   $gcc -o c client_udp.c
   $./c eros.cs.txstate.edu
*/

#include <stdio.h>

#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

int main(){

    int id, score;
    char fname[20], lname[20];

    while(1){

    printf("enter stuff: \n");

    scanf("%d", &id);

    printf("%d\n", id);

    //if(scanf("%6d %20s %20s %3d", &id, fname, lname, &score) != 4)
    //    break;

    }
    return 0;
}