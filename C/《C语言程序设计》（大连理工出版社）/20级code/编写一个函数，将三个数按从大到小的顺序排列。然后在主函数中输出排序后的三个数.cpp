//不用指针的
/*
#include<stdio.h>
void pt(int a,int b,int c);
main()
{
	int a,b,c,t;
	printf("请输入三个数：");
	scanf("%d%d%d",&a,&b,&c);
	printf("三个数按照由大到小排列为：");
	pt(a,b,c);
}

void pt(int a,int b,int c)
{
	int t;
	while(a<b || b<c )
	{
		if(a<b)
		{
			t=a;
			a=b;
			b=t;
		}else if(a<c){
			t=a;
			a=c;
			c=t;
		}else if(b<c){
			t=b;
			b=c;
			c=t;
		}//if
	}//while
	printf("%d %d %d\n",a,b,c);
}*/

//用指针的
/*
#include<stdio.h>
void pt(int a,int b,int c,int *A,int *B,int *C);
main()
{
	int a,b,c,A,B,C;
	printf("请输入三个数：");
	scanf("%d%d%d",&a,&b,&c);
	printf("三个数按照由大到小排列为：");
	pt(a,b,c,&A,&B,&C);
	printf("%d %d %d\n",A,B,C);
}

void pt(int a,int b,int c,int *A,int *B,int *C)
{
	int t;
	while(a<b || b<c )
	{
		if(a<b)
		{
			t=a;
			a=b;
			b=t;
		}else if(a<c){
			t=a;
			a=c;
			c=t;
		}else if(b<c){
			t=b;
			b=c;
			c=t;
		}//if
	}//while
	*A=a;*B=b;*C=c;
}*/