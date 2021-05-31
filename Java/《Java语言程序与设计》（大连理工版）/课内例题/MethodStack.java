package ÀýÌâ;

public class MethodStack {
	int[] arr = new int[3];
	public void methodOne()
	{
		methodTwo();
		System.out.println("One");
	}
	public void methodTwo()
	{
		methodThree();
		System.out.println("two");
	}
	public void methodThree()
	{
		System.out.println(arr[3]);
		System.out.println("three");
	}
	public static void main(String[] args)
	{
		new MethodStack().methodOne();
		System.out.println("main");
	}
}
