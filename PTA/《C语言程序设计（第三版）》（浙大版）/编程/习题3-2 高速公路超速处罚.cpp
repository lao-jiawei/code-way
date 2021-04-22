#include<stdio.h>
int main()
{
	int speed,limit;
	double max1,max2,exceed;
	max1=max2=exceed=0;
	scanf("%d %d",&speed,&limit);
	exceed=(speed-limit)*1.0/limit;
	if(exceed*100>=50)
	{
		printf("Exceed %0.f%%. License Revoked\n",exceed*100); //%%才输出百分号
	}else if(exceed*100>=10 && exceed*100<50){
		printf("Exceed %0.f%%. Ticket 200\n",exceed*100);
	}else{
		printf("OK\n");
	}
	return 0;
}