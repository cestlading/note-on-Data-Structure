/*------------------------------------------*/
/*              By Jason Ding               */
/*       E-mail:cestlading@gmail.com        */
/*   Fundamentals of Data Structures in C   */
/*------------------------------------------*/
//Compiler:Microsoft Visual C++ 2010 Express

#include <stdio.h>
#include <stdlib.h>

#define MAX_TERMS 101
#define _CRT_SECURE_NO_WARNINGS

typedef struct {
	int col;
	int row;
	int value;
} term;

void fastTranspose(term a[],term b[]);

void main(void)
{
	FILE *input;
	FILE *output;
	term a[MAX_TERMS];
	int i, term_num;

	term b[MAX_TERMS];

	input=fopen("5.input.txt","r");
	if ( input==NULL )
	{
		printf("open input.txt file failed!\n");
		exit(0);
	}
	i=0;
	while ( fscanf (input, "%d %d %d", &a[i].row, &a[i].col, &a[i].value) != EOF ) {
		i++;
		if (i >= MAX_TERMS) exit(0);
	}
	term_num = i;


	fastTranspose(a,b);//performing fastTranspose
	for (i=0;i<term_num;i++ )//clone b into a
	{
		a[i].row=b[i].row;
		a[i].col=b[i].col;
		a[i].value=b[i].value;
	}

	output=fopen("5.transposed.txt","w+"); 
	if ( output== NULL )
	{
		printf("open transposed.txt file failed!\n");
		exit(0);
	}
	for ( i=0; i < term_num; i++ )
	{
		fprintf( output, "%d %d %d\n", a[i].row, a[i].col, a[i].value);

	}
	fclose(output);
	fclose(input);
}

void fastTranspose(term a[],term b[]){
	int rowTerms[MAX_TERMS],startingPos[MAX_TERMS];
	int i,j,numCols = a[0].col,numTerms = a[0].value;
	b[0].row = numCols;b[0].col = a[0].row;
	b[0].value = numTerms;
	if(numTerms > 0){
		for(i=0;i<numCols;i++){
			rowTerms[i] = 0;
		}
		for(i=1;i<=numTerms;i++){
			rowTerms[a[i].col]++;
		}
		startingPos[0] = 1;
		for(i=1;i<numCols;i++){
			startingPos[i]=startingPos[i-1]+rowTerms[i-1];
		}
		for(i=1;i<=numTerms;i++){
			j=startingPos[a[i].col]++;
			b[j].row=a[i].col; b[j].col=a[i].row;
			b[j].value=a[i].value;
		}
	}
}
