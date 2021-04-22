#include<stdio.h>
void pyramid( int n);

int main()
{
	int n;

	scanf("%d",&n);
	pyramid(n);

	return 0;
}

void pyramid(int n)             //定义金字塔函数
{
	for(int i=1;i<=n;i++)        //定义行
	{
		for(int j=n-i;j>0;j--)   //定义空格。所有的条件一定要与行联系。
		{
			printf(" ");
		}
	for(int k=1;k<=i;k++)        //定义输出的元素。所有的条件一定要与行联系
	{
		printf("%d ",i);		
	}
	printf("\n");
	}
}
