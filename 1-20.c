#include<stdio.h>
double f(int n,double a[],double x)
{int i;
double p=a[n];
for(i=n;i>0;i--)
	p=a[i-1]+x*p;
return p;}


int main
{int N;
double A[];
double X;
printf("输入多项式的最高,幂底数x:");
scanf("%d%f",&N,&X);
printf("输入系数：");
gets(A);
f(N,A,X);}