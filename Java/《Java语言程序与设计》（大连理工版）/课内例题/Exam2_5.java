package 例题;
import java.util.*;
public class Exam2_5 {
	public static void main(String[] args) 
	{
		Scanner input = new Scanner (System.in);
		System.out.println("请输入1~7的整数：");
		int day = input.nextInt();//对象调用方法获取数据
		switch(day) 
		{
		case 7:System.out.println("星期日");break;
		case 1:System.out.println("星期一");break;
		case 2:System.out.println("星期二");break;
		case 3:System.out.println("星期三");break;
		case 4:System.out.println("星期四");break;
		case 5:System.out.println("星期五");break;
		case 6:System.out.println("星期六");break;
		default:System.out.println("你输入的日期不在有效范围内！");
		}
	}
}
