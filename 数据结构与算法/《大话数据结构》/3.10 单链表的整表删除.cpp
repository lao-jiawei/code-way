//单链表整表删除
/*初始条件：顺序线性表L已存在，操作结果：将L重置为空表*/
//Status ClearList(LinkList* L)
//{
//	LinkList p, q;   //声明一结点p和q
//	p = (*L)->next; /*p指向第一个结点*/ //将第一个结点赋值给p
//	while (p) 
//	{
//		q = p->next;  //将下一结点赋值给q
//		free(p);      //释放p
//		p = q;        //将q赋值给p
//	}
//	(*L)->next = NULL; /*头结点指针域为空*/
//	return OK;
//}