//练习1.3：编写程序，在标准输出上打印Hello, World。
/*#include<iostream>
int main()
{
	std::cout << "Hello, World" << std::endl;
	return 0;
}*/

//练习1.4：
//使用加法运算符+来将两个数相加。
/*#include<iostream>
int main() 
{
	int v1=0, v2=0;
	std::cin >> v1 >> v2;
	std::cout << v1 << "+" << v2 << "=" << v1 + v2 << std::endl;
	return 0;
}*/

//使用乘法运算符*来打印两个数的积
/*#include<iostream>
int main() 
{
	int v1 = 0,v2 = 0;
	std::cin >> v1 >> v2;
	std::cout << v1 << "*" << v2 << "=" << v1 * v2<<std::endl;
	return 0;
}*/

//练习1.6 
//std::cout<<"The sum of "<< v1;
//         <<" and "<< v2;
//         <<" is "<<v1+v2<<std::endl;
//不合法的，“；”终止符，并没有将后两句都输出
