package hello;
import java.util.Scanner;
public class 判断素数 {
	//判断素数
	public static void main(String[] args) {
		Scanner in = new Scanner(System.in);
//		int n = in.nextInt();
		for( int n = 2; n<100; n++) 
		{
			int isPrime = 1;
			for(int i=2;i<n;i++)
			{
				if( n % i == 0)
				{
					isPrime = 0;
					System.out.println(n+"不是素数,i="+i);
					break;
				}
			}
			if( isPrime == 1) 
			{
				System.out.println(n+"是素数");
			}
			else 
			{
//				System.out.println(n+"不是素数");
			}
		}
	}
		//判断是否能被已知的<x的素数整除
/*	public static void main(String[] args) {
			Scanner in = new Scanner(System.in);
			int[] primes = new int[50];
			primes[0]=2;
			int cnt =1;
			MAIN_LOOP:
			for(int x = 3;cnt<50;x++) 
			{
				for(int i=0;i<cnt;i++) 
				{
					if(x % primes[i]==0) 
					{
						continue MAIN_LOOP;
					}
					primes[cnt++]=x;
				}
				for(int k:primes) 
				{
					System.out.print(k+" ");
				}
			}
		}*/
		
}
