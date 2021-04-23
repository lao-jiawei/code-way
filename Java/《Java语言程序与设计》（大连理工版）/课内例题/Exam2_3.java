package 例题;
import java.util.Scanner;  //调用读取函数
public class Exam2_3 {
	public static void main(String[] args) {
		Scanner reader = new Scanner(System.in); //Scanner 读取所给数
		double count=0,price=0;
		System.out.print("请输入电量：");
		count=reader.nextDouble();   //将读取的数给count赋值
		if(count>=1&&count<=90)
			price=0.6*count;
		if(count>91&&count<=150)
			price=0.6*90+1.1*(count-90);
		if(count>=151)
			price=0.6*90+1.1*60+1.7*(count-150);
		System.out.println(price); //直接输出price
	}
}
