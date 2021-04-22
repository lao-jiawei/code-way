#include<stdio.h>
int main()
{
	int endyear,i,n=0;
	scanf("%d",&endyear);
	if(endyear<=2000 || endyear>2100)
	{
		printf("Invalid year!\n");
	}else{
		for(i=2001;i<=endyear;i++)
		{
			if((i%4==0 && i%100!=0)||i%400==0)
			{
				n++;
				printf("%d\n",i);
			}//if
		}//for
		if(n==0)
		{
			printf("None\n");
		}	
	}
	return 0;
}
