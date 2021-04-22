#include<stdio.h>
int main()
{
	int i;
	float lower,upper,c;

	scanf("%f %f",&lower,&upper);
	if(lower>upper || upper>100){
		printf("Invalid.\n");
	}else {
		printf("fahr celsius\n");
		for(i=lower;i<=upper;i+=2)
		{
			c=5.0*(i-32)/9;
			printf("%d%6.1f\n",i,c);
		}
	}
	return 0;
}
