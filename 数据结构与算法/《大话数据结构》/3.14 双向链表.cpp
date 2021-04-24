/*线性表的双向链表存储结构*/
//typedef struct DulNode
//{
//	ElemType data;
//	struct DuLNode* prior; /*直接前驱指针*/
//	struct DuLNode* next;  /*直接后继指针*/
//}DulNode,*DuLinkList;

//对于链表中的某一个结点p，它的后继的前驱是它自己。
//约等于上海的下一站是苏州，上海的下一站的前一站是哪里？
//p->next->prior = p = p->prior->next

//存储元素e的结点为s，要将s插入结点p和p->next之间
//s - >prior = p; /*把p赋值给s的前驱*/
//s -> next = p->next; /*把p->next赋值给s的后继*/
//p -> next->prior = s; /*把s赋值给p->next的前驱*/
//p -> next = s； /*把s赋值给p的后继*/

//删除结点p
//p->prior->next = p->next; /*把p->next赋值给p->prior的后继*/
//p->next->prior = p->prior;/*把p->prior赋值给p->next的前驱*/
//free(p);