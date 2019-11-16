/*------------------------------------------*/
/*              By Jason Ding               */
/*       E-mail:cestlading@gmail.com        */
/*   Fundamentals of Data Structures in C   */
/*------------------------------------------*/
//Compiler:Microsoft Visual C++ 2010 Express
#include <stdio.h>
#include <stdlib.h>

#define SIZE 5

int Horner(int *coef,int len,int x);

int main(){

	int coefficent[SIZE]={1,2,3,4,5};
	int x = 2;
	int result=Horner(coefficent,SIZE,x);
	int i;
	printf("for the expression:");
	for(i=SIZE-1;i>=0;i--){
		if(i!=0){
			printf("%d*%d^%d+",coefficent[i],x,i);
		}else{
			printf("%d",coefficent[i]);
		}
	}
	printf("\nresult is:%d\n",result);
	
	system("pause");
}

int Horner(int *coef,int len,int x){
	int result = coef[0],i;
	for(i=1;i<len;i++){
		result = result*x+coef[i];
	}
	return result;
}