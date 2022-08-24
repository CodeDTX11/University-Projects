//Dylan Messerly


#include<stdio.h>


int main() {
 
          struct Student_info{
                  char name[30];
                  float gpa;
          };
 
          struct Student_info students[20];
 
          //printf("Input student's first name and gpa\n");
          int i = 0;
 
          while(scanf("%s %f", students[i].name, &students[i].gpa)!=EOF) {
 
          i++;
          }
 
          //printf("\n");
 
          int j = 0;
 
          while(j < i){
                  if(students[j].gpa > 3.0)
                          printf("%s\n", students[j].name);
                  j++;
          }
 
 
  }//end main
