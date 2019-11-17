/*------------------------------------------*/
/*              By Jason Ding               */
/*       E-mail:cestlading@gmail.com        */
/*   Fundamentals of Data Structures in C   */
/*------------------------------------------*/
//Compiler:Microsoft Visual C++ 2010 Express
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(){

	char *s1,*s2,*s3;
	s1=(char*)malloc(sizeof("HELLO")*sizeof(char));
	s2=(char*)malloc(sizeof("World")*sizeof(char));
	strcpy(s1,"Hello");
	strcpy(s2," World");
	s1=(char*)realloc(s1,(sizeof(s1)+sizeof(s2)-1)*sizeof(char));
	strcat(s1,s2);
	s3=(char*)malloc(sizeof(s1)*sizeof(char));
	strcpy(s3,s1);
	printf("%s\n",s1);
	printf("%s\n",s2);
	printf("%s\n",s3);
	system("pause");
}