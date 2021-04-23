package 例题;
import java.util.Scanner; //程序导入JDK类库提供的Scanner类，该类可以获取从键盘输入的数据
public class Exam2_4 {
	public static void main(String[] args) 
	{
		Scanner input = new Scanner(System.in); //实例化一个对象input，System.in是参数
		System.out.println("请输入成绩");
		double score = input.nextDouble();//对象调用方法获取数据，input.nextDouble()是获取数据并赋值给score
		if(score>=90)
			System.out.println("你的成绩等级为：优秀");
		else if(score>=80) 
			System.out.println("你的成绩等级为：良好");
		else if(score>=70)
			System.out.println("你的成绩等级为：中等");
		else if(score>=60)
			System.out.println("你的成绩等级为：及格");
		else 
			System.out.println("你的成绩等级为：不及格");
	}
}
