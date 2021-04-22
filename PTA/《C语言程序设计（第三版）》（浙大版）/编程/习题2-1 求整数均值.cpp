#include<stdio.h>
int main()
{
	int a,b,c,d;
	int sum=0;
	float average =0;
	scanf("%d %d %d %d",&a,&b,&c,&d);
	sum=a+b+c+d;
	average=sum*1.0/4;
	printf("Sum = %d; Average = %.1f\n",sum,average);
	return 0;
}