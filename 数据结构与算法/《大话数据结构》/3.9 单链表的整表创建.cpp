//单链表整表创建
/*随机产生n个元素的值，建立带头结点的单链线性表（头插法）*/
//void CreateListHead(LinkList* L, int n)
//{
//	LinkList p;   //声明一结点p
//	int i;        //计数器变量i
//	srand(time(0));    /*初始化随机数种子*/
//	//初始化一空链表L
//	*L = (LinkList)malloc(sizeof(Node));   
//	(*L)->next = NULL;   /*先建立一个带头结点的单链表*/ //让L的头结点的指针指向NULL
//  //头插法代码    头插法：始终让新结点在第一的位置
//	for (i =0;i<n;i++) 
//	{
//		p = (LinkList)malloc(sizeof(Node)); /*生成新结点*/  //生成新结点赋值给p
//		p->data = rand() % 100 + 1; /*随机生成100以内的数字*/   //随机生成一数字赋值给p的数据域p->data
//		p->next = (*L)->next;     //将p插入到头结点与前一新结点之间
//		(*L)->next = p; /*插入到表头*/
//	}
//}

/*随机产生n个元素，建立带头结点的单链线性表L（尾插法）*/
//void CreateListTail(LinkList* L, int n)
//{
//	LinkList p, r;  //r是指向尾结点的变量，r会随着循环不断地改变结点
//	int i;
//	srand(time(0)); /*初始化随机数种子*/
//	*L = (LinkList)malloc(sizeof(Node));/*为整个线性表*/
//	r = *L; /*r为指向尾部的结点*/
//	//尾插法代码    尾插法：把每次新结点都插在终端结点的后面
//	for（i = 0; i < n; i++ ）
//	{
//		p = (Node*)malloc(sizeof(Node));/*生成新结点*/
//	    p->data = rand() % 100 + 1;/*随机生成100以内的数字*/
//		r->next = p;/*将表尾终端结点的指针指向新结点*/
//		r = p;      //r会随着循环不断改变，本来是p结点（最后一个结点），变成了r结点
//	}
//	r->next = NULL;/*表示当前链表结束*/  //循环结束后，应该让这个链表的指针域置空
//}