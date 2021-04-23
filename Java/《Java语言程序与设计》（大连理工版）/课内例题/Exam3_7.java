package 例题;

class A{  //父类
	int i,j; //定义了两个成员变量i，j
	void showij() {  //定义了一个成员方法：用来显示成员变量i、j的值
		System.out.println("i and j:"+i+" "+j);	
	}
}
class B extends A{ //B类继承A类（B类是A类的子类）
	int k;  //定义了一个成员变量k
	void showk() {  //成员方法：显示k的值
		System.out.println("k:"+k);
	}
	void sum() {  //成员方法：计算变量i、j、k的和
		System.out.println("i+j+k:"+(i+j+k));
	}
}

public class Exam3_7 {  //主类
	public static void main(String[] args) {
		A father =new A();  //father 父类对象
		B son = new B();    //son 子类对象
		father.i=10;father.j=20; //将父类中的成员变量赋值
		father.showij();  //显示父类成员变量数值
		son.i=7;son.j=8;son.k=9; //将子类中的成员变量赋值
		son.showij(); //子类继承父类的成员方法，并显示修改父类成员变量i、j的数值
		son.showk();  //子类显示自己的成员变量k的数值
		son.sum();  //子类计算i+j+k的和
		}
}
