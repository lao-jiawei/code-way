//栈的缺点：必须事先确定数组存储空间的大小，万一不够用力，就需要编程手段来扩展数组的容量
//两栈共享的思路：(1)让一个栈的栈底为数组的始端，即下标为0处，另一个栈为栈的末端。
//                (2)它们（栈顶）是在数组的两端，向中间靠拢。只要它们（栈顶）俩不见面，两个栈就可以一直使用。

//两栈共享空栈判断：栈1为空时，栈1的top1等于n-1时，就是栈1满了；
//                  而当top2等于n时，即是栈2为空时。

//两栈共享栈满判断：(1)若栈2是空栈，栈1的top1等于n-1时，就是栈1满了。
//                  (2)当栈1为空栈时，top2等于0时，为栈2满。
//                  (3)两个指针之间相差1时，即top1+1==top2为栈满。

//两栈共享空间的结构代码
/*两栈共享空间结构*/
//#define MAXSIZE 10
//#define OK 1
//#define ERROR 0
//typedef struct
//{
//	SEemType data[MAXSIZE];
//	int top1; /*栈1栈顶指针*/
//	int top2; /*栈2栈顶指针*/
//}SqDoubleStack;

//对于两栈共享空间的push方法，我们除了要插入元素值参数外，还需要有一个判断栈1还是栈2的栈号参数stackNumber
/*插入元素e为新的栈顶元素*/
//Status Push(SqDoubleStack* S, SElemType e, int stackNumber)
//{
//	if (S->top1 + 1 == S->top2)/*栈已满，不能再push新元素了*/
//	{
//		return ERROR;
//	}
//	if (stackNumber == 1)/*栈1有元素进栈*/
//	{
//		S->data[++S->top1] = e;/*若栈则先top1+1后给数组元素赋值*/
//	}
//	else if (stackNumber == 2)/*栈2有元素进栈*/
//	{
//		S->data[--S->top2] = e;/*若栈2则先top2-1后给数组元素赋值*/
//	}
//	return OK;
//}
//因为在开始已经判断是否有栈满的情况，所以后面的top1+1或top2-1是不用担心溢出问题的。

//对于两栈共享空间的pop方法，参数就只是判断栈1栈2的参数stackNumber
/*若栈不空，则删除S的栈顶元素，用e返回其值，并返回OK；否则返回ERROR*/
//Stats Pop(SqDoubleStack* S, SElemType* e, int stackNumber) //读取：（调用两栈共享链表S，设置e返回值，所要删除栈顶的栈）
//{
//	if (stackNumber == 1)  //如果要删除第1个栈的栈顶
//	{
//		if (S->top1 == -1) //判断栈是否为空
//		{
//			return ERROR;/*说明栈1已经是空栈，溢出*/
//		}
//		*e = S->data[S->top1--];/*将栈1的栈顶元素出栈*/ //且栈顶减一
//	}
//	else if (stackNumber == 2) //如果要删除第2个栈的栈顶
//	{
//		if (S->top2 == MAXSIZE) //如果第2个栈的top指针指为最大值，意味着空栈
//		{
//			return ERROR; /*说明栈2已经是空栈，溢出*/
//		}
//		*e = S->data[S->top2++];/*将栈2的栈顶元素出栈*/ //同时第2个栈的top指针要向左移动一位
//	}
//	return OK;
//}