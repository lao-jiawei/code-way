package 额外例题;

class Point1{
	int x,y;
	public Point1(int x,int y) {
		this.x=x;
		this.y=y;
		System.out.println("父类Point:"+this.print());
	}
	public Point1() {
		this(1,1);
	}
	public String print() {
		return "["+x+","+y+"]";
	}
}
class Circle1 extends Point1{
	double r;
	public Circle1(double r,int x,int y) {
		super(x,y);	//调用父类的构造方法，必须做为第一条语句
		this.r=r;
		System.out.println("Cirle:"+this.print());
	}
	public String print() {
		return "子类Center="+super.print()+"	r="+r;
	}
}
public class Example4_5 {
	public static void main(String[] args) {
		Point1 p=new Point1();
		Circle1 circle=new Circle1(3.5,10,20);
		}
}
