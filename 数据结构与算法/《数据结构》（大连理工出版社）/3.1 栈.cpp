//3.1.1 栈的定义以及其基本运算
//1、栈的定义
//栈（堆栈）：是限定仅在表的一端进行插入和删除操作的线性表。
//栈顶：允许插入和删除的一端
//栈底：不能够插入和删除的一端
//空栈：不含任何元素的栈

//在栈上的主要操作是在栈顶进行插入和删除操作。

//入栈（进栈）：栈的插入操作
//出栈（退栈）：栈的删除操作

//栈的主要特点：先进后出(First In Last Out(FILO))\后进先出（Last In First Out(LIFO)）

//只有最后入栈的元素才能最先出栈

//2、栈的基本运算
/*InitStack(&S):构造空栈
DestroyStack(&S):销毁栈
ClearStack(&S):清为空栈
EmptyStack(&S):判断是否为空栈，是空栈返回True,不是空栈返回False
LengthStack(&S):求栈长度
TraverseStack(&S):遍历栈，将栈中的每个元素都访问一遍
GetTop(&S,e):获取栈顶元素，存储到e中
Push(&S,e):入栈,将元素e插入栈S中，使其成为新的栈顶元素
Pop(&S,e):出栈，将栈S的栈顶元素删除，并将其存到e中
*/

//3.1.2 栈的顺序存储结构及运算
//栈有两种存储表示方法：顺序存储和链式存储
//顺序栈：1、采用顺序存储结构的栈
//        2、利用一组地址连续的存储单元依次存放自栈底到栈顶的数据元素，同时附设一个栈顶指针top，用于指示当前栈顶位置。

//栈顶指针top=0时表示空栈

//链栈：1、采用链式存储结构的栈

//顺序栈的类型说明：
/*#define Stack_Init_Size 100 //栈的初始大小
#define Stack Increment 10 //栈的存储空间分配增量
typedef int ElemType; //ElemType为栈的元素类型
typedef struct 
{
	ElemType* stackdata; //栈中数据元素存储空间（一位数组）的起始地址
	int top; //栈顶指针，实际上是栈顶位置的数组下标
	int stacksize; //栈当前的可用大小，初始大小有Stack_Init_Size指定
}SeqStack;*/

//1、初始化顺序栈
//Status InitStack(SeqStack* S) 
//{
//	if (!S) //if(!S)等价于if(S==0)
//	{
//		return Err_InvalidParam; //顺序栈无效
//	}
//	/*为stackdata分配内存空间*/
//	S->stackdata = (ElemType*)malloc(Stack_Init_Size*sizeof(ElemType)); //从栈的初始大小中分配当前栈的大小
//	if (!S->stackdata) //等价于if(S->stackdata==0)
//	{
//		return Err_Memory;//内存分配错误
//	}
//	S->top = 0; //初始化栈顶指针为0
//	S->stacksize = Stack_Init_Size; //设置栈当前大小
//	return OK;
//}

//2、清空顺序栈
//Status ClearStack(SeqStack* S)
//{
//	if (!S) //如果S不存在
//	{
//		return Err_InvalidParam; //顺序栈无效
//	}
//	S->top = 0; //栈顶指针设置为0
//	return OK;
//}

//3、判断是否为空栈
//int EmptyStack(SeqStack* S)
//{
//	if (!S) 
//	{
//		return Err_InvalidParam; //顺序表无效
//	}
//	return (S->top == 0); //top等于0为空，返回True，否则返回False
//}

//4、计算栈的长度
//int LengthStack(SeqStack* S) 
//{
//	return S->top; //top指示栈中元素个数
//}

//5、遍历顺序栈
//void TraverseStack(SeqStack* S)
//{
//	int i;
//	for (i = 0; i < S->top; i++) //从栈底开始直到i大于栈顶为止
//	{
//		printf("%d\t", S->stackdata[i]);
//	}
//}

//6、获取栈顶元素
//Status GetTop(SeqStack* S, ElemType* e)
//{
//	if (!S) //如果S不存在
//	{
//		return Err_InvalidParam; //顺序栈无效
//	}
//	if (S->top == 0)//如果栈顶为0
//	{
//		return Err_NoResult; //栈为空
//	}
//	*e = S->stackdata[S->top - 1]; //获取栈顶元素
//	return OK;
//}

//7、元素入栈
//Status Push(SeqStack* S, ElemType e)  //读取：（调用顺序栈S，入栈元素）
//{
//	ElemType* newstack;
//	if (!S) //判断顺序栈是否存在
//	{
//		return Err_InvalidParam; //顺序栈无效
//	}
//	if (S->top == S->stacksize) //栈满，追加存储空间
//	{
//		newstack = (ElemType*)malloc(S->stackdata, (S->stacksize + Stack_Increment) * sizeof(ElemType));  //？
//	}
//	if (!newstack)   //？
//	{
//		return Err_Memory; //内存分配错误
//	}
//	S->stackdata = newstack;
//	S->top = S->stackdata + S->stacksize; //修改当前栈的可用空间大小
//	S->stackdata[S->top++] = e; //将元素e存入栈顶，然后将top加1
//	return OK;
//}

//8、元素出栈
//Status Pop(SeqStack* S, ElemType* e) //读取：（调用顺序栈S，栈顶元素）
//{
//	if (!S) //判断顺序栈是否存在
//	{
//		return Err_InvalidParam;//顺序栈无效
//	}
//	if (S->top == 0)
//	{
//		return Err_NoResult; //栈为空
//	}
//	*e = S->stackdata[--S->top];//将top减1，然后将栈顶元素存入e中
//	return OK;
//}

//3.1.3 栈的链式存储结构及运算

//链栈：利用单链表作为栈的存储结构
//链栈的栈顶：单链表第一个结点
//链栈的栈底：单链表最后一个结点

//链栈既可以是带头结点的链表也可以是不带头结点的链表。

//对于不带头结点的链栈，栈顶指针直接指向栈顶结点
//对于带头结点的链栈，栈顶指针指向头结点。

//链栈结点结构
//typedef struct node 
//{
//	ElemType data; //数据域，用于存放栈中的数据元素
//	Struct node *next;//指针域
//}StackNode,*LinkStack;

//链栈：一个限定只能在表头（第1个位置）进行插入（入栈）和删除（出栈）操作的链表。

//1、获取栈顶元素
//Status GetTop(LinkStack top, ElemType* e) //读取：（调用链栈top，设置一个e来存储栈顶元素）
//{
//	if (!top) //如果top=0，
//	{
//		return Err_InvalidPara; //链栈无效
//	}
//	if (!top->next)//栈顶为0，则栈空
//	{
//		return Err_NoResult; //栈为空
//	}
//	*e = top->next->data; //获取栈顶元素，并将其存入e中
//	return OK;
//}

//2、元素入栈
//Status Push(LinkStack top, ElemType e)//读取：（调用链栈top，设置e用来存放要插入元素）
//{
//	StackNode* s; //设置指针s
//	if (!top) //链栈无效 top头结点值为0
//	{
//		return Err_InvalidParam; 
//	}
//	s = (StackNode*)malloc(sizeof(StackNode)); //生产新结点s
//	if (!s) //内存分配错误 
//	{
//		return Err_Memory; 
//	}
//	s->data = e;//将数据元素e存放到新结点的数据域
//	s->next = top->next; //将s插入到栈顶
//	top->next = s;
//	return OK;
//}

//3、元素出栈
//Status Pop(LinkStack top, ElemType* e)//读取：（调用链栈top，用e来存储栈顶元素）
//{
//	StackNode* p;  //设置p指针
//	if (!top) //链栈无效 //top头结点值为零
//	{
//		return Err_InvalidParam; 
//	}
//	if (!top->next) //栈为空 //栈顶的下一个结点值为0
//	{
//		return Err_NoResult;
//	}
//	*e = top->next->data; //将栈顶数据元素保存至e中
//	p = top->next;//p指向栈顶结点
//	top->next = p->next;//删除栈顶结点
//	free(p);//释放结点
//	return OK;
//}