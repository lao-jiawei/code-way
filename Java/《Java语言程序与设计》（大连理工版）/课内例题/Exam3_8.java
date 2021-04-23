package 例题;
class A8{
	int i,j;
	void showij() {
		System.out.println("i and j:"+i+" "+j);
	}
}
class B8 extends A8{ //B类继承A类
	int k;
	int i,j;  //隐藏父类变量i、j
	void showk() {
		System.out.println("k:"+k);
	}
	void sum() {
		System.out.println("i+j+k:"+(i+j+k));
	}
}
public class Exam3_8 {
	public static void main(String[] args) {
		A8 father =new A8();
		B8 son =new B8();
		father.i=10;father.j=20;
		father.showij();
		son.i=7;son.j=8;son.k=9;
		son.showij();
		son.showk();
		son.sum();
	}
}
