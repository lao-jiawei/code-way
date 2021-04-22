#include<stdio.h>
int main()
{
	int n,i,A,B,C,D,E;
	int score;
	A=B=C=D=E=0;
	scanf("%d",&n);
	for(i=1;i<=n;i++)
	{
		scanf("%d",&score);
		if(score>=90){
			A++;
		}else if(score>=80){
			B++;
		}else if(score>=70){
			C++;
		}else if(score>=60){
			D++;
		}else{
			E++;
		}
	}//for
	printf("%d %d %d %d %d\n",A,B,C,D,E);
	return 0;
}