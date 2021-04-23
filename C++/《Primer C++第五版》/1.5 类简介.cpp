//1.5.1 Sales_item 类
//读写Sale_item
/*#include<iostream>      //包含来自标准库的头文件用（<>）包围头文件名
#include"Sales_item.h"    //对于不属于标准库的头文件，则用双引号（""）包围
int main() 
{
	Sales_item book;
	//读入ISBN号、售出的册数以及销售价格
	std::cin >> book;
	//写入ISBN、出售的册数、总销售额和平均价格
	std::cout << book << std::endl;
	return 0;
}*/
 
//Sales_item 对象的加法
/*#include<iostream>
#include"Sales_item.h"
int main()
{
	Sales_item item1, item2;
	std::cin >> item1 >> item2;  //读取一对交易记录
	std::cout << item1 + item2 << std::endl; //打印它们的和
	return 0;
}*/

//1.5.1节练习
//练习1.20：读取一组书籍销售记录，将每条记录打印到标准输出上。
/*#include<iostream>
#include"Sales_item.h"
int main(int argc,char** argv)
{
	using namespace std;
	Sales_item item;
	while(cin>>item)
	cout << item << endl;
	return 0;
}*/

//练习1.21：编写程序，读取两个ISBN相同的Sales_item对象，输出它们的和。
/*#include<iostream>
#include"Sales_item.h"
int main(int argc,char** argv) 
{
    using namespace std;
	Sales_item item1, item2;
	cin >> item1 >> item2;  //读取一对交易记录
	if (item1.isbn() == item2.isbn())
	{
		cout << item1 + item2 << endl;
	}
	else
	{
		cout << "输入的两个ISBN不相同" << endl;
	}
	return 0;
}*/

//练习1.22：编写程序，读取多个具有相同ISBN的销售记录，输出所有记录的和。
/*#include<iostream>
#include"Sales_item.h"
int main(int argc,char** argv)
{
	using namespace std;
	Sales_item item1,item2;
	while (cin>>item2)
	{
		item1 += item2;
	}
	cout << item1 << endl;
	return 0;
}*/

//1.5.2初识成员函数
//将两个Sales_item对象相加的程序首先应该检查两个对象是否具有相同的ISBN
/*#include<iostream>
#include"Sales_item.h"
int main()
{
	Sales_item item1, item2;
	std::cin >> item1 >> item2;
	//首先先检查item1和item2是否表示相同书
	if (item1.isbn() == item2.isbn()) 
	{
		std::cout << item1 + item2 << std::endl;
		return 0; //表示成功
	}
	else 
	{
		std::cerr << "Data must refer to sam ISBN"
			<< std::endl;
		return -1; //表示失败
	}
}*/

//1.5.2节练习
//练习1.23：读取多条销售记录，并统计每个ISBN（每本书）有几条销售记录。
//未分析
/*#include<iostream>
#include"Sales_item.h"
int main()
{
	Sales_item  trans1, trans2;
	int num = 1;                                        // 计数
	std::cout << "请输入若干条销售记录"
		<< std::endl;
	if (std::cin >> trans1) {                          // 判断是否输入了销售记录 并将第一条销售记录赋值于 trans1 中 
		while (std::cin >> trans2) {                   // 再经过一次循环后，再次将下一组数据赋值于 trans2 中
			if (compareIsbn(trans1, trans2)) {         // 判断 trans1 ，trans2 是否相同
				++num;
				std::cout << trans1.isbn() << "共有"
					<< num << "条销售记录" << std::endl;
			}
			else {
				std::cout << "没有数据！"
					<< std::endl;
				return -1;
			}
		}
	}
	return 0;
}*/

//练习1.24：输入表示多个ISBN的多条销售记录来测试上一个程序，每一个ISBN的记录应该聚在一起

