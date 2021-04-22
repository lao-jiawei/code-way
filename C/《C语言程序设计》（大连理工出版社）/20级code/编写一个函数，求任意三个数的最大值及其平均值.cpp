#include<stdio.h>
double getmaxandaverage(double a, double b,double c,double *ave,double *max);
main()
{
	double x,y,z,average,max;
	scanf("%lf%lf%lf",&x,&y,&z);
	getmaxandaverage(x,y,z,&average,&max);
	printf("max=%lf,average=%lf\n",max,average);
}//main

double getmaxandaverage(double a, double b,double c,double *ave,double *max)
{
	double t;
	*ave=(a+b+c)/3;//求平均值，通过指针将其保存到main中的average
	t=a;
	if(t<b){t=b;}
	if(t<c){t=c;}
	*max=t;
	return 0;
}