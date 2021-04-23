package 例题;

public class Exam3_2 {
	public static void main(String[] args) 
	{
		var1 v1=new var1();
		var1 v2=new var1();
		v1.print();
		v2.print();
	}
}
class var1{
	static int a=1; //成员变量  a是静态变量
	int b=1; //成员变量 b是默认变量
	public void print() {
		int c=1; //c是在方法内的变量
		++a;
		++b;
		++c;
		System.out.println("a="+a);
		System.out.println("b="+b);
		System.out.println("c="+c);
	}
}
