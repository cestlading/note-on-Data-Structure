/*------------------------------------------*/
/*              By Jason Ding               */
/*       E-mail:cestlading@gmail.com        */
/*   Fundamentals of Data Structures in C   */
/*------------------------------------------*/
//Compiler:Microsoft Visual C++ 2010 Express
#include <stdio.h>
#include <stdlib.h>

int fibonacci_recursive(int n);
int fibonacci_iterative(int n);

int main(){

	int i;
	printf("fibonacci series by recursive method:\n");
	for(i=0;i<=10;i++){
		printf("%d ",fibonacci_recursive(i));
	}
	printf("\n");
	printf("fibonacci series by iterative method:\n");
	for(i=0;i<=10;i++){
		printf("%d ",fibonacci_iterative(i));
	}
	printf("\n");
	system("pause");
}

int fibonacci_recursive(int n){
	if(n==1||n==0)
		return 1;
	else if(n>1)
		return fibonacci_recursive(n-1)+fibonacci_recursive(n-2);
}

int fibonacci_iterative(int n){
	int result,x=1,y=1,i;
	if(n==1||n==0)
		result=1;
	else if(n>1){
		for(i=1;i<=n-1;i++){
			result=x+y;
			x=y;
			y=result;
		}
	}
	return result;
	
}