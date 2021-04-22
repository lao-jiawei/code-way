#include<stdio.h>
int main()
{
	//фад╩иоотй╬╡к╣╔
	printf("[1] apple\n");
	printf("[2] pear\n");
	printf("[3] orange\n");
	printf("[4] grape\n");
	printf("[0] exit\n");

	int n,i;
	for(i=1;i<=5;i++)
	{
		scanf("%d",&n);
		if(n==0)
		{
			break;
		}//if
			switch(n)
			{
			case 1:printf("price = 3.00\n");break;
			case 2:printf("price = 2.50\n");break;
			case 3:printf("price = 4.10\n");break;
			case 4:printf("price = 10.20\n");break;	
			default: printf("price = 0.00\n");
			}//switch
	}//for
	return 0;
}
