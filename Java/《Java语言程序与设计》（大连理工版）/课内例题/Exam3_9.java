package 例题;
class A9{
	int i,j;
	void showij() {
		System.out.println("i and j:"+i+" "+j);
	}
}
class B9 extends A9{ //B类继承A类
	int k;
	int i,j; //隐藏父类变量
	void showk() {
		System.out.println("k:"+k);
	}
	void sum() {
		System.out.println("i+j+k:"+(i+j+k));
	}
	void showij() { //隐藏父类方法
		System.out.println("i and j:"+i+" "+j);
	}
}
public class Exam3_9 {
	public static void main(String[] args) {
		A9 father =new A9();
		B9 son=new B9();
		father.i=10;father.j=20;
		father.showij();
		son.i=7;son.j=8;son.k=9;
		son.showij();
		son.showk();
		son.sum();
		}
}
