/*------------------------------------------*/
/*              By Jason Ding               */
/*       E-mail:cestlading@gmail.com        */
/*   Fundamentals of Data Structures in C   */
/*------------------------------------------*/
//Compiler:Microsoft Visual C++ 2010 Express
#include <stdio.h>
#include <stdlib.h>

typedef struct listnode *listpointer;
typedef struct listnode{
	int data;
	listpointer link;
};

void trace(listpointer first);
listpointer create(int n);
listpointer insert(listpointer target,listpointer add);
listpointer insert_at_tail(listpointer target,listpointer add);

int main(){
	listpointer lp,temp;
	int i;
	lp=create(0);
	trace(lp);
	for(i=1;i<10;i++){
		insert_at_tail(lp,create(i));
		trace(lp);
	}
	system("pause");
}

void trace(listpointer first){
	for(;first;first=first->link){
		printf("(%d)->",first->data);
	}
	printf("NULL\n");
}

listpointer create(int n){
	listpointer first;
	first=(listpointer)malloc(sizeof(listpointer));
	first->data=n;
	first->link=NULL;
	return first;
}

listpointer insert(listpointer target,listpointer add){
	add->link=target->link;
	target->link=add;
}

listpointer insert_at_tail(listpointer target,listpointer add){
	for(;target->link!=NULL;target=target->link);
	add->link=target->link;
	target->link=add;
}

