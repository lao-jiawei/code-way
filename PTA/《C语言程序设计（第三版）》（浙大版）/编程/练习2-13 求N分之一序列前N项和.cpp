#include<stdio.h>
int main()
{
	int N;
	double sum=0;
	scanf("%d",&N);
	for(int i=1;i<=N;i++)
	{
		sum+=1.0/i;
	}
	printf("sum = %.6f\n",sum);
	return 0;
}