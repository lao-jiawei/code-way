//线性表的抽象数据蕾西定义
//ADT 线性表（List）
//Data
//	  线性表的数据对象集合为{a1，a2,......,an},每个元素的类型均位DataType。其中，除第
//    一个元素a1外，每一个元素有且只有一个直接前驱元素，除了最后一个元素an外，每一个
//    元素有且只有一个直接后继元素。数据元素之间的关系是一对一的关系。
//
//Operation
//     InitList(*L);         初始化操作，建立一个空的线性表。
//     ListEmpty(L);         若线性表为空，返回true，否则返回false。
//     ClearList(*L);        将线性表清空
//     GetElem(L,i,*e);      将线性表L中的第i个位置值返回给e。
//     LocateElem(L,e);      在线性表L中查找与给定值e相等的元素，如果查找成功，返回
//                           该元素在表中序号表示成功；否则，返回0表示失败。
//     ListInsert(*L,i,e);   在线性表L中的第i个位置插入新元素e。
//     ListDelete(*L,i,*e);  删除线性表L中第i个位置元素，并用e返回其值。
//     ListLength(L);        返回线性表L的元素个数。
//
//endADT

/*将所有的在线性表Lb中但不在La中的元素插入到La中*/
//void union(List* La, List* Lb)
//{
//	int La_len,Lb_len, i;
//	ElemType e; /*声明与La和Lb相同的数据元素e*/
//	La_len = ListLength(La);/*求线性表的长度*/
//	Lb_len = ListLength(Lb);
//	for (i=1;i<=Lb_len;i++) 
//	{
//		GetElem(Lb, i, e);/*取Lb中第i个数据元素赋给e*/
//		if (!LocateElem(La, e, equal))/*La中不存在和e相同数据元素*/
//		{
//			ListInsert(La, ++La_len, e);/*插入*/
//		}
//	}
//}