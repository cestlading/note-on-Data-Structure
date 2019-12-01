#include <stdio.h>
#include <stdlib.h>

typedef struct node *treepointer;
typedef struct node{
	char data;
	treepointer leftchild,rightchild;	
};

void inorder(treepointer ptr){
	if(ptr){
		inorder(ptr->leftchild);
		printf("%c",ptr->data);
		inorder(ptr->rightchild);
	}
}

void preorder(treepointer ptr){
	if(ptr){
		printf("%c",ptr->data);
		preorder(ptr->leftchild);
		preorder(ptr->rightchild);
	}
}

void postorder(treepointer ptr){
	if(ptr){
		postorder(ptr->leftchild);
		postorder(ptr->rightchild);
		printf("%c",ptr->data);
	}
}

int main(){
	treepointer root,t1,t2,t3,t4,t5,t6,t7,t8;
	root=(treepointer)malloc(sizeof(treepointer));
	t1=(treepointer)malloc(sizeof(treepointer));
	t2=(treepointer)malloc(sizeof(treepointer));
	t3=(treepointer)malloc(sizeof(treepointer));
	t4=(treepointer)malloc(sizeof(treepointer));
	t5=(treepointer)malloc(sizeof(treepointer));
	t6=(treepointer)malloc(sizeof(treepointer));
	t7=(treepointer)malloc(sizeof(treepointer));
	t8=(treepointer)malloc(sizeof(treepointer));
	root->data='+';
	root->leftchild=t1;
	root->rightchild=t2;
	t1->data='*';
	t1->leftchild=t3;
	t1->rightchild=t4;
	t2->data='E';
	t2->leftchild=NULL;
	t2->rightchild=NULL;
	t3->data='*';
	t3->leftchild=t5;
	t3->rightchild=t6;
	t4->data='D';
	t4->leftchild=NULL;
	t4->rightchild=NULL;
	t5->data='/';
	t5->leftchild=t7;
	t5->rightchild=t8;
	t6->data='C';
	t6->leftchild=NULL;
	t6->rightchild=NULL;
	t7->data='A';
	t7->leftchild=NULL;
	t7->rightchild=NULL;
	t8->data='B';
	t8->leftchild=NULL;
	t8->rightchild=NULL;

	printf("inorder expression:\n");
	inorder(root);
	printf("\n");
	printf("preorder expression:\n");
	preorder(root);
	printf("\n");
	printf("postorder expression:\n");
	postorder(root);
	printf("\n");

	system("pause");
}