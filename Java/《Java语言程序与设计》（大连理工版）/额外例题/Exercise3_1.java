package 额外例题;

class StaticDemo{
	static int x;
	int y;
	public static int getX() {
		return x;
	}
	public static void setX(int newX) {
		x=newX;
	}
	public int getY() {
		return y;
	}
	public void setY(int newY) {
		y=newY;
	}
}
public class Exercise3_1 {
	public static void main(String[] args) {
		System.out.println("静态域x="+StaticDemo.getX());
//		//提示：该语句非法，编译时出错，请分析为什么？
//		System.out.println("实例域y="+StaticDemo.getY());
		StaticDemo a = new StaticDemo();
		StaticDemo b = new StaticDemo();
		a.setX(1);
		a.setY(2);
		b.setX(3);
		b.setY(4);
		System.out.println("静态域a.x="+a.getX());
		System.out.println("实例域a.y="+a.getY());
		System.out.println("静态域b.x="+b.getX());
		System.out.println("实例域b.y="+b.getY());
		
		}
}
