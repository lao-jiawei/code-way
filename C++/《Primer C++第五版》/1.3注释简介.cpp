//#include<iostream>
/*
* 简单主函数;
* 读取两个数，求它们的和
*/

/*int main()
{
	//提示用户输入两个数
	std::cout << "Enter two numbers:" << std::endl;
	int v1 = 0, v2 = 0; //保存我们读入的数据的变量
	std::cin >> v1 >> v2;//读取输入数据
	std::cout << "The sum of " << v1 << " and " << v2
		<< " is " << v1 + v2 << std::endl;
	return 0;
}*/

//1.3节练习
//练习1.7 编译一个包含不正确的嵌套注释的程序，观察编译器返回的错误信息。
//int main() 
//{
//	std::cout << "Hollow World!" << std::endl;/*输出/*hollow world*/*/
//	return 0;
//}

//练习1.8
//std::cout << "/*";    //不合法  //修改/*std::cout<<"/*"*/
//std::cout <<"*/";     //不合法  //修改/*std::cout<<"/*"*/
//std::cout <</*"*/"*/;  //不合法，注释不能嵌套 //修改 //std::cout <</*"*/"*/;
//std::cout <</*"*/"/*"/*"*/; //不合法，注释不能嵌套