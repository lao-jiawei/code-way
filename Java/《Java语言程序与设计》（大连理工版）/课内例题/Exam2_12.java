package ÀıÌâ;

public class Exam2_12 {
	public static void main(String[] args) 
	{
		int a[][]= {{1,2,3},{4,5,6},{7,8,9}};
		int i,j;
		int sum=0;
		for(i=0;i<3;i++) 
			for(j=0;j<3;j++)
				if(i==j)
					sum=sum+a[i][j];
		System.out.println(sum);
	}
}
