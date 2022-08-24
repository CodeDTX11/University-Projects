//Dylan Messerly
//

	
#include<stdio.h>
#include<string.h>

int main(){

	char names[50][50],copy[50];

	int num_stu = 0;
	int i,j =0;

	while(scanf("%s", names[num_stu])!= EOF){
		num_stu++;
	}

	while(i<num_stu){
		j=i+1;
		while(j<num_stu){
			if(strcasecmp(names[i],names[j])>0){
				strcpy(copy,names[i]);
				strcpy(names[i],names[j]);
				strcpy(names[j],copy);
			}
		j++;
		}
	i++;
	}
				
	for(i=0;i<num_stu;i++){
		printf("%s\n",names[i]);
	}
															  

	 
}//end main
			    
