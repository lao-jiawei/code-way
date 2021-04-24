//4.4.1 栈的顺序存储结构

//顺序栈：顺序存储的栈
//top：(1)一个变量来指示栈顶元素在数字组中的位置（等同于游标卡尺的游标）
//     (2)栈顶的top可以变大变，但无论如何游标不能超出尺的长度。
//StackSize:(1)存储栈的长度，则栈顶位置top必须小于StackSize
//          (2)当栈顶存在一个元素时，top等于0，因此通常把空栈的判定条件为top等于-1

//栈的结构定义
//#define ERROR 0
//#define OK 1
//#define MAXSIZE 5
//typedef int SElemType;/*SElemType类型根据实际情况而定，这里假设为int*/
//typedef struct 
//{
//	SElemType data[MAXSIZE];
//	int top; /*用于栈顶指针*/
//}SqStack;

//4.4.2 栈的顺序存储结构——进栈操作
//进栈操作push，代码
/*插入元素e为新的栈顶元素*/
//Status Push(SqStack* S, SElemType e)
//{
//	if (S->top == MAXSIZE) /*栈满*/
//	{
//		return ERROR;
//	}
//	S->top++; /*栈顶指针加一*/
//	S->data[S->top] = e; /*将新插入元素赋值给栈顶空间*/
//	return OK;
//}

//4.4.3 栈的顺序存储结构——出栈操作
/*若栈不空，则删除S的栈顶元素，用e返回其值，并返回OK；否则返回ERROR*/
//Status Pop(SqStack* S, SElemType* e)
//{
//	if (S->top == -1)   //栈为空栈
//	{
//		return ERROR;
//	}
//	*e = S->data[S->top]; /*将要删除的栈顶元素赋值给e*/
//	S->top--; /*栈顶指针减一*/
//	return OK;
//}