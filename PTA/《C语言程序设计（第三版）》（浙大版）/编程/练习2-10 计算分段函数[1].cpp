#include <stdio.h>
 
int main ()
{
	double x,result;
	scanf("%lf",&x);
	if(x!=0){
		result=1/x;
	}else{
		result=0;
	}
	printf("f(%.1f) = %.1f",x,result);
		
	return 0;
}