#include<stdio.h>
#include<math.h>
int main()
{
	float i,y;
	scanf("%f",&i);
	if(i<0){
		y=pow(i+1,2)+2*i+1.0/i;
	}else{
		y=pow(i,0.5);
	}
	printf("f(%.2f) = %.2f\n",i,y);
		return 0;
}