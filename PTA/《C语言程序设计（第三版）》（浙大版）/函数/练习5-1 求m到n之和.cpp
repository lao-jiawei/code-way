#include<stdio.h>

int sum(int m,int n);

int main()
{
	int m,n;

	scanf("%d %d",&m,&n);
	printf("sum = %d\n",sum(m,n));

	return 0;
}

int sum(int x,int y)   //累加函数定义。
{
	int sum=0;         //累加sum一定要初始化。

	for(x;x<=y;x++)
	{
		sum += x;
	}

	return sum;
}