package hello;
import java.util.Scanner;

public class 自动售票机 {
	//	自动售票机
	public static void main(String[] args) {
		//初始化
		Scanner in =new Scanner(System.in);
		int balance=0;
		//	读入投币金额
		while(true)
		{
			System.out.println("请投币：");
			int amount = in.nextInt();
			balance=balance+amount;
			System.out.println(amount);
			if(balance>=10)
			{
				//	打印车票
				System.out.println("********************");
				System.out.println("* Java城际铁路专线 *");
				System.out.println("*   无指定座位票   *");
				System.out.println("*   票价： 10元    *");
				System.out.println("********************");
				//	计算并打印找零
				System.out.println("找零："+(amount-10));
				balance=0;
			}
			else 
			{
				balance=balance+amount;
			}
		}	
	}
}
