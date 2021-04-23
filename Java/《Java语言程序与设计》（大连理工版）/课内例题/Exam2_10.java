package 例题;

public class Exam2_10 {
	public static void main(String[] args) 
	{
		int count;
		for(count=1;count<=10;count++) {
			if(count ==5)continue;
			System.out.println(count);
		}
		System.out.println("循环中断的数是:"+count);
	}
}
