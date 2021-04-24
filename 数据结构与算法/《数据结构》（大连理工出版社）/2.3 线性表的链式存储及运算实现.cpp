//2.3.1 单链表
//1、单链表的定义和表示
//在C语言中，单链表的类型定义
//#include"stdio.h"
//typedef int ElemType; /*在实际问题中，可以根据需要定义所需的数据类型*/
//typedef struct node
//{
//	ElemType data; /*数据域*/
//	struct nod* next;/*指针域*/
//}slink; /*单链表类型名*/

//2、基本操作在单链表上的实现
//（1）建立一个单链表（创建一个含有n个元素的带头结点的单链表head）
//slink* creslink(int n)
//{
//	slink* head, * p, * s;
//	int i;
//	if (n < 1) 
//	{
//		return NULL;
//	}
//	p = head =(slink*)malloc(sizeof(slink));/*创建头结点*/
//	for (i = 1; i <= n; i++)
//	{
//		s = (slink*)malloc(sizeof(slink));
//		scanf(" %d", &s->data);
//		p = s;
//	}
//	p->next = NULL;
//	return head;    /*尾结点的指针域为空*/
//}

//（2）求表长操作（返回单链表head的长度）
/*int getlen(slink* head)
{
	slink* p;
	int n = 0;     //设置一个整型变量作为计数器
	p = head->next;     //指针p指向第1个结点
	while (p != NULL)   //若p值不为空
	{
		n++;            //计数器加一
		p = p->next;    //同时指针p往后移动一次
	}                   //直到p为空为止。
	return n;           //n的值即为表长
}*/

//（3）取元素操作（取出单链表head的第i个元素的值）
//int getelem(slink* head, int i, ElemType* e)
//{
//	slink* p;
//	int j;
//	if (i < 1)        //确定i的取值范围（1<=i<=n）
//	{
//		return 0;      /*参数i不合法，返回0*/
//	}
//	p = head->next;   //从单链表head的第1个结点开始
//	j = 1;
//	while (p != NULL && j < i)  /*从第1个结点开始查找第i个结点*/
//	{
//		p = p->next;
//		j++;
//	}
//	if (p == NULL)       /*i值超过链表的长度，返回0*/
//	{
//		return 0;
//	}
//	*e = p->data;      //将该结点的元素值带回
//	return 1;           /*读取成功，返回1*/
//}

//（4）定位操作（查找元素x在单链表head中第1次出现的位置）
//slink* locate(slink* head, ElemType x)
//{
//	int i;
//	slink* p;
//	p = head->next;   //从单链表head的第1个结点开始
//	i = 1;
//	while (p != NULL && p->data != x)  /*从第1个结点开始查找数据域值为x的结点*/   //逐个进行给定值x和结点数据域值的比较
//	{
//		p = p->next;
//		i++;
//	}
//	return p;   /*无论是否找到，返回其指针p即可*/  //若某个结点的数据域和给定值x相等，则返回该结点的指针。 //若不存在，则返回NULL
//}

//（5）删除操作（删除带头结点单链表head的第i个结点）
//int delete(slink* head, int i, ElemType* e)
//{
//	slink* p, * q;
//	int j;
//	if (i < 1)    /*参数i不正确*/ //保证删除位置的合理性（1<=i<=n）
//	{
//		return 0;
//	}
//	p = head;
//	j = 0;
//	while (p->next != NULL && j < i - 1)     //在单链表head上找到要删除的结点的前驱结点
//	{
//		p = p->next;  /*从第1个结点开始查找第i-1个结点，由p指向它*/
//		j++;
//	}
//	if (p->next == NULL) /*i值超过表长*/
//	{
//		return 0;
//	}
//	q = p->next;      /*q指向第i个结点*/
//	p->next = q->next;  /*p的指针域指向q指向结点的下一个结点，删除第i个结点*/
//	*e = q->data;     /*保存结点上的值*/
//	free(q);          /*释放第i个结点占用的空间*/
//	return 1;         /*删除成功，返回1*/
//}

//（6）插入操作（在带头结点的单链表head的第i个结点之前插入值为x的新结点）
//int insert(slink* head, int i, ElemType x)
//{
//	slink* p, * q;
//	int j;
//	if (i < 1)  //保证删除位置的合理性（1<=i<=n+1）
//	{
//		return 0;   /*参数i不正确*/
//	}
//	p = head;
//	j = 0;
//	while (p!=NULL && j<i-1) /*从第1个结点开始查找第i-1个结点，由p指向它*/
//	{
//		p = p->next;
//		j++;
//	}
//	if (p==NULL) /*i值超过链表长度+1*/
//	{
//		return 0;
//	}
//	q = (slink*)malloc(sizeof(slink));
//	q->data = x;          /*创建值为x的结点q*/
//	q->next = p->next;   //在p所指向的结点后插入q所指向的结点
//	p->next = q;
//	return 1;    /*插入成功返回1*/
//}

//（7）输出操作（输出带头结点的单链表head中的所有结点值）
/*void list(slink* head)
{
	slink* p;
	p = head->next;
	while (p != NULL) //从第1个结点开始，顺序往下扫描
	{
		printf("%4d", p->data); //输出扫描到结点的数据域的值
		p == p->next;
	}//直到终端结点为止
	printf("\n");
}*/

//例2.4：实现两个带头结点单向链表a和b的连接。要求结果链表仍使用原来的两个链表的存储空间，不另开辟存储空间
//void link(slink* a, slink* b)
//{
//	slink* p;
//	for (p = a; p->next != NULL; p = p->next);  /*p指向单链表a的最后一个结点*/
//	p->next = b->next;  /*把单链表b连接到单链表a的后面*/  //用指针p指向链表的最后一个结点，然后通过语句进行连接
//	free(b);   //回收单链表b的头结点
//}

//例2.5：将两个带头结点的非递减有序单向链表la和lb归并成一个非递减的有序单链表。要求结果链表仍使用原来两个链表的存储空间。不另开辟存储空间，表中允许有重复数据
//void merge(slink* la, slink* lb)
//{
//	slink* pa, * pb, * pc;   
//	pa = la->next;      //每个链表上安排一个指针（pa，pb）
//	pb = lb->next;
//	pc = la;  /*将la作为新链表的头指针，pc总是指向新链表的最后一个结点*/
//	while (pa != NULL && pb != NULL)   //遍历各自的链表结点
//	{
//		if (pa->data <= pb->data)
//		{
//			pc->next = pa;     
//			pa = pa->next;     /*pa指向的结点链接到pc指向的结点后*/
//		}
//		else 
//		{
//			pc->next = pb; /*pb指向的结点连到pc指向的结点后*/
//			pb = pb->next;
//		}
//		pc = pc->next;
//	}
//	if (pa != NULL)       /*若la表中还有剩余结点，则接入新表中*/
//	{
//		pc->next = pa;
//	}
//	else           /*若lb表中还有剩余结点，则接入新表中*/
//	{
//		pc->next = pb;
//		free(lb);
//	}
//}

//例2.6 用带头结点单向链表实现集合操作A∪B，要求结果链表使用原来两个链表的存储空间，不另开辟存储空间。
//void bring(slink* la, slink* lb)
//{
//	slink* l, * p, * q;
//	int i;
//	l = lb->next;
//	while (l!=NULL)
//	{
//		p = la;
//		q = la->next;
//		while (q!=NULL && q->data!=l->next) //在单链表la中依次搜索单链表lb的每一个结点
//		{
//			p = q;
//			q = q->next;
//		}
//		if (q!=NULL)      
//		{
//			p->next = q->next; //存在重复的值，释放其中一个
//			free(q);
//		}
//		l = l->next;   //指针l往后移
//	}
//	for (l = la; l->next！=NULL; l = l->next); /*l指向单链表la的最后一个结点*/
//	l->next = lb->next; /*把单链表lb连接到单链表la的后面*/
//	free(b);
//}

//例2.7 实现带头结点单链表head逆置。要求结果仍使用原链表的存储空间，不另开辟存储空间。
//void turn(slink* head)
//{
//	slink* p, * q;
//	p = head->next;
//	head->next = NULL;/*置一个空链表head*/
//	while (p!=NULL)
//	{
//		q = p->next;     /*保存插入点的后继结点指针*/
//		p->next = head->next;
//		head->next = p;
//		p = q;
//	}
//}

//例2.8 将带头结点单链表head（结点数据域的值为整数）拆成一个奇数链表和一个偶数链表。要求结果仍使用原链表的存储空间，不开辟存储空间
//void divide(slink* head, slink** odd)
//{
//	slink* p, * q, * r;
//	*odd = (slink*)malloc(sizeof(slink));  /*生成偶数链表的头结点*/
//	r = head->next;       /*r用于遍历整个链表*/
//	p = head;      /*head作为奇数链表的头指针，p用于连接奇数结点*/
//	q = *odd;      /* *odd作为偶数链表的头指针，q用于连接偶数结点*/
//	while (r!=NULL)   //r指针遍历整表
//	{
//		if (r->data % 2 != 0) //判断当前r指针指的结点数据域的元素值是否为奇数
//		{
//			p->next = r;  //将其连在head链表的尾部
//			p = r;
//		}
//		else //为偶数
//		{
//			q->next = r;  //连到*odd链表的尾部。
//			q = r;
//		}
//		r = r->next;
//	} //while循环结束
//	p->next = q->next = NULL;
//}

/*未分析*/
//例2.9假设多项式形式为p（x）=C1x,其中，C1和em（1<=o<=m）为整型数，并且e1>e2>...>em>=0。求两个多项式相加的程序
//#include"stdio.h"
//typedef struct node
//{
//	int c; /*多项式系数*/
//	int e; /*多项式指数*/
//	struct node* next;
//}dxs;
//
//dxs* creat(int m) /*把多项式表示成带头结点的单链表*/
//{
//	dxs* head, * p* q;
//	int i;
//	p = head = (dxs*)malloc(sizeof(dxs));/*头结点*/
//	for (i=1;i<=m;i++)
//	{
//		q = (dxs*)malloce(sizeof(dxs));
//		scanf("%d%d", &q->c, &q->e);
//		p->next = q;
//		p = q;
//	}
//	p->next = NULL;
//	return head;
//}
//
//plus(dxs* h1, dxs* h2) /*多项式求和*/
//{
//	dxs* h, * p1, * p2, * q;
//	h = h1;
//	p1 = h1->next;
//	p2 = h2->next;
//	while (p1!=NULL &&p2!=NULL)
//	{
//		if (p1->e > p2->e) /*p1结点连到h结点的后面*/
//		{
//			h->next = p1;
//			h = p1;
//			p1 = p1->next;
//		}
//		else if (p2->e > p1->e) /*p2结点连到h结点的后面*/
//		{
//			h->next = p2;
//			h = p2;
//			p2 = p2->next;
//		}
//		else if (p1->c + p2->c!=0)/*结合值合并到p1结点中*/
//		{
//			p1->c = p1->c + p2->c; /*把p2->c累加到p1->c中*/
//			h->next = p1;         /*p1结点连到h结点的后面*/
//			h1 = p1;
//			p1 = p1->next;
//			q = p2;
//			p2 = p2->next;
//			free(q);
//		}
//		else /*系数和为0，删除两个对应的结点*/
//		{
//			q = p1;
//			p1 = p1->next;
//			free(q);
//			q = p2;
//			p2 = p2->next;
//			free(q);
//		}
//		if (p1!=NULL) 
//		{
//			h->next = p1; /*剩余部分连接到h结点的后面*/
//		}
//		else 
//		{
//			h->next = p2;
//			free(h2);
//		}
//	}
//}	
//	void list(dxs * head)
//		{
//			dxs * p = head->next;
//			while (p != NULL)
//			{
//				printf("(%4d,%4d)", p->c, p->e);
//				p = p->next;
//			}
//			printf("\n");
//		}
//		main()
//		{
//			dxs* h1, * h2;
//			h1 = creat(5);
//			h2 = creat(7);
//			plus(h1, h2);
//			list(h1);
//		}

//2.3.2循环链表
//1、单向循环链表的表示和实现
//单向循环链表的类型定义
//#include"stdio.h"
//typedef int ElemType;
//typedef struct node
//{
//	struct node* next;
//}slink;
//(1)建立单向循环链表（创建一个含有n个结点的带头结点单向循环链表head）
//slink* cresrlink(int n)
//{
//	slink* head, * p, * s;
//	int i;
//	p = head = (slink*)malloc(sizeof(slink)); //创建头结点
//	for (i=1;i<=n;i++)
//	{
//		s = (slink*)malloc(sizeof(slink));   //分配结点空间
//		scanf(" %d",&s->data);
//		p->next = s;
//		p = s;
//	}
//	p->next = head;/*尾结点的指针域指向头结点*/
//	return head;
//}

//（2）求表长操作（返回单向循环链表head的表长）
//int getlen(slink* head)
//{
//	int i;
//	slink* p;
//	p = head->next;
//	i = 0;  //定义一个整型计数器
//	while (p != head)  //p!=head 是因为单循环链表循环一遍又回到head
//	{
//		i++;
//		p = p->next;    //指针指向下一个结点
//	}
//	return i;
//}

//（3）取元素操作（取出单循环链表head的第i个结点的元素值）
//int getelem(slink* head, int i, ElemType* e)
//{
//	int j;
//	slink* p;
//	if (i < 1)    //输入元素不合法，返回0
//		return 0;
//	}
//	p = head->next;
//	j = 1;
//	while (p!=head && j < i)  //从head结点的下一个结点到结点i-1结束
//	{
//		p = p->next;
//		j++;
//	}
//	if (p == head)   //指针指到头结点，取出失败，返回0
//	{
//		return 0;
//	}
//	*e = p->data;  //取出结点i的元素值
//	return 1;
//}

//（4）定位操作（在单向循环链表head中查找第1个值为x的结点）
//slink* locate(slink* head, ElemType x)
//{
//	int i;
//	slink* p;
//	p = head->next;
//	i = 1;
//	while(p!=head && p->data!=x) //从头结点的下一个结点开始，到第一个保存x的结点的前一个结点结束
//	{
//		p = p->next;
//		i++;
//	}
//	if (p == head)   
//	{
//		return NULL; /*没找到返回NULL，否则返回指向该结点的指针p*/
//	}
//	else 
//	{
//		return p;
//	}
//}

//（5）删除操作（删除带头结点单向循环链表head中的第i个结点）
//int delete(slink* head, int i, ElemType* e)
//{
//	slink* p, * q;
//	int j;
//	if (i < 1)   //所要删除的结点不合法，返回0
//	{
//		return 0;
//	}
//	p = head;
//	j = 0;
//	while (p->next != head && j < i - 1)  //从头结点的下一个结点开始，到第i-1个结点结束 因为j从0开始，所以i-1
//	{
//		p = p->next;
//		j++;
//	}
//	if (p->next == head)    //循环了一遍没有找到i，返回0
//	{
//		return 0;
//	}
//	q = p->next;       //q指针指向所要删除的结点
//	p->next = q->next;   
//	*e = q->data;      //取出所要删除结点的元素值
//	free(q);          //释放所要删除的结点
//	return 1;
//}

//（6）插入操作（在带头结点单向循环链表head中的第i个结点之前插入一个值为x的结点）
//int insert(slink* head, int i, ElemType x)
//{
//	slink* p, * q, int j;
//	if (i < 1)       //所要插入的位置不合法，返回0
//	{
//		return 0;
//	}
//	p = head;
//	j = 0;
//	while (p->next！=head && j<i-1) /*从第1个结点开始查找第i-1个结点*/
//	{
//		p = p->next;   /*p指向它*/
//		j++;
//	}
//	if ((p->next!=head)||p->next==head && j==i-1) 
//	{
//		q = (slink*)malloc(sizeof(slink)); /*创建data域为x的结点*/
//		q->data = x;
//		q->next = p->next; /*q的指针域指向p结点的后继结点*/
//		p->next = q; /*p的指针域指向q结点，完成插入*/
//		return 1; /*插入成功，返回1*/
//	}
//	else 
//	{
//		return 0;
//	}
//}

//（7）输出操作（输出带头结点单向循环链表head的歌结点的值）
//void list(slink* head)
//{
//	slink* p;
//	p = head->next;
//	while (p != head)  //从头结点的下一个结点开始，一直到再次循环到头结点结束
//	{
//		printf(" %4d",p->data);  //%4d 是用来对齐输出值
//		p = p->next;
//	}
//	printf("\n");  
//}

//例2.10 由n个按照1、2、3...、n编号的人围成一圈，从编号为1的人开始按照1,2，3...顺序循环报数，凡报道3者出圈，最后只留一个人，问其编号是多少（用带头结点单向循环链表实现）
//void onlyone(int n)
//{
//	slink* head, * p, * q;  //用p作为扫描单向循环链表head的指针
//	int i, m, k;           //用k作为计数器
//	p = head = (slink*)malloc(sizeof(slink));   
//	for (i = 1; i <= n; i++) 
//	{
//		q = （slink * ）malloc(sizeof(slink));
//		q->data = i;
//		p->next = q;
//		p = q;
//	}
//	p->next = head; /*建立了一个值为编号的带头结点单向循环链表head*/
//	p = head;   //先指向头结点
//	m = 0;     //记录数到3的人数
//  while(m<n-1)   //全部人都过一遍，直到最后一个人为止
//  {
//      k=0; //出现3之后重新从0开始数
//	while (k<3)    //编号为1、3的人
//	  {
//		k++;
//		q = p;
//		p = p->next;   //下一个结点
//		if(p==head)   //如果已经循环了一遍，p指针又指到头结点
//		{
//			q = p;
//			p = p->next; /*跳过头结点*/
//		}
//    }
//		q->next = p->next;/*删除p结点*/  //当p指到编号为3的人时。
//		free(p);
//		p = q; /*重新定位p指针*/
//		m++;   /*对删除的结点计数，当m=n-1时退出循环*/
//  }
//	list(head);/*检验链表中是否仅剩一个结点，若是，即为所求*/
//}

//2、双循环向链表的表示和实现
//双向链表的类型定义
#include"stdio.h"
typedef int ElemType;
typedef struct node
{
	ElemType data;
	struct node* next;
	struct node* prior;
}dlink;

//(1)建立双向循环链表（创建一个含有n个结点的带头结点双向循环链表head）
//dlink* initlist(int n)
//{
//	dlink* head, * p, * s;
//	int i;
//	p = head = (dlink*)malloc(sizeof(dlink));
//	for (i=1;i<=n;i++) 
//	{
//		s = (dlink*)malloc(sizeof(dlink));
//		scanf(" %d", &s->data);
//		s->prior = p;  //s结点向前连接p结点
//		p->next = s; //p结点向后连接s结点
//		p = s;    //p指针直到s结点
//	}
//	p->next = head;
//	head->prior = p;/*首尾相连，构成循环*/
//	return head;
//}

//(2)求表长操作（计算机双向循环链表head的表长）
/*int getlen(dlink* head)
{
	int i = 0;      //定义一个整型变量i为计数器，来记录链表的长度
	dlink* p;
	p = head->next;
	while (p != head) //如果指针没有指到头结点，就继续移到下一个结点
	{
		i++;       
		p = p->next;  //p指针指向下一个结点
	}  //直到指针指到头结点，循环结束
	return i;  //返回链表长度
}*/

//(3)取元素操作（取出双向循环链表head的第i个结点的数据元素的值）
/*int getelem(dlink* head, int i, ElemType* e)
{
	int j;
	dlink* p;
	if (i < 1) {     //所要取出的位置不合法
		return 0;
	}
	p = head->next;
	j = 1;
	while (p != head && j < i) //p不为头指针并且指针没指到第i个结点
	{
		p = p->next; //指针指向下一个结点
		j ++;
	}//直到指针指到第i个结点，循环结束
	if (p == head) {  //如果循环一遍，p指针指到了头结点，还是没找到第i个结点
		return 0;     //查找失败
	}
	*e = p->data;  //e取出第i个结点的元素
	return 1;
}*/

//(4)定位操作（在带头结点双向循环链表中查找第1个值为x的结点）
//dlink* locate(dlink* head, ElemType x)
//{
//	dlink* p;
//	p = head->next;  //让p指针从头结点的下一个结点开始循环
//	while (p!=head&&p->data!=x) //p指针不为头结点且p指针没找到值为x的结点时则继续循环
//	{
//		p = p->next; //p指针移向下一个结点
//	} //循环结束
//		if (p==head)   //循环了一遍p指针又指到了头结点
//		{
//			return NULL;/*没找到返回NULL，否则返回指向该结点的指针p*/
//		}
//		else  //找到值为x的结点
//		{
//			return p;
//		}
//}

//(5)删除操作（删除带头结点的双向循环链表head中的第i个结点）
//int delete(dlink* head, int i, ElemType* e)
//{
//	dlink* p, * q;
//	int j;
//	if (i < 1)   //删除位置不合法
//	{
//		return 0;
//	}
//	p = head;  //p指针从头结点开始
//	j = 0;    
//	while (p->next!=head&&j<i-1)//p指针的下一结点不为头指针并且j的值还不为要删除的第i个结点的前一项时，循环继续 
//	{
//		p = p->next; //p指针指向下一个结点
//		j++;  
//	}
//	if (p->next==head)  //循环一遍还没找到第i个结点，删除失败
//	{
//		return 0;
//	}
//	q = p->next;   //p指针指到要删除的结点的前一个结点，q指针指向要删除的结点
//	p->next = q->next;   //p的下一个等于要删除结点的下一个结点
//	q->next->prior = p;//要删除结点的后一个结点的前驱等于p指向的结点
//	*e = q->data; //e存储要删除结点的元素
//	free(q); //释放q指针
//	return 1; //删除成功
//}

//(6)插入操作（在带头结点双向循环链表head的第i个结点之前插入一个值为x的结点）
//int insert(dlink* head, int i, ElemType x)
//{
//	dlink* p, * q;
//	int j;
//	if (i < 1)  //插入位置不合法，返回插入失败
//	{
//		return 0;
//	}
//	p = head;  //p指针从头结点开始
//	j = 0;
//	while (p->next!=head&&j<i-1)  //p指针的下一个结点不为头结点，且j不为插入位置的前一个结点循环继续
//	{
//		p = p->next; //p指针指向下一个结点
//		j++;
//	} //while循环结束
//	if (p->next!=head||p->next==head&&j=i-1)  //p的下一个不为头结点或p的下一个为头结点且j为要插入位置的前一个结点
//	{
//		q = (dlink*)malloc(sizeof(dlink)); //分配空间给q指针
//		q->data = x;        //q的数据域为要插入的元素
//		q->next = p->next;   //要插入q结点的后继为p结点的下一个结点
//		q->prior = p; //要插入q结点的前驱为p指向的结点
//		p->next->prior = q; //p结点的下一个结点的前驱指向要插入的q结点
//		p->next = q; //p结点的后继改为q结点
//		return 1;  //插入成功
//	}
//	else  //否则插入失败
//	{
//		return 0;
//	}
//}

//(7)输出操作（从两个方向输出带头结点双向循环链表head的各结点的值）
//void list(dlink* head)
//{
//	dlink* p;
//	p = head->next;/*正向输出链表*/
//	while (p!=head) //直到p指针指为头结点才结束循环
//	{
//		printf("4%d", p->data); //4位对齐，输出每个结点上数据域的值
//		p = p->next;   //p指针移向下一个结点
//	}
//	printf("\n");   //输出完后换行
//	p = head->prior;/*反向输出链表*/
//	while (p!=head)  //同上
//	{
//		printf("%4d", p->data); //同上 
//		p = p->prior; //p指针移向前一个结点
//	}
//	printf("\n");//同上
//}

//例2.11 将自然数1~m按由小到大的顺序沿顺时针方向围成一个圈，然后以1为起点，先沿顺时针方向数到第n个数将其划去，再沿逆
//       时针方向数到k个数将其划去。重复以上操作，直到剩下一个数为止。问最后剩下的是哪个数（用带头结点双向循环链表实现）
//void onlyone(int m, int n, int k) //定义m为元素个数，n为顺时针寻找要删除的位置，k为逆时针寻找要删除的位置
//{
//	dlink* head, * p, * q; //创建一个带头结点的双向循环链表head
//	int i;
//	if (m < 1 || n < 1 || k < 1)  //如果元素个数少于1，或顺时针要删除位置小于1，或逆时针要寻找的位置小于1
//	{
//		printf("Error!\n");  //报错
//		exit(0);
//	}
//	p = head = (dlink*)malloc(dlink); //p指向头结点，分配空间给p
//	for (i = 1; i <= m; i++)         //双向循环链表的建立
//	{
//		q = (dlink*)malloc(dlink); //分配空间给q指针
//		q->data = i;    //给q指针所在的结点赋值
//		q->prior = p;   //q所在的结点前驱指向p所在的结点
//		p->next = q;   //p所在的结点后继指向q所在的结点
//		p = q;  //p指针移动到q指针所指的结点
//	} //for循环结束
//	p->next = head;   //p指针此时正指着第m个结点，现在让p结点的后继指回头结点就构成循环链表
//	head->prior = p;/*已建立了一个带头结点双向循环链表head*/  //接下来头结点的前驱指向p结点，就形成了双向循环链表
//	p = head; //再让p指针指向头结点
//	while (m > 1) //判链表是否为空，如果非空则进行循环
//	{
//		for (i = 1; i <= n; i++) /*顺时针搜索第n个结点，用p指向它*/  //i此时又要初始化为1
//		{
//			q = p; //q指针指向p指针所在的结点
//			p = p->next;  //p指针移动到下一个结点
//			if (p == head) //已经循环了一圈还没找到第n个结点，再循环一次
//			{
//				q = head;  //q指针指向头结点
//				p = head->next;  //p指针移动到头指针的下一个指针
//			}
//		} //for循环结束
//		q->next = p->next;    //删
//		p->next->prior = q;   //除
//		free(p);              //操
//		p = q->next;          //作
//		m--;  //元素个数减少一个
//		if (m > 1) /*若链表中的结点数不为1，将p指向的结点的结点删除，链表长度减1*/
//		{
//			for (i = 1; i <= k; i++) /*逆时针搜索第k个结果，用p指向它*/
//			{
//				q = p;             //q指针指向p指针所在的结点
//				p = p->prior;      //p指针移动到前一个结点
//				if (p == head)    //已经循环了一遍，再来一遍
//				{
//					q = head;          //同上
//					p = head->prior;   //p指针移动到头结点的前一个结点
//				}
//			}
//			q->prior = p->prior;    //q结点的前驱改为p结点的前驱
//			p->prior->next = q;    //p指针所指的前一个结点的后继为q结点
//			free(p);     //释放p结点
//			p = q->prior;  //p指针指向q所指结点的前一个结点
//			m--;  //元素个数又少了一个
//		}
//	}
//	list(head);/*若链表中只有一个结点，该结点值即为所求，否则出错*/
//}

//2.3.3 双向链表
//1、双链表
//双向链表（双链表）：为了能是迅速方便地找到任意一个结点的前驱和后继，在结点中再增设一个指针域，指向该结点的前驱结点，这样就形成两个不同方向的链。

//双链表的结点类型定义
//#include"stdio.h"
//typedef int ElemType;
//typedef struct node 
//{
//	ElemType data;
//	struct node* next;  /*指向后继结点的指针域*/
//	struct node* prior; /*指向前驱结点的指针域*/
//};

//2、基本操作在双链表上的实现
//(1)建立双链表（创建一个含有n个结点的带头结点双链表head）
//dlink* initlist(int n)
//{
//	dlink* head, * p, * s;
//	int i;
//	p = head = (dlink*)malloc(sizeof(dlink)); /*创建头结点*/
//	for (i=1;i<=n;i++) //创建双链表
//	{
//		s = (dlink*)malloc(sizeof((dlink)); //给s指针分配空间
//		scanf("%d", &s->data);//给刚生成的结点赋值
//		s->next = NULL;     /*刚生成的结点一定为尾结点*/   //s指针所在结点的后继指向尾结点
//		s->prior = p;      //s指针所在结点的前驱指向p指针所在结点
//		p->next = s;       //p指针所在结点的后继为s指针所在结点
//		p = s;            //p指针移动到s指针的位置
//	}
//	p->next = NULL;      //完成创建双链表后，p指针的后继为尾结点
///	return head;         //返回头指针
//}

//(2)求表长操作（返回双链表head的长度）
//int getlen(dlink* head)
//{
//	int i = 0;//设置一个整型i来计数
//	dlink* p; //设置一个p指针
//	p = head->next; //p指针指向头节点的下一个结点
//	while (p != NULL) //循环直到p指针指到尾结点结束
//	{
//		i++;     //计数器+1
//		p = p->next; //p指针移动到下一个结点
//	}
//	return i;     //返回表长
//}

//(3)取元素操作（取出双链表head中第i个结点的值）
//int getelem(dlink* head, int i, ElemType* e)
//{
//	int j;
//	dlink* p;
//	if (i<1) 
//	{
//		return 0;     /*i值不合理，返回0*/
//	}
//	p = head->next;
//	j = 1;
//	while (p != NULL && j < i)  /*从第1个结点开始查找第i个结点*/
//	{
//		p = p->next;
//		j++;
//	}
//	if (p == NULL)  /*值超出表长，返回0*/
//	{
//		return 0;
//	}
//	*e = p->data;  /*保存结点值*/
//	return 1;    /*取元素成功，返回1*/
//}

//(4)定位操作（返回双链表head中第1个值为x的结点的位置）
//dlink* locate(dlink* head, ElemType x)
//{
//	dlink* p;
//	p = head->next;
//	while (p != NULL && p->data != x) /*从第1个结点开始查找值为x的结点*/
//	{
//		p = p->next;
//	}
//	return p; /*没找到返回NULL，否则返回该值结点的指针*/
//}

//(5)删除操作（删除双链表head中的第i个结点）
//int delete(dlink* head, int i, ElemType* e)
//{
//	dlink* p, * q, int j;
//	if (i < 1)  /*参数i不正确，删除失败，返回0*/
//	{
//		return 0;
//	}
//	p = head;  //p指针指向头结点
//	j = 0;
//	while (p->next!NULL && j < i - 1) /*从第1个结点开始查找第i-1个结点，由p指向它*//
//	{
//		p = p->next;
//		j++;
//	}
//	if (p->next == NULL) /*i值超过表长，返回0*/  //如果p指针的下一个结点为尾结点，意味着循环了一遍还没找到i。
//	{
//		return 0;
//	}
//	q = p->next;/*q指向第i个结点*/
//	p->next = q->next;
//	if (q->next != NULL)   //如果删除结点的下一个结点不为尾结点
//	{
//		q->next->prior = p;
//	}
//	*e = q->data;  //如果是尾结点，直接删除。//用e存储删除结点的元素
//	free(q);    /*释放第i个结点占用的空间*/
//	return 1;   /*删除成功，返回1*/
//}

//(6)插入操作（在双链表head中第i个结点之前插入一个值为x的结点）
//int insert(dlink* head.int i, ElemType x)
//{
//	dlink* p, * q;  //创建p，q两个结点
//	int j;     //定义一个整型j为计数器
//	if (i < 1)  /*参数i不正确，插入失败，返回0*/
//	{
//		return 0;
//	}
//	p = head;  //p指向头结点
//	j = 0;     
//	while (p != = NULL && j < i - 1) /*从第1个结点开始查找第i-1个结点，p指向它*/
//	{
//		p = p->next;  
//		j++;
//	}
//	if (p == NULL) //i值超过表长，返回0  //已经到尾结点还没找到要找的第i-1个结点
//	{
//		return 0;
//	}
//	q = (dlink*)malloc(sizeof(dlink)); /*创建值为x的结点q*/
//	q->data = x;   //给新建的结点赋值
//	q->next = p->next; /*插入新结点*/  //q指针当前结点的下一个结点为p指针的下一个结点
//	q->prior = p;  //q指针当前结点的前驱为p指针所在结点
//	if (p->next != NULL)   //如果p结点的下一个结点不为尾结点
//	{
//		p->next->prior = q; //p当前结点的下一个结点前驱为q结点
//	}
//	p->next = q;  //如果p结点的下一个结点为尾结点，p当前结点的下一个结点就为q结点
//	return 1; /*插入成功返回1*/
//}

//(7)输出操作（从两个方向输出双链表head中各结点的值）
//void list(dlink* head)
//{
//	dlink* p;
//	p = head; //p指针从头结点开始
//	while (p->next!=NULL) /*先正向输出链表元素值*/ //直到p结点的下一个结点为尾结点循环结束
//	{
//		printf("%4d", p->next->data); //四位数字对齐，输出p结点的下一个结点的元素
//		p=p->next
//	}
//	printf("\n");
//	while (p!=NULL)   //直到p指针指到尾结点循环结束
//	{
//		printf("%4d", p->data); //四位数字对齐，输出p指针当前的结点元素
//		p = p->prior;  //p指针向前移动
//	}
//}

//例2.12 有一个带头结点的双链表，其结点值为整数。设计一个算法，把所有值不小于0的结点放在所有值小于0的结点之前。
//void main(dlink *head)
//{
//	ElemType temp;  //定义任意变量temp来交换两个结点的元素
//	dlink* p, * q;
//	p = head->next;    /*让p指向第1个结点*/
//	for (q = head; q->next != NULL; q = q->next); /*让q指向尾结点*/  //q从头结点开始，直到q的下一个结点为尾结点循环结束
//	while (p != q)  //直到p指针与q指针相遇，循环停止
//	{
//		while (p->data >= 0 && p != q) /*从头向尾找负数*/  //p指针当前结点元素值为正数，并且p、q两指针没有相遇，循环继续
//		{
//			p = p->next;   //p指针向后移动
//		}//从头找到表中的负数，换q指针运动
//		while (q->data < 0 && p != q) /*从尾向头找正数*/  //q指针当前结点元素值为负数，并且p、q两指针没有相遇，循环继续
//		{
//			q = q->prior;  //q指针向前移动
//		}//从尾找到表中的正数，p、q两指针互换
//		if (p!=q)  /*若p与q未相遇，则交换*/ //交换的是两个指针所在结点的元素
//		{
//			temp = p->data; //p结点的元素先赋值给temp
//			p->data = q->data; //q结点的元素交给p结点，此时p结点元素值等于q结点元素值
//			q->data = temp;     //再把temp存储原本p结点元素值赋值给q指针所在结点
//			p = p->next; /*p后移一步*/ 
//		}
//	}
//}

//2.3.4 静态链表
//1、静态链表

//静态链表：借用一维数组来描述的链表
//数据域：结点的一部分用来存放数据信息
//指针域（游标）：结点的另一部分用来存放其后继结点在数组中的相对位置（下标）

//静态链表描述
//typedef int ElemType;/*在实际中，根据需要定义所需的数据类型*/
//#define MAXSIZE 100 /*静态链表的最大长度，根据实际情况定义*/
//typedef struct 
//{
//	ElemType data;
//	int cur;  /*游标，指向后继结点的存储位置*/
//}stalink[MAXSIZE];

//2、基本操作在静态链表上的实现
//(1)初始化操作（建立一个空的静态链表space）
//void initlist(stalink space)
//{
//	int i;
//	for (i = 0; i < MAXSIZE - 1; i++) 
//	{
//		space[i].cur = i + 1; //数组第i个的游标为i+1
//	}
//	space[MAXSIZE - 1].cur = 0;  //数组最后一个的游标为0
//}

//(2)获取结点函数allocnode()
//int allocnode(stalink space) 
//{
//	int i; //获取一个下标
//	i = space[0].cur; //将备用链表头结点的游标赋值给i
//	if (i == 0)     //如果备用链表头结点的游标为0意味着表满
//	{
//		return 0; /*备用链表空间已空，分配空间失败*/
//	}
//	space[0].cur = space[i].cur;  //若表未满，则将第i个结点的游标值赋值给备用表头结点的游标
//	return i;  /*分配成功，返回结点下标*/
//}

//(3)回收结点函数freenode()
//	void freenode(stalink space, int i)
//{
//	space[i].cur = space[0].cur; //备用链表头结点的游标值赋值给第i个结点的游标
//	space[0].cur = i;            //备用表头结点的游标值变为i
//}

//(4)建立静态链表（建立一个含有n个结点的静态链表head）
//int crestalink(stalink space, int n)
//{
//	int head, k, s, i;  //head就是头结点，k相当于一个指针，s也相当于一个指针
//	k = head = allocnode(space); //分配一个空间给s指针当为头结点
//	for (i=1;i<=n;i++) //建立从第1个结点，到第n个结点的静态链表
//	{
//		s = allocnode(space);     //分配一个空间给s指针
//		scanf("%d", &space[s].data);  //将输入的值赋给第s个结点的数据域
//		space[k].cur = s;            //k指针所在结点的游标指向指针s所在结点的下标
//		k = s;                     //k指针移动到s指针所在结点
//	}//静态链表建立完成后结束循环
//	space[k].cur = 0;   //最后一个结点的游标要指到备用链表的下标
//	return head;   //返回头结点
//}

//(5)求表长操作（计算静态链表head中数据元素的个数）
//	int getlen(stalink space, int head) /*head为链表头结点的下标*/
//	{
//		int i, k;        //定义一个整型i来计数表长
//		k = space[head].cur;  //头结点的游标赋值给k （相当于k指针指向头结点的下一个结点）
//		i = 0;
//		while (k!=0)        //若k不等于0循环继续
//		{
//			i++;    
//			k = space[k].cur;    //将第k个结点的游标赋值给k（相当于k指针移向下一个结点）
//		}//当k为0时（到尾结点时）循环结束
//		return i;  //返回表长
//	}

//(6)取元素操作（取出静态链表head中的第i个结点的元素值）
//	int getelem(stalink space, int head, int i, ElemType* e)
//	{
//		int j, k;
//		if (i < 1)  /*参数i不合法*/
//		{
//			return 0;
//		}
//		j = 0;
//		k = head;  //k指针指向头结点
//		while (k!=0&&j<i) /*从静态链表的第1个结点开始查找第i个结点，其下标存入k*/  //k不等于0（k指针没有指到尾结点）且j小于i时循环继续
//		{
//			j++;
//			k = space[k].cur;//k指针移到下一个结点
//		}
//		if (k==0) /*参数i超过表长*/ //如果循环一遍还没找到第i个结点，返回0
//		{
//			return 0;
//		}
//		*e = space[k].data; //找到第i个结点，将结点的数据元素存放到e中
//		return 1;/*读取元素成功，返回真值*/
//	}

//(7)定位操作（确定静态链表head中第1个值为x的结点的位置）
//	int locate(stalink space, int head, ElemType x)
//	{
//		int k;
//		k = space[head].cur;  //k的值等于头结点的游标值
//		while (k!=0&&space[k].data!=x)  //如果k不等于0（k指针没指到尾结点）且没有结点的数据域的值等于x，循环继续
//		{
//			k = space[k].cur; //k指针移向下一个结点
//		}
//		return k; /*不存在，返回0，否则返回下标*/
//	}

//(8)插入操作（在静态链表中head的第i个结点之前插入一个值为x的新结点）
//	int insert(stalink space, int head, int i, ElemType x)
//	{
//		int j, k, m;
//		if (i < 1)  /*参数i不合法，插入失败，返回0*/
//		{
//			return 0;
//		}
//		k = head; //k指针指向头结点
//		j = 0;
//		while (k!=0&&j<i-1) /*从第1个结点开始查找第i-1个结点，其下标存入k*/ //k不为0（k不指向尾结点）且j小于所要插入位置的前一个位置
//		{
//			j++;
//			k = space[k].cur;//k指针向后移动
//		}
//		if (k == 0) //循环结束后，如果k指针指到尾结点，还没找到第i-1个结点，返回0
//		{
//			return 0;
//		}
//		m = allocnode(space); /*从备用链表中获取结点，结点下标为m*/  //分配空间给m指针
//		if (m!=0)  /*若m不为0，取结点成功，开始插入*/ 
//		{
//			space[m].cur = space[k].cur; //将当前k指针指向的结点游标值赋值给新建结点的游标值
//          space[k].cur = m;    //结点k的游标值为m
//			return 1;  /*插入成功，返回1*/
//		}
//		else 
//		{
//			return 0;/*无可用空间*/
//		}
//	}

//(9)删除操作（将静态链表head中的第i个结点删除）
//	int delete(stalink space, int head, int i, ElemType* e)
//	{
//		int j, k, m;
//		if (i < 1) /*参数i不合法，删除失败，返回0*/
//		{
//			return 0;
//		}
//		k = space[head].cur; //k的值为头结点的游标值
//		j = 0;
//		while (k!=0&&j<i-1)  /*从第1个结点开始查找第i-1个结点，其下标存入k*/ //k不为0（k不指向尾结点）且j小于所要插入位置的前一个位置
//		{
//			j++;
//			k = space[k].cur;  //k指针向后移动到下一个结点
//		}
//		if (k==0)  //循环结束后，如果k等于0（k指针指向尾结点），返回0
//		{
//			return 0;
//		}
//		m = space[k].cur; /*m为第i个结点的下标*/ //此时的m赋值后为要删除的结点i
//		space[k].cur = space[m].cur; /*将第i个结点删除*/  //用要删除结点的前一个结点的游标值等于要删除结点的游标值
//		*e = space[m].data; //用e存储要删除的结点元素
//		freenode(space, m); //将删除的结点放到备用链表中
//		return 1; /*删除成功，返回1*/
//	}

//(10)输出操作（从头结点开始，依次输出静态链表head中的所有元素值）
//	void list(stalink space, int head)
//	{
//		int i;
//		i = space[head].cur; //头结点的游标值赋给i
//		while (i!=0)   //直到i的值为头结点游标的值，循环结束
//		{
//			printf("%4d", space[i].data);  //四位数对齐，输出第i个结点的元素
//			i = space[i].cur;      //将第i个结点的游标值赋值给i（实现从一个结点向下一个结点的移动）
//		}
//		printf("\n");
//	}

//例2.13 已知A和B是两个集合，元素类型都为整型，编写算法，建立表示集合（A-B）∪（B-A）的静态链表
//	void mergesetAB(stalink space, int A, int B)
//	{
//		int i, j, k;
//		ElemType x;
//		j = space[B].cur;  //将静态链表B的游标值赋值给j
//		while (j != 0)  //一直到j的值为头结点的游标值（相当于循环到尾结点），循环结束
//		{
//			getelem(space, j, &x);  //获取B表上的元素值
//			i = locate(space, A, x);  /*在静态链表A中查找集合B中的数据元素x*/
//			if (i==0) 
//			{
//				insert(space, A, i, &x);/*如果不存在，在A中插入值为x的结点*/
//			}
//			else 
//			{
//				delete(space, A, i, &x);/*如果存在，在A中删除值为x的结点*/
//			}
//		}
//		list(space, A); //输出A∪B后的链表A
//	}