#include<stdio.h>
int main()
{
	int n,f,d,i;
	double sum,item;
	scanf("%d",&n);
	f=1;
	d=1;
	sum=0;
	for(i=1;i<=n;i++)
	{
		item=f*1.0/d;
		sum+=item;
		f=-f;  //实现每个元素一正一负交替的
		d=d+3;
	}
	printf("sum = %.3f\n",sum);
	return 0;
}

