package 例题;
interface N1{ //接口的声明
	int year=2020; //year默认为static final常量
	int age(); //无方法体，在使用时需加入方法体
}
public class Exam3_10 implements N1{
	String xm;
	int sr; //成员变量xm为姓名，sr为出生年份
	public static void main(String[] args) {
		Exam3_10 p1=new Exam3_10("张弛",2004);
		p1.output();
		}
	Exam3_10(String a,int b){ //构造方法
		xm=a;
		sr=b;
	}
	
	public int age() { //实现接口的方法，返回年龄值
		return year-sr;
	}
	
	public void output() { //实现接口方法,输出年龄
		System.out.println(xm+"的年龄为："+this.age());
	}
}
