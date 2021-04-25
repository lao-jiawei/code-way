package hello;
import java.util.Scanner;
public class 凑硬币 {
	public static void main(String[] args) {
		Scanner in = new Scanner(System.in);
		int amount = in.nextInt();
		OUT: //标号
		for( int one = 0; one<=amount; ++one)
		{
			for( int five = 0; five<=amount/5; ++five)
			{
				for( int ten = 0; ten<=amount/10; ++ten)
				{
					for( int twenty = 0; twenty<=amount/20; ++twenty)
					{
						if( one+five*5+ten*10+twenty*20 == amount)
						{
							System.out.println(one+"张1元，"+five+"张5元，"+ten+"张10元，"+twenty+"张20元->"+amount);
							break OUT;
						}
					}
				}
			}
		}
	}
}
