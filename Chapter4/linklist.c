#include <stdio.h>
#include <stdlib.h>

typedef struct listnode *listpointer;
typedef struct listnode{
	int data;
	listpointer link;
};

int length(listpointer first){
	int i;
	for(i=0;first;first=first->link){
		i++;
	}
	return i;
}
int sum_even(listpointer first){
	int s;
	for(s=0;first;first=first->link){
		if(!(first->data%2)){
			s+=first->data;
		}
	}
	return s;
}
void trace(listpointer first){
	for(;first;first=first->link){
		printf("(%d)->",first->data);
	}
	printf("NULL\n");
}
void add_node(listpointer *first,listpointer newnode){
	listpointer temp=*first;
	if(newnode->data<(*first)->data){
		newnode->link = (*first);
		(*first) = newnode;
	}else{
		for(;temp;temp=temp->link){
			if((newnode->data>temp->data)&&(newnode->data<temp->link->data)){
				newnode->link=temp->link;
				temp->link = newnode;
			}
		}
	}
}

void add(listpointer *first,listpointer x){
	listpointer temp;
	temp=(listpointer)malloc(sizeof(listpointer));
	temp->data=50;
	if(*first){
		temp->link=(*first)->link;
		(*first)->link=temp;
	}
}

typedef struct node *nodepointer;
typedef struct node{
	nodepointer llink;
	int data;
	nodepointer rlink;
};
void trace_node_r(nodepointer first){
	for(;first;first=first->rlink){
		printf("(%d)->",first->data);
	}
	printf("NULL\n");
}
void trace_node_l(nodepointer first){
	for(;first;first=first->llink){
		printf("(%d)->",first->data);
	}
	printf("NULL\n");
}

void ddelete(nodepointer deleted){
	deleted->llink->rlink=deleted->rlink;
	deleted->rlink->llink=deleted->llink;m
}

int main(){

	int size,sum;
	listpointer n1,n2,n3,n4,n5,n6;
	nodepointer N1,N2,N3,N4,N5;
	n1=(listpointer)malloc(sizeof(listpointer));
	n2=(listpointer)malloc(sizeof(listpointer));
	n3=(listpointer)malloc(sizeof(listpointer));
	n4=(listpointer)malloc(sizeof(listpointer));
	n5=(listpointer)malloc(sizeof(listpointer));
	n6=(listpointer)malloc(sizeof(listpointer));
	n1->data=1;
	n1->link=n2;
	n2->data=2;
	n2->link=n3;
	n3->data=3;
	n3->link=n4;
	n4->data=7;
	n4->link=n5;
	n5->data=10;
	n5->link=NULL;
	n6->data=6;
	n6->link=NULL;

	N1=(nodepointer)malloc(sizeof(nodepointer));
	N2=(nodepointer)malloc(sizeof(nodepointer));
	N3=(nodepointer)malloc(sizeof(nodepointer));
	N4=(nodepointer)malloc(sizeof(nodepointer));
	N5=(nodepointer)malloc(sizeof(nodepointer));
	N1->llink=NULL;
	N1->data=1;
	N1->rlink=N2;
	N2->llink=N1;
	N2->data=2;
	N2->rlink=N3;
	N3->llink=N2;
	N3->data=3;
	N3->rlink=N4;
	N4->llink=N3;
	N4->data=4;
	N4->rlink=N5;
	N5->llink=N4;
	N5->data=5;
	N5->rlink=NULL;

	size = length(n1);
	printf("length:%d\n",size);
	sum = sum_even(n1);
	printf("even_sum:%d\n",sum);
	trace(n1);
	add_node(&n1,n6);
	trace(n1);
	printf("----------\n");
	trace_node_r(N1);
	trace_node_l(N5);
	ddelete(N3);
	trace_node_r(N1);
	trace_node_l(N5);
	system("pause");
}

