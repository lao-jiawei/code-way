#include<stdio.h>
main()
{
	float fahr;

	printf("******ÎÂ¶È×ª»»±í******\n");
	for(fahr = 300;fahr>=0;fahr--)
	{
		printf("%3.0f %6.1f\n",fahr,(5.0/9.0)*(fahr-32));
	}//for
}//main