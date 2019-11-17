/*------------------------------------------*/
/*              By Jason Ding               */
/*       E-mail:cestlading@gmail.com        */
/*   Fundamentals of Data Structures in C   */
/*------------------------------------------*/
//Compiler:Microsoft Visual C++ 2010 Express
#include <stdio.h>
#include <stdlib.h>

#define SIZE 100
typedef struct{
	int value;	
}element;

element queue[SIZE];
int top=-1;

void display(void);
void push(int v);
int pop(void);

int main(){

	int i,num;
	for(i=0;i<100;i++){
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
	printf("\n");
	display();
	system("pause");
}

void display(void){
	int i;
	if(top!=-1){
		for(i=0;i<=top;i++){
			printf("%3d ",queue[i]);
			if(i%10==9){
				printf("\n");
			}
		}
	}
}

void push(int v){
	if(top<SIZE){
		queue[++top].value=v;
	}else{
		fprintf(stderr,"queue overflow\n");
		system("pause");
		exit(0);
	}
}

int pop(void){
	int v,i;
	if(top==-1){
		fprintf(stderr,"queue is empty\n");
		system("pause");
		exit(0);
	}else{
		v=queue[0].value;
		for(i=0;i<top;i++){
			queue[i]=queue[i+1];
		}
		top--;
		return v;
	}
}