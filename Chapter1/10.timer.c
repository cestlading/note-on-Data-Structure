/*------------------------------------------*/
/*              By Jason Ding               */
/*       E-mail:cestlading@gmail.com        */
/*   Fundamentals of Data Structures in C   */
/*------------------------------------------*/
//Compiler:Microsoft Visual C++ 2010 Express
#include <stdio.h>
#include <stdlib.h>
#include <time.h>


long long f_i(int n);
long long f_r(int n);

int main(){
	
	clock_t start1,start2;
	clock_t end1,end2;
	long long f1,f2;
	double total1,total2;
	start1=clock();
	printf("start_t = %ld\n", start1);
	f1 = f_i(1000);
	end1=clock();
	printf("end_t = %ld\n", end1);
	total1 = (double)(end1 - start1) / CLOCKS_PER_SEC;
	printf("CPU time：%f\n", total1);
	
	start2=clock();
	printf("start_t = %ld\n", start2);
	f2 = f_r(40);
	end2=clock();
	printf("end_t = %ld\n", end1);
	total2 = (double)(end2 - start2) / CLOCKS_PER_SEC;
	printf("CPU time：%f\n", total2);
	
	
	system("pause");
}

long long f_i(int n)
{
	int i;
	long v1 = 0;
	long v2 = 1;
	long result = n;
	for (i = 2; i <= n; ++i)
	{
		result = v2 + v1;
		v1 = v2;
		v2 = result;
	}
	return result;
}

long long f_r(int n)
{
	if( n==1 || n==2 )
		return 1;
	if( n >= 3 ){
		//printf("%lf\n",clock());
		return f_r(n-1)+f_r(n-2);

	}
}