#include<stdio.h>
main()
{
	float fahr,celsius;
	int lower,upper,step;

	lower = 0;
	upper = 300;
	step =20;

	celsius = lower;
	printf("******摄氏度温度转换为相应华氏温度的转化表******\n");
	while(celsius <= upper)
	{
		fahr = celsius/(8.0/9.0)+32;
		printf("%6.1f %3.0f\n",celsius,fahr);
		celsius = celsius + step;
	}//while
}//main