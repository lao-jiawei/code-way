#include<stdio.h>
#include<math.h>
int main()
{
	int n;
	double sum =0;
	scanf("%d",&n);
	for(int i=1;i<=n;i++)
	{
		sum+=sqrt(i); //sqrt(int n);求平方根函数
	}//for
	printf("sum = %.2f\n",sum);
	return 0;
}