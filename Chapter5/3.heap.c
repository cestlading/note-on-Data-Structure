#include <stdio.h>
#include <stdlib.h>

#define SIZE 100

typedef struct {
	int key;
}element;

element heap[SIZE];
int n=0;

void push(element item,int *n);
element pop(int *n);

int main(){
	int i;
	element e[5],pop_out;
	e[0].key=20;
	e[1].key=15;
	e[2].key=2;
	e[3].key=14;
	e[4].key=10;
	
	for(i=0;i<5;i++){
		push(e[i],&n);
	}
	for(i=0;i<5;i++){
		pop_out=pop(&n);
		printf("%2d ",pop_out.key);
	}
	printf("\n");

	system("pause");
}

void push(element item,int *n){
	int i;
	if((*n)==SIZE-1){
		printf("The heap is full\n");
		system("pause");
	}
	i=++(*n);
	while((i!=1)&&(item.key>heap[i/2].key)){
		heap[i]=heap[i/2];
		i/=2;
	}
	heap[i]=item;
}


element pop(int *n){
	int parent,child;
	element item,temp;
	if(!(*n)){
		printf("The heap is empty\n");
		system("pause");
	}
	item=heap[1];
	temp=heap[(*n)--];
	parent=1;
	child=2;
	while(child<=(*n)){
		if(child<(*n)&&(heap[child].key<heap[child+1].key))
			child++;
		if(temp.key>=heap[child].key)
			break;
		heap[parent]=heap[child];
		parent=child;
		child*=2;
	}
	heap[parent]=temp;
	return item;
}