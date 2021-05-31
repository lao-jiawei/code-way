package 例题;

public class Exam5_2 {
	public static void main(String[] args)
	{
		fun(0);
		fun(1);
		fun(2);
	}
	static void fun(int i)
	{
		System.out.println("调用方法：fun("+i+")");
		try
		{
			if(i==0)
			{
				System.out.println("没有异常！");
			}
			if(i==1){int a=0;int b =0;b/=a;}
			if(i==2){int m[]=new int [5];m[5]=100;}
		}
		catch(ArithmeticException e)
		{
			System.out.println("捕捉到ArithmeticException异常！");
		}
		catch(ArrayIndexOutOfBoundsException e)
		{
			System.out.println("捕捉到ArrayIndexOutOfBoundsException异常！");
		}
		finally{System.out.println("处理完毕！");}
	}
}
