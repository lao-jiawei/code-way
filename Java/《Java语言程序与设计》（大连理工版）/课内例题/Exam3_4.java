package ÀıÌâ;
class C{
	int c;
	C(int a){
		c=0;
		for(int i=0;i<=a;i++)
			c+=i;
	}
	C(C b){
		c=b.c;
	}
}
public class Exam3_4 {
	public static void main(String[] args) {
		C c1=new C(6);
		C c2=new C(new C(4));
		System.out.println("c1:"+c1.c);
		System.out.println("c2:"+c2.c);
	}
}