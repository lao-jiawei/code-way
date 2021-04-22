#include <stdio.h>
#include <math.h>
int main(){
	double sum,eps;
	sum=0;
	scanf("%lf",&eps); //double，双精度浮点型，对应%lf
	int i=1;
	sum=1.0/i+sum;
	
	for(;fabs(1.0/i)>eps;){	//fabs函数求绝对值
		i=i+3;	
		if(i%2==1){
			sum=1.0/i+sum;
		}else{
			sum=-1.0/i+sum;
		}
	}
			
	printf("sum = %.6lf",sum);//double 类型使用了%f格式，会导致输入值错误
}
 