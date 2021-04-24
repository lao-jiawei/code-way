//3.5.1 获得元素操作
//
//#define OK 1
//#define ERROR 0
//#define TRUE 1
//#define FALSE 0
//typedef int Status;
/*Status是函数的类型，其值四函数结果状态代码。如OK等*/
/*初始条件：顺序线性表L已存在，1<=i<=ListLength(L)*/
/*操作结果：用e返回L中第i个数据元素的值*/

//Status GetElem(SqList L, int i, ElemType* e)
//{
//	if (L.length == 0 || i<1 || i>L.length) {
//		return ERROR;
//	}
//	*e = L.data[i - 1];
//	return OK;
//}

//3.5.2 插入操作
/*初始条件：顺序线性表L已存在，1<=i<=ListLength(L)*/
/*操作结果：在L中第i个位置之前插入新的元素e，L的长度加1*/
//Status ListInsert(SqList* L, int i, ElemType e)
//{
//	int k;
//	if (L->length == MAXSIZE) /*顺序线性表已经满*/
//	{
//		return ERROR;
//	}
//	if (i<1 || i>L->length + 1)/*当i不在范围内时*/
//	{
//		return ERROR;
//	}
//	if (i <= L->length) /*若插入数据位置不在表尾*/
//	{
//		for (k = L->length - 1; k >= i - 1; k--) /*将要插入位置后数据元素向后移动一位*/
//		{
//			L->data[k + 1] = L->data[k];
//		}
//	}
//	L->data[i - 1] = e;/*将新元素插入*/  //将要插入元素填入位置i处
//	L->length++;     //表长加1
//	return OK;
//}

//3.5.3 删除操作
/*初始条件：顺序线性表L已存在，1<=i<=ListLength(L)*/
/*操作结果：在L中第i个位置之前插入新的元素e，L的长度减1*/
//Status ListDelete(SqList* L, int i, ElemType* e)
//{
//	int k;
//	if (L->length == 0) /*线性表为空*/
//	{
//		return ERROR;
//	}
//	if (i<1 || i>L->length) /*删除位置不正确*/
//	{
//		return ERROR;
//	}
//	*e = L->data[i - 1];
//	if (i < L->length)
//	{
//		for (k = i; k < L->length; k++)/*将删除位置后继元素前移*/
//		{
//			L->data[k - 1] = L->data[k];
//		}
//		L->length--;
//		return OK;
//	}
//}