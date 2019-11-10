/*------------------------------------------*/
/*              By Jason Ding               */
/*       E-mail:cestlading@gmail.com        */
/*   Fundamentals of Data Structures in C   */
/*------------------------------------------*/
//Compiler:Microsoft Visual C++ 2010 Express
#include <stdio.h>
#include <stdlib.h>

char swap(char *x,char *y);
void permutation(char *list,int i,int n);

int main(){

	char s[]="ABCDEFGHIJ";
	permutation(s,0,3);
	
	
	system("pause");
}

char swap(char *x,char *y){
	char c;
	c = *x;
	*x = *y;
	*y = c;
}

void permutation(char *list,int i,int n){
	int j,temp,k;
	if(i==n){
		for(j=0;j<=n;j++)
			printf("%c",list[j]);
		printf("\n");
	}else{
		for(j=i;j<=n;j++){
			swap(&list[i],&list[j]);
			permutation(list,i+1,n);
			swap(&list[i],&list[j]);
		}
	}
}