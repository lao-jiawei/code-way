#include<stdio.h>
int main()
{
	int N;
	double sum=0;
	scanf("%d",&N);
	if(N>=0)
	{	
		for(int i=1;i<=N+1;)
		{
			sum+=1.0/i;
			i=i+2;	
		
		}//for
	}else{
		printf("ERROR");
		return 0;
	}
	printf("sum = %.6f\n",sum);
	return 0;
}