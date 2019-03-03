/*------------------------------------------*/
/*              By Jason Ding               */
/*       E-mail:cestlading@gmail.com        */
/*   Fundamentals of Data Structures in C   */
/*------------------------------------------*/
//Compiler:Microsoft Visual C++ 2010 Express
#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#define MAX_SIZE 101
#define SWAP(x,y,t) ((t) = (x), (x) = (y), (y) = (t))
void sort(int list[],int n);

int main(){

	int i,n;
	int *list;
	printf("Enter the number of numbers to generate: ");
	scanf("%d",&n);
	if(n < 1|| n > MAX_SIZE){
		fprintf(stderr,"Improper value of n\n");
		system("pause");
		exit(EXIT_FAILURE);
	}
	list = (int*) malloc(n*sizeof(int));//dynamic allocation
	for(i = 0;i < n;i++){
		list[i] = rand() % 100;
		printf("%d ",list[i]);
	}
	sort(list,n);
	printf("\nSorted array:\n");

	for(i = 0;i < n;i++){
		printf("%d ",list[i]);
	}
	printf("\n");

	system("pause");
}

void sort(int list[],int n){
	int i,j,min,temp;
	for(i = 0;i < n-1;i++){
		min = i;
		for(j = i+1;j < n;j++)
			if(list[j] < list[min])
				min = j;
		SWAP(list[i],list[min],temp);
	}
}