#ifndef _STACK_H_ //定义头文件开始
#define _STACK_H_  //定义头文件的名称
#include<stdio.h>
#include<stdlib.h>
/*常量定义*/
#define OK 0  //成功执行
#define Err_Memory -1 //内存分配错误
#define Err_InvalidParam -2 //输入参数无效
#define Err_Overflow -3 //溢出错误
#define Err_IllegalPos -4 //非法位置
#define Err_NoResult -5 //无返回结果或返回结果为空
#define Stack_Init_Size 100 //栈的初始大小
#define Stack_Increment 10 //栈的存储空间分配增量

/*数据类型*/
typedef int ElemType; //ElemType为栈的元素类型
typedef struct  //栈结构
{
	ElemType* stackdata; //栈中数据元素存储空间（一维数组）的起始地址
	int top; //栈顶指针，实际上是栈顶位置的数组下标
	int stacksize; //栈当前的可用大小，初始大小由Stack_Init_Size指定
}SeqStack;

typedef int Status; //函数返回状态

/*以下是需要用到的栈的基本操作的实现函数*/
Status InitStack(SeqStack* S) //初始化链表
{
	if (!S) //if(!S)等价于if(S==0)
	{
		return Err_InvalidParam; //顺序栈无效
	}
	/*为stackdata分配内存空间*/
	S->stackdata = (ElemType*)malloc(Stack_Init_Size * sizeof(ElemType)); //从栈的初始大小中分配当前栈的大小
	if (!S->stackdata) //等价于if(S->stackdata==0)
	{
		return Err_Memory;//内存分配错误
	}
	S->top = 0; //初始化栈顶指针为0
	S->stacksize = Stack_Init_Size; //设置栈当前大小
	return OK;
}

int EmptyStack(SeqStack* S)  //判断是否为空栈
{
	if (!S)
	{
		return Err_InvalidParam; //顺序表无效
	}
	return (S->top == 0); //top等于0为空，返回True，否则返回False
}

Status GetTop(SeqStack* S, ElemType* e) //获取栈顶元素,将其存入e
{
	if (!S) //如果S不存在
	{
		return Err_InvalidParam; //顺序栈无效
	}
	if (S->top == 0)//如果栈顶为0
	{
		return Err_NoResult; //栈为空
	}
	*e = S->stackdata[S->top - 1]; //获取栈顶元素
	return OK;
}

Status Push(SeqStack* S, ElemType e)  //读取：（调用顺序栈S，入栈元素） //元素e入栈
{
	StackNode* p;
	if (!S) //判断顺序栈是否存在
	{
		return Err_InvalidParam; //顺序栈无效
	}
	if (S->top == S->stacksize) //栈满，追加存储空间
	{
//		newstack = (ElemType*)malloc(S->stackdata, (S->stacksize + Stack_Increment) * sizeof(ElemType));  //？
	}
	if (!newstack)   //？
	{
		return Err_Memory; //内存分配错误
	}
	S->stackdata = newstack;
//	S->top = S->stackdata + S->stacksize; //修改当前栈的可用空间大小
	S->stackdata[S->top++] = e; //将元素e存入栈顶，然后将top加1
	return OK;
}

Status Pop(SeqStack* S, ElemType* e) //读取：（调用顺序栈S，栈顶元素） //栈顶元素出栈，存入e中
{
	if (!S) //判断顺序栈是否存在
	{
		return Err_InvalidParam;//顺序栈无效
	}
	if (S->top == 0)
	{
		return Err_NoResult; //栈为空
	}
	*e = S->stackdata[--S->top];//将top减1，然后将栈顶元素存入e中
	return OK;
}
#endif //头文件结束
