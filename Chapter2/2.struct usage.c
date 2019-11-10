/*------------------------------------------*/
/*              By Jason Ding               */
/*       E-mail:cestlading@gmail.com        */
/*   Fundamentals of Data Structures in C   */
/*------------------------------------------*/
//Compiler:Microsoft Visual C++ 2010 Express
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct Date{
	int year;
	int month;
	int day;
};

struct Human{
	char name[10];
	int age;
	int score;
	Date birthday;//struct in a struct
	
	void display(void){//member function
		printf("Name:%s\n",name);
		printf("age:%d\n",age);
		printf("score:%d\n",score);
		printf("born on:%d/%d/%d\n",birthday.year,birthday.month,birthday.day);
	}
};

int main(){

	Human H;//declare a human
	strcpy(H.name,"Amy");
	H.age = 12;
	H.score = 95;
	H.birthday.year = 1998;
	H.birthday.month = 1;
	H.birthday.day = 20;

	H.display();//call the function
	
	system("pause");
}

