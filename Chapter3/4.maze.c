/*------------------------------------------*/
/*              By Jason Ding               */
/*       E-mail:cestlading@gmail.com        */
/*   Fundamentals of Data Structures in C   */
/*------------------------------------------*/
//Compiler:Microsoft Visual C++ 2010 Express
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define FALSE 0
#define TRUE 1
#define EXIT_ROW 4
#define EXIT_COL 4

typedef struct{
	short int vert;
	short int horiz;
}offsets;

offsets move[8];

int vert(int n){
	if(n==0||n==1||n==7)
		return -1;
	else if(n==2||n==6)
		return 0;
	else if(n==3||n==4||n==5)
		return 1;
}

int horiz(int n){
	if(n==5||n==6||n==7)
		return -1;
	else if(n==0||n==4)
		return 0;
	else if(n==1||n==2||n==3)
		return 1;
}

typedef struct{
	short int row;
	short int col;
	short int dir;
}element;

element stack[36];
int top=0;
element pop(){
	element temp;
	if(top==-1){
		printf("stack is empty");
		system("pause");
		exit(0);
	}else{
		temp=stack[top--];
		printf("pop()=>(%d,%d,%d)\n",temp.row,temp.col,temp.dir);
		return temp;
	}
}
void push(element item){
	if(top==36){
		printf("stack is full");
		system("pause");
		exit(0);
	}else{
		printf("push()=>(%d,%d,%d)\n",item.row,item.col,item.dir);
		stack[++top]=item;
	}
}

int main(){

	int i,j;
	int maze[6][6]={{1,1,1,1,1,1},
	{1,0,0,0,0,1},
	{1,0,1,0,1,1},
	{1,0,1,1,1,1},
	{1,1,0,0,0,1},
	{1,1,1,1,1,1}};
	int mark[6][6]={{0,0,0,0,0,0},
	{0,0,0,0,0,0},
	{0,0,0,0,0,0},
	{0,0,0,0,0,0},
	{0,0,0,0,0,0},
	{0,0,0,0,0,0}};
	element position;


	int row,col,nextRow,nextCol,dir,found=FALSE;

	stack[0].col=1,stack[0].row=1,stack[0].dir=0;
	mark[1][1]=1;
	for(i=0;i<8;i++){
		move[i].vert=vert(i);
		move[i].horiz=horiz(i);
	}
	/*
	printf("   dir|  vert| horiz\n");
	for(i=0;i<8;i++){
	printf("%6d|%6d|%6d\n",i,move[i].vert,move[i].horiz);
	}*/

	while(top>-1&&!found){
		position = pop();
		row = position.row;
		col = position.col;
		dir = position.dir;
		while(dir<8&&!found){
			nextRow=row+move[dir].vert;
			nextCol=col+move[dir].horiz;
			if(nextRow==EXIT_ROW&&nextCol==EXIT_COL)
				found=TRUE;
			else if(!maze[nextRow][nextCol]&&!mark[nextRow][nextCol]){
				mark[nextRow][nextCol]=1;
				position.row=row;
				position.col=col;
				position.dir=++dir;
				push(position);
				row=nextRow;
				col=nextCol;
				dir=0;
			}else
				++dir;
		}

	}

	if(found){
		printf("the path is:\n");
		printf("row  col\n");
		for(i=0;i<=top;i++)
			printf("%2d%5d\n",stack[i].row,stack[i].col);
		printf("%2d%5d\n",row,col);
		printf("%2d%5d\n",EXIT_ROW,EXIT_COL);
	}else
		printf("the maze does not have a path\n");


	system("pause");
}