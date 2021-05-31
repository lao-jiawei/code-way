package 额外例题;

public class Circle { 
	private double r;
	public Circle() {
		r=1;
	}
	public Circle(double rr) {
		r=rr;
	}
	public double getArea() {
		return 2*Math.PI*r*r;
	}
	public double getCircum() {
		return 2*Math.PI*r;
	}

	public static void main(String[] args) {
		Circle c1=new Circle(3.1);
		Circle c2=new Circle();
		System.out.println("圆形C1的面积为："+c1.getArea());
		System.out.println("圆形C1的周长为："+c1.getCircum());
		System.out.println("圆形C2的面积为："+c2.getArea());
		System.out.println("圆形C2的周长为："+c2.getCircum());
}
}
