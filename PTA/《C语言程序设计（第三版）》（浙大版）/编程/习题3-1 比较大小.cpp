#include<stdio.h>
int main()
{
	int a[3],i,min;
	for(i=0;i<3;i++)
	{
		scanf("%d",&a[i]);
	}//for
	for(i=1;i<3;i++)
	{
		min=a[0];
		if(a[0]>a[i])
		{
			min=a[i];
			a[i]=a[0];
			a[0]=min;
		}//if
	}//for
	if(a[1]>a[2])
	{
		min=a[2];
		a[2]=a[1];
		a[1]=min;
	}//if
	printf("%d->%d->%d\n",a[0],a[1],a[2]);
	return 0;
}

/*
a[0] a[1] a[2]
 8    4    2
 4    8    2

min=4   min
a[1]=8
a[0]=4

*/
