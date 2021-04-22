#include<stdio.h>
main()
{
	int x,y,fac;
	printf("请输入两个整数：");
	scanf("%d%d",&x,&y);
	fac = x*y;
	printf("两个数的积 %d * %d = %d\n",x,y,fac);
}