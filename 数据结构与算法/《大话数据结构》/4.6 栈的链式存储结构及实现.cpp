//4.6.1 栈的链式存储结构

//链栈：栈的链式存储结构
//对于链栈来说，基本不存在栈满的情况

//链栈的结构代码：
#include"stdio.h"
#include"stdlib.h"
#define ERROR 1
#define OK 0
typedef int SElemType;
typedef struct StackNode  //结点
{
	SElemType data;   //设置数据域
	struct StackNode* next; //指针域
}StackNode,*LinkStackPtr; //定义一个指向结构体的指针LinkStackPtr

typedef struct LinkStack  //链栈
{
	LinkStackPtr top; //栈顶指针
	int count;      //设置一个整数count来记录结点数
}LinkStack;

//4.6.2 栈的链式存储结构——进栈操作
/*插入元素e为新的栈顶元素*/
Status Push(LinkStack* S,SElemType e)
{
	LinkStackPtr s = (LinkStackPtr)malloc(sizeof(StackNode)); //指针s分配空间
	s->data = e; //将e赋值给s结点的数据域
	s->next = S->top; /*把当前的栈顶元素赋值给新结点的直接后继，如图①*/  //电子版教材P122
	S->top = s;/*将新的结点s赋值给栈顶指针，如图②*/ //电子版教材P122
	S->count++;
	return OK;
}

//4.6.3 栈的链式存储结构——出栈操作
/*若栈不空，则删除S的栈顶元素，用e返回其值，并返回OK；否则返回ERROR*/
Status Pop(LinkStack* S, SElemType* e)
{
	LinkStackPtr p;  //设置指针p
	if (StackEmpty(*S)) //如果栈S为空，返回ERROR
	{
		return ERROR;
	}
	*e = S->top->data; //用e来保存栈顶元素
	p = S->top; /*将栈顶结点赋值给p，如图③*/ //电子版教材P123
	S->top = S->top->next; /*使得栈顶指针下移一位，指向后一结点，如图④*///电子版教材P123
	free(p); /*释放结点p*/
	S->count--; //结点数减一
	return OK;
}