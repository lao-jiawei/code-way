package 例题;

public class Exam2_9 {
	public static void main(String[] args)
	{
		int count;
		for(count =1;count<=10;count++) 
		{
			if(count ==5)break;
			System.out.println(count);
		}
		System.out.println("循环中断的数是："+count);
	}
}
