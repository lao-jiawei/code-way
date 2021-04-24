//获得链表第i个数据的算法思路
/*初始条件：顺序线性表L已存在，1<=i<=ListLength(L)*/
/*操作结果*/
//Status GetElem(LinkList L, int i, ElemType* e)
//{
//	int j;
//	LinkList p; /*声明一结点p*/
//	p = L->next;/*让p指向链表L的第一个结点*/
//	j = 1;    /*j为计数器*/
//	while (p && j < i) /*p不为空或者计数器j还没有等于i时，循环继续*/
//	{
//		p = p->next; /*让p指向下一个结点*/
//		++j;
//	}
//	if (!p || j > i)
//	{
//		return ERROR; /*第i个元素不存在*/
//		*e = p->data;/*取第i个元素的数据*/
//		return OK;
//	}
//}