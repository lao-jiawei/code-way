package 例题;

class Intsort{
	public String sort(int a,int b) {  //定义两个数排序方法
		if(a>b)return a+" "+b;
		else return b+" "+b;
	}
	public String sort(int a,int b,int c) { //定义三个数排序方法
		int swp;
		if(a<b) {swp=a;a=b;b=swp;}
		if(a<c) {swp=a;a=c;c=swp;}
		if(b<c) {swp=b;b=c;c=swp;}
		return a+" "+b+" "+c; 
	}
}

public class Exam3_5 { //定义主类考察Intsort类中的方法
	public static void main(String[] args) {
		Intsort s=new Intsort();
		System.out.println("两个数从大到小排序结果："+s.sort(1, 2));
		System.out.println("三个数从大到小排序结果："+s.sort(1, 2, 3));
		}
}
