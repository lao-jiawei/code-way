/*//2.5.1 约瑟夫环问题
//约瑟夫环源代码
#include<stdio.h>
#include<stdlib.h>
#define MAX 100
typedef struct NodeType  //自定义结构体类型
{
	int id; //编号
	int password; //密码
	struct NodeType* next; //用于指向下一个结点的指针
}NodeType;

//函数声明
void CreatList(NodeType**, int);//创建单向循环链表
NodeType* GetNode(int, int);//得到一个结点
void PrntList(NodeType*);//打印循环链表
int IsEmptyList(NodeType*);//测试链表是否为空
void JosephusOperate(NodeType**, int);//运行“约瑟夫环”问题

//主函数
int main(void) 
{
	int n = 0; //定义一个整型n为人数
	int m = 0; //定义一个整型m为初始密码
	NodeType* pHead = NULL;  //建立pHead指针
	do 
	{
		if (n > MAX)
		{
			//人数n超过最大人数循环，接着做下一次循环，重新输入人数n，直至满足条件为止
			printf("人数太多，请重新输入！\n");
		}
		printf("请输入人数n（最多%d个）:", MAX);
		scanf("%d", &n);
	} while (n > MAX);
	printf("请输入初始密码m:");
	scanf("%d", &m);
	CreatList(&pHead, n); //创建单向循环链表
	printf("\n-----------打印循环链表-----------\n");
	PrntList(pHead); //打印循环链表
	printf("\n-----------打印出队情况-----------\n");
	JosephusOperate(&pHead, m);
	return 1;
}

//函数代码
void CreatList(NodeType** ppHead, int n) //创建有n个结点的循环链表ppHead  //读取：（总人数n）
{
	int i = 0;  //定义一个整型i为人数
	int iPassword = 0;  //定义一个整型iPassword为个人密码
	NodeType* pNew = NULL;    //建立pNew指针，来指向新建结点
	NodeType* pCur = NULL;    //建立pCur指针
	for (i=1;i<=n;i++)   //依次录入每一个学生的个人密码
	{
		printf("输入第%d个人密码：", i);
		scanf("%d", &iPassword);
		pNew = GetNode(i, iPassword); //结点存储着学生id和学生密码
		if (*ppHead==NULL)  //如果*ppHead指针指向的为空结点
		{
			*ppHead = pCur = pNew; //让三个指针都指向新建结点
			pCur->next = *ppHead; 
		}
		else 
		{
			pNew->next = pCur->next;
			pCur->next = pNew;
			pCur = pNew;
		}
	}
	printf("完成单向循环链表的创建!\n");
}

NodeType* GetNode(int iId, int iPassword) //向结点中传送编号和密码 //读取：（个人id，个人密码）
{
	NodeType* pNew = NULL; //建立指针
	pNew = (NodeType*)malloc(sizeof(NodeType)); //为当前结点开辟新空间
	if (!pNew) //如果开辟空间失败
	{
		printf("Error,the memory is not enough!\n");
		exit(-1);
	}
	pNew->id = iId;  //将个人id赋值给主链表上的id
	pNew->password = iPassword; //将个人密码赋值给主链表上的密码
	pNew->next = NULL; //pNew的next指向空，置空表尾
	return pNew; //返回指针？
}

void PrntList(NodeType* pHead) //依次输出至n个人，且输出密码，完成原始链表的打印
{
	NodeType* pCur = pHead;
	if (!IsEmptyList(pHead)) //调用EmptyList()函数来判断if语句是否执行，若pHead为空则执行
	{
		printf("--ID-- --PASSWORD--\n");
		do 
		{
			printf("%3d  %7d\n",pCur->id,pCur->password);
			pCur = pCur->next; //让指针变量pCur改为指向后继结点
		} while (pCur != pHead);
	}
}

int IsEmptyList(NodeType* pHead) 
{
	if (!pHead) 
	{
		//若pHead为空，提示“空”，返回真值
		printf("The list is empty!\n");
		return 1;
	}
	return 0;//否则返回0
}

void JosephusOperate(NodeType** ppHead, int iPassword)
{
	int iCounter = 0;
	int iFlag = 1;
	NodeType* pPrv = NULL;
	NodeType* pCur = NULL;
	NodeType* pDel = NULL;
	pPrv = pCur = *ppHead;
	while (pPrv->next != *ppHead) 
	{
		pPrv = pPrv->next; //将pPrv初始为指向尾结点，为删除结点做好准备
	}
	while (iFlag) 
	{
		for (iCounter = 1; iCounter < iPassword;iCounter++)
		{
			pPrv = pCur;
			pCur = pCur->next;
		}
		if (pPrv == pCur) 
		{
			iFlag = 0;
		}
		pDel = pCur;      //删除pCur指向的结点，即有人出列
		pPrv->next = pCur->next; //使得pPrv指向结点域下下个结点相连，让pCur从链表中脱节
		pCur = pCur->next;//让指针pCur改为指向后继结点，后移一个结点
		iPassword = pDel->password; //记录出列的人手中的密码
		printf("第%d个人出列<密码：%d>\n", pDel->password,pDel->password);
		free(pDel); //释放删除pDel指向的结点
	}
	*ppHead = NULL;
	getchar();
}*/