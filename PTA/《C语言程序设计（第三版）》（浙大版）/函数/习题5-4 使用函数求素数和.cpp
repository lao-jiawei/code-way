#include <stdio.h>
#include <math.h>

int prime( int p );
int PrimeSum( int m, int n );

int main()
{
    int m, n, p;

    scanf("%d %d", &m, &n);
    printf("Sum of ( ");
    for( p=m; p<=n; p++ ) {
        if( prime(p) != 0 )
            printf("%d ", p);
    }
    printf(") = %d\n", PrimeSum(m, n));

    return 0;
}

//判断输入值是否为素数。
int prime( int p)
{
	int i ;
	if(p<=1){                //p为复数时，负数不是素数
		return 0;	
	}else if (p==2){         //p等于2时
		return 1;
	}else{                    
		for(i=2;i<=p/2;i++){        //p依次除于小于p的数
			if(p%i==0){            //如果能被整除，不是素数
				return 0;
			} else if(i>p/2){         //如果依次处于小于p的数，没有整除，是素数。
				return 1;	
			}
		}
	}
	return 1;

}

//函数返回区间内所有素数之和
int PrimeSum( int m, int n )
{
	int i,sum=0;
	for(i=m;i<=n;i++)
	{
		if(prime(i)!=0)
			sum+=i;
	}
	return sum;
}

