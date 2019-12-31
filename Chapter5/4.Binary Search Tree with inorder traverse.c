#include <stdio.h>
#include <stdlib.h>

typedef struct node *treepointer;
typedef struct node{
	int key;
	treepointer leftchild,rightchild;	
};

void inorder(treepointer ptr);
treepointer copy(treepointer original);
treepointer search(treepointer root,int k);
treepointer iter_search(treepointer root,int k);

int main(){
	treepointer t1,t2,t3,t4,t5,t6,t7;
	treepointer root_copy;
	treepointer search_result;
	t1=(treepointer)malloc(sizeof(treepointer));
	t2=(treepointer)malloc(sizeof(treepointer));
	t3=(treepointer)malloc(sizeof(treepointer));
	t4=(treepointer)malloc(sizeof(treepointer));
	t5=(treepointer)malloc(sizeof(treepointer));
	t6=(treepointer)malloc(sizeof(treepointer));
	t7=(treepointer)malloc(sizeof(treepointer));
	t1->key=10;
	t1->leftchild=t2;
	t1->rightchild=t3;
	t2->key=5;
	t2->leftchild=t4;
	t2->rightchild=t5;
	t3->key=15;
	t3->leftchild=t6;
	t3->rightchild=t7;
	t4->key=1;
	t4->leftchild=NULL;
	t4->rightchild=NULL;
	t5->key=7;
	t5->leftchild=NULL;
	t5->rightchild=NULL;
	t6->key=12;
	t6->leftchild=NULL;
	t6->rightchild=NULL;
	t7->key=17;
	t7->leftchild=NULL;
	t7->rightchild=NULL;
	
	
	printf("inorder:\n");
	inorder(t1);
	printf("\n");
	root_copy=copy(t1);
	printf("inorder of copy one:\n");
	inorder(root_copy);
	printf("\n");

	search_result=search(t1,12);
	if(search_result)
		printf("%d\n",search_result->key);
	
	search_result=search(t1,100);
	if(!search_result)
		printf("the key is nowhere to be found\n");

	search_result=search(t1,17);
	if(search_result)
		printf("%d\n",search_result->key);
	
	search_result=search(t1,0);
	if(!search_result)
		printf("the key is nowhere to be found\n");

	system("pause");
}

treepointer copy(treepointer original){
	treepointer temp;
	if(original){
		temp=(treepointer)malloc(sizeof(treepointer));
		temp->leftchild=copy(original->leftchild);
		temp->rightchild=copy(original->rightchild);
		temp->key=original->key;
		return temp;
	}
	return NULL;
}

void inorder(treepointer ptr){
	if(ptr){
		inorder(ptr->leftchild);
		printf("%d ",ptr->key);
		inorder(ptr->rightchild);
	}
}

treepointer search(treepointer root,int k){
	if(!root)
		return NULL;
	if(k==root->key)
		return root;
	if(k<root->key)
		return search(root->leftchild,k);
	return search(root->rightchild,k);
}


treepointer iter_search(treepointer root,int k){
	while(root){
		if(k==root->key)
			return root;
		if(k<root->key)
			root=root->leftchild;
		if(k>root->key)
			root=root->rightchild;
	}
}

