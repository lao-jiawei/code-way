#include <stdio.h>
#include <math.h>
int main()
{
	double mile;
	int wait;
	double sum = 0;
	scanf("%lf %d",&mile,&wait);
	if(mile<=3)
	{
		sum += 10;
	}else if(mile>3 && mile <=10)
	{
		sum += 10 + (mile-3)*2;
	}else{
		sum += 24 + (mile-10)*3;
	}
	if(wait >= 5)
	{
		sum += (wait/5) * 2;
	}
	printf("%.0f\n",sum);
	return 0;	
} 