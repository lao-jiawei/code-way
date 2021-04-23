package ÀýÌâ;

public class Exam3_3 {
	static double d;
	public static void main(String[] args) {
		int i;
		Exam3_3 ob=new Exam3_3();
		i=5;
		ob.changeInt(i);
		System.out.println("i="+i);
		ob.d=6.25;
		ob.changeDouble(ob);
		System.out.println("d="+d);
		
		}
	public void changeInt(int v) {
		v=10;
	}
	public void changeDouble(Exam3_3 ref) {
		ref.d=10.5;
	}
}
