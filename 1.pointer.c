/*------------------------------------------*/
/*              By Jason Ding               */
/*       E-mail:cestlading@gmail.com        */
/*   Fundamentals of Data Structures in C   */
/*------------------------------------------*/
//Compiler:Microsoft Visual C++ 2010 Express
#include <stdio.h>
#include <stdlib.h>

int main(){

	int i,*pi;//declare i and its pointer
	pi = &i;//get the address of i

	i = 10;
	printf("i = %d\n",i);
	printf("pi = %p\n",pi);//print the address stored in pointer pi
	printf("*pi = %d\n",*pi);//print the value addressed by pointer pi

	system("pause");
}