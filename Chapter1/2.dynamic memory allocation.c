/*------------------------------------------*/
/*              By Jason Ding               */
/*       E-mail:cestlading@gmail.com        */
/*   Fundamentals of Data Structures in C   */
/*------------------------------------------*/
//Compiler:Microsoft Visual C++ 2010 Express
#include <stdio.h>
#include <stdlib.h>

int main(){

	int i,*pi;
	float f, *pf;
	pi = (int*) malloc(sizeof(int));//dynamically allocation with size int
	pf = (float*) malloc(sizeof(float));//dynamically allocation with size float
	*pi = 1024;
	*pf = 3.14;
	printf("i = %d, f = %lf\n",*pi,*pf);
	free(pi);//free the memory of pointer pi
	free(pf);;//free the memory of pointer pf

	system("pause");
}