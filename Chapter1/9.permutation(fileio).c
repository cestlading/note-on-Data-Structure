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

FILE *output;
int counter;

int main(){

	
	char s[]="ABCDEFGHIJKLMNOPQRSTUVWXYZ";
	output=fopen("permutation.txt","w+");
	counter=0;
	permutation(s,0,12);
	
	
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
		//printf("%d",counter);
		for(j=0;j<=n;j++)
			fprintf(output,"%c",list[j]);
		fprintf(output,"\n");
		//printf("\n");
		//counter++;
	}else{
		for(j=i;j<=n;j++){
			swap(list,i,j,0);
			permutation(list,i+1,n);
			swap(list,i,j,1);
		}
	}
}