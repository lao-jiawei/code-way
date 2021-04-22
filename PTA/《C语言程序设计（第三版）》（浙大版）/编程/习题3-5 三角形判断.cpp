#include <stdio.h>
#include <math.h> 
int main()
{
 	double x1,y1,x2,y2,x3,y3;
 	double a,b,c,L,A;
 	scanf("%lf %lf %lf %lf %lf %lf",&x1,&y1,&x2,&y2,&x3,&y3);
 	a=sqrt(pow((x1-x2),2)+pow((y1-y2),2) );
 	b=sqrt(pow((x1-x3),2)+pow((y1-y3),2) );
 	c=sqrt(pow((x3-x2),2)+pow((y3-y2),2) );
 	if((a+b)<=c||(a+c)<=b||(c+b)<=a){
 		printf("Impossible");
 	}else{
 		L=a+b+c;
 		A=sqrt(0.5*L*(0.5*L-a)*(0.5*L-c)*(0.5*L-b));
 		printf("L = %.2f, A = %.2f",L,A ); 
 	}	
    return 0;
}