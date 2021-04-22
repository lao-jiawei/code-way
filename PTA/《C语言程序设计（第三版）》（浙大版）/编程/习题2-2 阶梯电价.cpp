#include<stdio.h>
int main()
{
	int electricity;
	float cost;
	scanf("%d",&electricity);
	if(electricity<0)
	{
		printf("Invalid Value!\n");
	}else if(electricity<=50){
		cost=0.53*electricity;
		printf("cost = %.2f\n",cost);
	}else{
		cost=0.53*50+(electricity-50)*0.58;
		printf("cost = %.2f\n",cost);
	}//else
	return 0;
}