/*------------------------------------------*/
/*              By Jason Ding               */
/*       E-mail:cestlading@gmail.com        */
/*   Fundamentals of Data Structures in C   */
/*------------------------------------------*/
//Compiler:Microsoft Visual C++ 2010 Express
#include <stdio.h>
#include <stdlib.h>

int** make2Darr(int m,int n){
	int **x,i;
	x=(int**)calloc(m,sizeof(int**));
	for(i=0;i<n;i++)
		x[i]=(int*)calloc(n,sizeof(int*));
	return x;
}

int main(){

	int m=3,n=5;
	int **p;
	int i,j;
	p = make2Darr(m,n);
		
	for(i=0;i<m;i++){
		for(j=0;j<n;j++){
			printf("%d ",p[i][j]);
		}
		printf("\n");
	}

	for(i=0;i<m;i++)
		free(p[i]);
	p=NULL;
	free(p);
	system("pause");
}

