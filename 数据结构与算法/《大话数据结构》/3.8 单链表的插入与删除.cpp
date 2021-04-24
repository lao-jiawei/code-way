//3.8.1 单链表的插入
/*初始条件：顺序线性表L已存在，1<=i<=ListLength(L)*/
/*操作结果：在L中第i个位置之前插入新的元素e，L的长度加1*/
//Status ListInsert(LinkList* L, int i, ElemType e)
//{
//	int j;
//	LinkList p, s;   //声明一个结点p指向链表第一个结点
//	while (p && j<i) /*寻找第i个结点*/
//	{
//		p = p->next;
//		++j;         
//	}
//	if (!p || j > i)
//	{
//		return ERROR; /*第i个元素不存在*/
//	}
//	s = (LinkList)malloce(sizeof(Node));/*生成新结点（C标准函数）*/
//	s->data = e;
//	s->next = p->next; /*将p的后继结点赋值给s的后*/
//	p->next = s; /*将s赋给p的后继*/
//	return OK;
//}

//3.8.2 单链表的删除
/*初始条件：线性表L已存在，1<=i<=ListLength(L)*/
/*操作结果：删除L的第i个数据元素，并用e返回其值，L的长度减1*/
//Status ListDelete(LinkList* L, int i, ElemType* e)
//{
//	int j;
//	LinkList p, q;
//	p = *L;
//	j = 1;
//	while (p->next && j<i) /*寻找第i个结点*/ //当j<i时，就遍历链表
//	{
//		p = p->next;   //让p的指针向后移动，不断指向下一结点
//		++j;           //j累加1
//	}
//	if (!(p->next) || j > i) //若到链表末尾p为空，则说明第i个元素不存在
//	{
//		return ERROR;/*第i个元素不存在*/
//	}
//	//若查找成功，将想要删除的结点p->next赋值给q
//	q=p->next;      
//	p->next = q->next;   /*将q的后继赋值给p的后继*/  //单链表删除标准语句
//	*e = q->data;        /*将q结点中的数据给e*/  
//	free(q);             /*让系统回收此结点，释放内存*/
//	return OK;
//}