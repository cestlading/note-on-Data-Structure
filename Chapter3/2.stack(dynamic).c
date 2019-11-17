/*------------------------------------------*/
/*              By Jason Ding               */
/*       E-mail:cestlading@gmail.com        */
/*   Fundamentals of Data Structures in C   */
/*------------------------------------------*/
//Compiler:Microsoft Visual C++ 2010 Express
#include <stdio.h>
#include <stdlib.h>


typedef struct{
	int value;	
}element;

element *stack;
int capacity=100;
int top=-1;

void display(void);
void push(int v);
int pop(void);
void resize(int n,element *e);

int main(){

	int i,size_re=200;
	stack=(element*)malloc(capacity*sizeof(element));
	resize(size_re,stack);
	for(i=0;i<200;i++){
		push(i);
	}
	display();
	printf("\n");
	for(i=0;i<50;i++){
		printf("%3d ",pop());
		if(i%10==9){
			printf("\n");
		}
	}
	system("pause");
}

void display(void){
	int i;
	if(top!=-1){
		for(i=0;i<=top;i++){
			printf("%3d ",stack[i]);
			if(i%10==9){
				printf("\n");
			}
		}
	}
}

void push(int v){
	if(top<capacity){
		stack[++top].value=v;
	}else{
		fprintf(stderr,"stack overflow\n");
		system("pause");
		exit(0);
	}
}

int pop(void){
	if(top==-1){
		fprintf(stderr,"stack is empty\n");
		system("pause");
		exit(0);
	}else{
		return stack[top--].value;
	}
}

void resize(int n,element *e){
	if(n>capacity){
		e=(element*)realloc(e,n*sizeof(element));
		capacity=n;
	}else{
		fprintf(stderr,"n should be larger than capacity!\n");
	}
}