#include<stdio.h>
int fact(int n) //ÀÛ³Ëº¯Êı
{
	int sum=1;
	for(int i=1;i<=n;i++)
	{
		sum*=i;
	}//for
	return sum;
}//Fact

int main()
{
	int n;
	int sum=0;
	scanf("%d",&n);
	if(n<=12)
	{
		for(int i=1;i<=n;i++)
		{
			sum+=fact(i);
		}
		printf("%d\n",sum);
	}//if
	return 0;
}