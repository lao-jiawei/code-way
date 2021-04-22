#include<stdio.h>
#include<math.h>
int main()
{
	int m,n;
	double sum=0;
	scanf("%d %d",&m,&n);
	if(m<=n)
	{
		for(m;m<=n;m++)
		{
			sum+=pow(m,2)+1.0/m;
		}//for
		printf("sum = %.6f\n",sum);
	}//if
	return 0;
}