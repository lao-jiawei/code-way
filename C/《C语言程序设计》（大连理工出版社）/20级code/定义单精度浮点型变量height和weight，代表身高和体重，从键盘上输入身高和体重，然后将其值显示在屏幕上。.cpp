#include<stdio.h>
main()
{
	float height,weight; //定义变量
	scanf("%f%f",&height,&weight); //输入两个值到变量中去
	printf("您好:\n");  //输出固定的字符串
	printf("您的身高是：%f\n",height); //输出变量height的值
	printf("您的体重是：%f\n",weight); //输出变量weight的值
	printf("%f,%f\n",height,weight);//一次将两个变量的值输出
}