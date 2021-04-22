#include<stdio.h>
/*统计输入字符数；版本1*/
main()
{
	long nc;
	nc = 0;
	while(getchar()! =EOF)
	{	
		++nc;
	}//while
	printf("%ld\n",nc);
}//main