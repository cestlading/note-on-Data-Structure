/*------------------------------------------*/
/*              By Jason Ding               */
/*       E-mail:cestlading@gmail.com        */
/*   Fundamentals of Data Structures in C   */
/*------------------------------------------*/
//Compiler:Microsoft Visual C++ 2010 Express
#include <stdio.h>
#include <stdlib.h>

void swap(int *x,int *y);//declare function with pass by reference

int main(){

	int a = 1,b = 10;
	printf("a = %d,b = %d\n",a,b);
	printf("after swap:\n");
	swap(&a,&b);//perform swapping
	printf("a = %d,b = %d\n",a,b);

	system("pause");
}

void swap(int *x,int *y){//function body
	int temp = *x;
	*x = *y;
	*y = temp;
}