#include<stdio.h>
#include<math.h>
int main()
{
	int n,i,d;
	scanf("%d",&n);
	for(i=0;i<=n;i++)
	{
		d=pow(3,i);
		printf("pow(3,%d) = %d\n",i,d);
	}//for
	return 0;
}