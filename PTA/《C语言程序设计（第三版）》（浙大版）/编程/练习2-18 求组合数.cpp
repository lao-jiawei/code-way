#include<stdio.h>
#include<math.h>

double Fact(int n){  //Fact函数的定义（累乘函数）
    int i;
    double sum=1;
    for(i=1;i<=n;i++){
        sum=sum*i;
    }
    return sum;
}

int main() //主函数
{
	int m,n;
	double up,down,result;
	scanf("%d %d",&m,&n);
	if(m<=n)
	{
		up=Fact(n); //求分子
		down=Fact(m)*Fact(n-m); //求分母
		result= 1.0*up/down;
	}else{
		return 0;
	}
	printf("result = %.0f\n",result);
	return 0;

}