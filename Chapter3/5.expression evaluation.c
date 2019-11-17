/*------------------------------------------*/
/*              By Jason Ding               */
/*       E-mail:cestlading@gmail.com        */
/*   Fundamentals of Data Structures in C   */
/*------------------------------------------*/
//Compiler:Microsoft Visual C++ 2010 Express
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#define MAX_STACK_SIZE 101
/* in-stack precedence */
int isp[] = {0, 19, 12, 12, 13, 13, 13, 0};
/* incoming precedence  */
int icp[] = {20, 19, 12, 12, 13, 13, 13, 0};


char infix_exp[MAX_STACK_SIZE]="5+(4/2)*(8-1)-9";
char postfix_exp[MAX_STACK_SIZE]= "\0";

/* global stack */
char Stack[MAX_STACK_SIZE];
int Top=-1;
/* Push elemnt to stack */
void push( char item) {
	if ( Top >= MAX_STACK_SIZE-1) {
		printf("STACK is full\n");
		exit(1);
	}
	Stack[++Top] = item;
}
/* Pop element from stack */
char pop() {
	if (Top == -1 ) {
		printf("STACK is empty\n");
		exit(1);
	}
	return Stack[Top--];	
}
typedef enum {lparen, rparen, plus, minus, times, divide, mod, eos, operand} precedence;
// return Token's precendence
precedence getPrecedence(char token ) {
	switch (token ) {
	case  '(' : return lparen;
	case  ')' : return rparen;
	case  '+' : return plus;
	case  '-' : return minus;
	case  '/' : return divide;
	case  '*' : return times;
	case  '%' : return mod;
	case  '\0': return eos;
	default   : return operand;
	}
}

void check_exp(char x[]) {
	int i =0;
	int sdigit =0;
	while ( x[i] != '\0' ) {
		if ( x[i] >= '0' && x[i] <= '9' )
			if (sdigit) {printf("Cannot accept double-digit operand\n"); exit(1);}
			else sdigit =1;
		else if ( x[i] == '(' || x[i] == ')' || x[i] == '+' ||
			x[i] == '-' || x[i] =='*' || x[i] == '/' || x[i] == '%')
			sdigit =0; 
		else { 
			printf("Error input expression\n");
			exit(1);
		}
		i++;
	}
}

void str_attach(char y[], char x) {

	int i =0;
	char tmp;

	for ( tmp = y[i]; tmp != '\0' ; tmp = y[++i]) ;
	y[i++] = x;
	y[i] = '\0';
	return;
}

void postfix(void) {
	char token, tmpc;
	int i=0;
	push('\0');
	for ( token = infix_exp[i]; token != '\0' ; token = infix_exp[++i]){
		if ( token >= '0' && token <= '9' ) { // a single-digit operand
			str_attach(postfix_exp, token);
		}
		else if ( token == ')' ) {
			while ( (tmpc= pop()) != '(') 
				str_attach(postfix_exp, tmpc);
		}
		else {

			while ( isp[ getPrecedence( Stack[Top]) ] >= icp[ getPrecedence(token) ] )
				str_attach(postfix_exp, pop());
			push(token);
		}
	}
	do { 
		token = pop();
		str_attach(postfix_exp, token);
	} while ( token != '\0');
}

int stack_int[MAX_STACK_SIZE];
int top_int = -1;
void push_int( char item) {
	if ( top_int >= MAX_STACK_SIZE-1) {
		printf("int STACK is full\n");
		exit(1);
	}
	Stack[++top_int] = item;
}
int pop_int() {
	if (top_int == -1 ) {
		printf("int STACK is empty\n");
		exit(1);
	}
	return Stack[top_int--];	
}

int eval_postfix(char p[]){
	char token;
	precedence op;
	int i=0,j;
	int operand_1,operand_2,temp;
	for ( token = p[i]; token != '\0' ; token = p[++i]){
		if ( token >= '0' && token <= '9' ) {
			push_int((int)token-48);//minus for ASCII code,such as '0' = 48 in int type
		}
		else{
			op = getPrecedence(token);
			operand_2 = pop_int();
			operand_1 = pop_int();
			if(op == plus){
				temp = operand_1 + operand_2;// +
			}else if(op == minus){
				temp = operand_1 - operand_2;// -
			}else if(op == divide){
				temp = operand_1 / operand_2;// /
			}else if(op == times){
				temp = operand_1 * operand_2;// *
			}else if(op == mod){
				temp = operand_1 % operand_2;// %
			}
			push_int(temp);
		}
	}
	return pop_int();
}

int main(){
	printf("Please input an infix-expression\n");
	scanf("%s", infix_exp);
	check_exp(infix_exp);
	postfix();
	printf("\n%s\n", postfix_exp);
	printf("%d", eval_postfix(postfix_exp));
	getch(); // quit if any key is pressed
}

