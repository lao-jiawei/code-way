//3.2.1 数制转换
/*头文件*/
#include<stdio.h>
#include<stdlib.h>
#include"Stack.h" //栈实现程序
/*转换函数*/
void conversion(int N,int h) //将十进制数N转换成h进制
{
	SeqStack* S; //声明栈
	ElemType e; 
	S = (SeqStack*)malloc(sizeof(SeqStack));//分配地址
	if (!S) 
	{
		printf("内存分配错误！\n");
		return ;
	}
	InitStack(S); //初始化栈
	while (N)
	{
		Push(S, N % h);
		N = N / h;
	}
	printf("转换结果为：");
	while (!EmptyStack(S)) 
	{
		Pop(S, &e);
		printf("%d", e);
	}
}

/*主函数*/
void main() 
{
	int N, m; //分别用于存放要转换的十进制和要转化换的进制
	printf("请输入要转换的十进制数："); 
	scanf("%d", &N);
	printf("请输入要转换的进制：");
	scanf("%d", &m);
	conversion(N, m); //调用进制转换函数
}