/*------------------------------------------*/
/*              By Jason Ding               */
/*       E-mail:cestlading@gmail.com        */
/*   Fundamentals of Data Structures in C   */
/*------------------------------------------*/
//Compiler:Microsoft Visual C++ 2010 Express
#include <stdio.h>
#include <stdlib.h>

void swap(char *list,int i,int j,int r);
void permutation(char *list,int i,int n);

int main(){

	char s[]="ABCDEFGHIJ";
	permutation(s,0,3);
	
	
	system("pause");
}

void swap(char *list,int i,int j,int r){
	char temp;
	char k;
	if(i!=j){
		if(!r){
			temp = list[j];
			for(k=j;k>i;k--)
				list[k]=list[k-1];
			list[i]=temp;
		}else if(r){
			temp = list[i];
			for(k=i;k<j;k++)
				list[k]=list[k+1];
			list[j]=temp;
		}
	}
	
}

void permutation(char *list,int i,int n){
	int j,temp,k;
	if(i==n){
		for(j=0;j<=n;j++)
			printf("%c",list[j]);
		printf("\n");
	}else{
		for(j=i;j<=n;j++){
			swap(list,i,j,0);
			permutation(list,i+1,n);
			swap(list,i,j,1);
		}
	}
}