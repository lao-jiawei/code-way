package 例题;
class myException extends Exception
{
	public myException()
	{
		super("我定义的异常");
	}
}
public class Exam5_4 {
	public static void mymethod1()throws myException
	{
		mymethod2();
	}
	public static void mymethod2()throws myException
	{
		myException ob = new myException();
		throw ob;
	}
	public static void main(String[] args)
	{
		try
		{
			mymethod1();
		}
		catch(myException e)
		{
			System.out.println(e.getMessage());
			e.printStackTrace();
			System.out.println("该异常的类型是"+e.getClass().getName());
		}
	}
}
