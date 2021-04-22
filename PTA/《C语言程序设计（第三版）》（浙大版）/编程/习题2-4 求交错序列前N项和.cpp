#include<stdio.h>
int main()
{
	int n,f=1,j=1;
	double sum=1;
	scanf("%d",&n);
	for(int i=2;i<=n;i++)
	{
			f=-f;
			j=j+2;
			sum+=1.0*f*i/j;
	}//for
	printf("%.3f\n",sum);
	return 0;
}
/*
2/3  3/
1 2 3 4 5 6
1 3 5 7 9 11
 2 2 2 2 2
*/