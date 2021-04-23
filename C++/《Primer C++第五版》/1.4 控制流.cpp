//1.4.1 while 语句
//求1到10这十个数之和：
/*#include<iostream>
int main()
{
	int sum = 0, va1 = 1;
	//只要va1的值小于等于10，while循环就会持续执行
	while (va1<=10)
	{
		sum += va1;//将sum +va1赋予sum
		++va1;     //将va1加1
	}
	std::cout << "Sum of 1 to 10 inclusive is "
		<< sum << std::endl;
	return 0;
}*/


//1.4.1 节练习
//练习1.9：编写程序，使用while循环将50到100的整数相加。
/*#include<iostream>
int main() 
{
	int sum = 0, va1 = 50;
	//只要va1的值小于等于100，while循环就会持续进行
	while (va1<=100)
	{
		sum += va1;
		++va1;
	}
	std::cout << "Sum of 50 to 100 inclusive is "
		<< sum << std::endl;
	return 0;
}*/

//练习1.10 使用递减运算在循环中递减顺序打印出10到0之间的整数
/*#include<iostream>
int main()
{
	using namespace std;
	int i = 10;
	cout << "从10到0之间的整数为：" <<endl;	
	while (i>0)
	{
		cout << "i: "<<i<<endl;
		i--;
	}
	return 0;
}*/

//练习1.11：编写程序，提示用户输入两个整数，打印出这两个整数指定的范围内的所有整数
/*#include<iostream>
int main()
{
	using namespace std;
	int a=0, b=0;
	cout << "请输入两个整数：" ;
	cin >> a >> b;
	if (a > b)
	{
		int t=0;
		t = a;
		a = b;
		b = t;
	}
	cout << "The number between " << a << " to " << b << " is:"<<endl;
	for (int i=a;i<=b;i++) 
	{
		cout << i<<endl;
	}
	return 0;
}*/


//1.4.2 for 语句
//用for语句来重写从1加到10的程序
/*#include<iostream>
int main()
{
	int sum = 0;
	//从1加到10
	for (int val = 1; val <= 10; ++val)
		sum += val;//等价于 sum = sum +val
		std::cout << "Sum of 1 to 10 inclusive is "
			<< sum << std::endl;
		return 0;
}*/


//1.4.2节练习
//练习：1.12：下面的for循环完成了什么功能？sum的终值是多少？
// int sum = 0；
// for（int i = -100;i <= 100;++i）  //从-100加到100的和
//     sum+=i;                       //sum的最终值为0

//练习：1.13使用for循环重做1.4.1节中的所有练习
//（1）编写程序，使用for循环将50到100的整数相加
/*#include<iostream>
int main()
{
	using namespace std;
	int a = 50, sum = 0;
	for (int i =a;i<=100;++i) 
	{
		sum += i;
	}
	cout << "Sum of 50 to 100 inclusive is " << sum << endl;
	return 0;
}*/

//(2）编写程序，使用递减运算符在循环中按递减顺序打印出10到0之间的整数。
/*#include<iostream>
int main()
{
	using namespace std;
	int a = 10;
	for (int i = a; i > 0; i--)
	{
		cout << i << endl;
	}
	return 0;
}*/

//(3)编写程序，提示用户输入两个整数，打印出这两个整数所指定的范围内所有整数。
/*#include<iostream>
int main()
{
	using namespace std;
	int a = 0, b = 0;
	cout << "请输入两个整数：";
	cin >> a >> b;
	if (a > b) 
	{
		int t;
		t = a;
		a = b;
		b = t;
	}
	cout << "The number between " << a << " to " << b << " is: " << endl;
	for (int i = a; i <= b; i++) 
	{
		cout << i << endl;
	}
	return 0;
}*/

//练习1.14:对比for循环和while循环，两种形式的优缺点各是什么。
//for循环：优点：1、
//         缺点：1、
//while循环：优点：1、
//           缺点：1、

//练习1.15：编写程序，包含第14页“再探编译”中讨论中的常见错误。学习编译器生成的错误信息。


//1.4.3读取量不定的输入数据
//预先不知道要对多少个数求和，需要不断的读取数据直至没有新的输入为止。
/*#include<iostream>
int main()
{
	int sum = 0, value = 0;   //定义sum 和 value 的int 变量，初始化为0
	//读取数据直到遇到文件尾，计算所有读入的值的和
	while (std::cin >> value)    //保存用户输入的每一个数
		sum += value;//等价于sum= sum + value 
	std::cout << "Sum is:" << sum << std::endl;
	return 0;
}*/

//1.4.4 if语句
//用if语句，来统计在输入中每个值连续出现了多少次：
/*#include<iostream>
int main()
{
	//currVal 是我们正在统计的数；我们将读入的新值存入val
	int currVal = 0, val = 0;
	//读取第一个数，并确保确实有数据可以处理
	if(std::cin>>currVal)
	{
		int cnt = 1;   //保存我们正在处理的当前的个数
		while (std::cin>>val) //读取剩余的数
		{
			if (val==currVal) //如果值相同
			{
				++cnt;        //将cnt加1
			}
			else
			{
				std::cout << currVal << " occurs "
					<< cnt << " times" << std::endl;
				currVal = val;//记住新值
				cnt = 1;//重置计数器
			}
		}//while循环在这里结束
		//记住打印文件中最后一个值的个数
		std::cout << currVal << " occurs"
			<< cnt << " times" << std::endl;
	}//最外层的if语句在这里结束
	return 0;
}*/

//1.4.4节练习
//练习1.17：如果输入的所有值都是相等的，本节的程序会输什么？如果没有重复值，输出又会是怎么样的？
//          如果输入的所有值都是相等的：显示“xxx occurs xxx times”
//          如果没有重复值:每一个值出现的次数都是1显示出来

//练习1.18：编译并运行本节的程序，给它输入全部相同的值。再次运行程序，输入没有重复的值。
//          给它输入全部相同的值：没有显示
//          输入没有重复的值：每一个值出现的次数都是1显示出来

//练习1.19：修改你为1.4.1节练习1.10所编写的程序（打印一个范围内的数），使其能处理用户输入的第一个数比第二个数小的情况。
/*#include<iostream>
int main()
{
	using namespace std;
	int a = 0, b = 0;
	cout << "请输入两个整数：";
	cin >> a >> b;
	if (a > b)
	{
		int t;
		t = a;
		a = b;
		b = t;
	}
	cout << "The number between " << a << " to " << b << " is: " << endl;
	for (int i = a; i <= b; i++)
	{
		cout << i << endl;
	}
	return 0;
}*/