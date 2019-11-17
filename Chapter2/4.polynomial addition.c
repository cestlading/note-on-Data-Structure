/*------------------------------------------*/
/*              By Jason Ding               */
/*       E-mail:cestlading@gmail.com        */
/*   Fundamentals of Data Structures in C   */
/*------------------------------------------*/
//Compiler:Microsoft Visual C++ 2010 Express
#include <stdio.h>
#include <stdlib.h>

void pol_print(int pol[][2],int len);

int main(){

	int polA[5][2]={{3,3000},{2,2000},{1,0}};
	int polB[5][2]={{-3,3000},{1,4},{10,3},{3,2},{1,0}};
	int polC[10][2];
	int lenA = 3;
	int lenB = 5;
	int lenC = 0;
	int iA=0,iB=0,iC=0;
	int expA,expB;

	while(1){
		if(iA==lenA&&iB==lenB)
			break;
		else{
			if(polA[iA][1]==polB[iB][1]){
				if(polA[iA][0]+polB[iB][0]!=0){
					polC[iC][0]=polA[iA][0]+polB[iB][0];
					polC[iC][1]=polA[iA][1];
					iA++;
					iB++;
					iC++;
					lenC++;
				}else{
					iA++;
					iB++;
				}
			}else if(polA[iA][1]>polB[iB][1]){
				polC[iC][0]=polA[iA][0];
				polC[iC][1]=polA[iA][1];
				iA++;
				iC++;
				lenC++;
			}
			else if(polA[iA][1]<polB[iB][1]){
				polC[iC][0]=polB[iB][0];
				polC[iC][1]=polB[iB][1];
				iB++;
				iC++;
				lenC++;
			}
		}
	}
	printf("polA:");
	pol_print(polA,lenA);
	printf("polB:");
	pol_print(polB,lenB);
	printf("polC:");
	pol_print(polC,lenC);
	system("pause");
}

void pol_print(int pol[][2],int len){
	int i;
	for(i=0;i<len;i++){
		if(i!=len-1){
			printf("%d*x^%d+",pol[i][0],pol[i][1]);
		}else{
			printf("%d*x^%d\n",pol[i][0],pol[i][1]);
		}
	}
}