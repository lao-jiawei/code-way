#include<stdio.h>
int main()
{
	int num,sore,count=0;
	double sum=0,average=0;
	scanf("%d",&num);
	if(num<=0)
	{
		printf("average = 0.0\n");
		printf("count = 0\n");
		return 0;
	}else{
		for(int i=0;i<num;i++)
		{
			scanf("%d",&sore);
			sum+=sore;
			if(sore>=60)
			{
				count++;
			}//if
		}//for
		average =1.0*sum/num;
		printf("average = %.1f\n",average);
		printf("count = %d\n",count);
		return 0;
	}//else
}