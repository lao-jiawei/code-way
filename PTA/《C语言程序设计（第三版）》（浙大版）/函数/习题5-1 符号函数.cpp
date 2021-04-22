#include<stdio.h>

int sign(int x); //函数声明。

int main()
{
	int x;

	scanf("%d",&x);
	printf("sign(%d) = %d\n",x,sign(x));

	return 0;
} 

int sign(int x)
{
	if(x==0)           //为什么要用“==”
		return 0;
	else if(x>1){
		return 1;
	}	
	else
		return -1;
}