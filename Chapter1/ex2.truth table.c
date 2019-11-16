/*------------------------------------------*/
/*              By Jason Ding               */
/*       E-mail:cestlading@gmail.com        */
/*   Fundamentals of Data Structures in C   */
/*------------------------------------------*/
//Compiler:Microsoft Visual C++ 2010 Express
#include <stdio.h>
#include <stdlib.h>

int truth_table(int n);

int main(){

	truth_table(2);
	
	system("pause");
}

int truth_table(int n){
	int len = 1<<n;
	int i,j,mask;
	int flag;
	for(i=0;i<len;i++){
		mask = 1<<n-1;
		printf("<");
		flag = 0;
		for(j=1;j<=n;j++){
			if(flag)
				printf(",");
			if(i&mask)
				printf("true ");
			else
				printf("false"); 
			mask >>= 1;
			flag = 1; 
		}
		printf(">");
		printf("\n");
	}
	
}