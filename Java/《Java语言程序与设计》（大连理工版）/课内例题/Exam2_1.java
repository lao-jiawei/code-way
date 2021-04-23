package 例题;

public class Exam2_1 {
	public static void main(String[] args) {
		byte a;
		int b=325;
		double c =346.73;
		a=(byte)b; //b转byte类型
		System.out.println("int->byte:"+b+"->"+a);
		b=(int)c;//c转int类型
		System.out.println("double->int:"+c+"->"+b);
	}
}
