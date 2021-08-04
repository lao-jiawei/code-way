package JAVA基础;

import java.util.Scanner;

import java.util.Arrays;

public class HelloWorld {
//练习-求和
//	public static void main(String[] args) {
//		Scanner s =	new	Scanner(System.in);
//		int a = s.nextInt();
//		System.out.println("第一个整数："+a);
//		int b = s.nextInt();
//		System.out.println("第二个整数："+b);
//		System.out.println("两个数的和是："+(a+b));
//	}
	
//练习-自增
//	public static void main(String[] args) {
//		int i = 1;
//		int j =++i + i++ + ++i + ++i + i++;
//		System.out.println(j);
//	}
	
//练习-BMI
//	public static void main(String[] args) {
//		double BMI;
//		Scanner s = new Scanner(System.in);
//		System.out.println("请输入身高（m）：");
//		double height = s.nextFloat();
//		System.out.println("请输入体重（kg）：");
//		double  weight = s.nextFloat();
//		BMI	=	weight/(height*height);
//		System.out.println("当前的BMI是："+BMI);
//		
//		if(BMI<18.5) {
//			System.out.println("体重过轻");
//		}
//		else if(BMI >=18.5 && BMI<24) {
//			System.out.println("正常范围");
//		}
//		else if(BMI >=24 && BMI<27) {
//			System.out.println("体重过重");
//		}
//		else if(BMI >=27 && BMI<30) {
//			System.out.println("轻度肥胖");
//		}
//		else if(BMI >=30 && BMI<35) {
//			System.out.println("中度肥胖");
//		}
//		else if(BMI >=35) {
//			System.out.println("重度肥胖");
//		}
//	}
	
//练习-关系操作符
//	public static void main(String[] args) {
//		Scanner s =	new Scanner(System.in);
//		int a = s.nextInt();
//		System.out.println("第一个整数："+a);
//		int b = s.nextInt();
//		System.out.println("第二个整数："+b);
//		
//		System.out.print("比较"+a+">"+b+"：");
//		if(a>b) 
//		{
//			System.out.println("true");
//		}
//		else {
//			System.out.println("false");
//		}
//		
//		System.out.print("比较"+a+">="+b+"：");
//		if(a>=b) 
//		{
//			System.out.println("true");
//		}
//		else {
//			System.out.println("false");
//		}
//		
//		System.out.print("比较"+a+"<"+b+"：");
//		if(a<b) 
//		{
//			System.out.println("true");
//		}
//		else {
//			System.out.println("false");
//		}
//		
//		System.out.print("比较"+a+"<="+b+"：");
//		if(a<=b) 
//		{
//			System.out.println("true");
//		}
//		else {
//			System.out.println("false");
//		}
//		
//		System.out.print("比较"+a+"=="+b+"：");
//		if(a==b) 
//		{
//			System.out.println("true");
//		}
//		else {
//			System.out.println("false");
//		}
//		
//		System.out.print("比较"+a+"!="+b+"：");
//		if(a!=b) 
//		{
//			System.out.println("true");
//		}
//		else {
//			System.out.println("false");
//		}
//	}
	
//练习-逻辑操作符
//	public static void main(String[] args) {
//		int i = 1;
//
//		boolean b = !(i++ == 3) ^ (i++ ==2) && (i++==3);
//
//		System.out.println(b);
//
//		System.out.println(i);
//	}
	
//练习-快速计算2x16
//	public static void main(String[] args) {
//		System.out.println(16<<1);
//	}
	
//练习-位操作符
//	public static void main(String[] args) {
//		int i = 3; // 二进制是11
//
//		int j = 2; // 二进制是10
//
//		int c = ((i | j) ^ (i & j)) << 2 >>> 1;
//		System.out.println(c);
//	}
	
//练习-赋值操作符
//	public static void main(String[] args) {
//		int i = 1;
//		i+=++i;
//		System.out.println(i);
//	}
	
//练习-判断是否是工作日
//	public static void main(String[] args) {
//		Scanner s = new Scanner(System.in);
//		System.out.println("今天是周几?");
//		int date = s.nextInt();
//		String massage = date < 6 ? "今天是工作日": "今天是周末";
//		System.out.println(massage);
//	}
	
//练习-闰年
//	public static void main(String[] args) {
//		Scanner s = new Scanner(System.in);
//		int year = s.nextInt();
//		if(year % 4 == 0 && year % 100 !=0 ) {
//			System.out.println(year+"是闰年");
//		}
//		else if(year % 400 == 0) {
//			System.out.println(year+"是闰年");
//		}
//		else {
//			System.out.println(year+"不是闰年");
//		}
//	}
	
//练习-季节
//	public static void main(String[] args) {
//		Scanner s = new Scanner(System.in);
//		System.out.println("请输入月份");
//		int month = s.nextInt();
//		switch(month) {
//		case 1:
//		case 2:
//		case 3:
//			System.out.println("春天");
//			break;
//		case 4:
//		case 5:
//		case 6:
//			System.out.println("夏天");
//			break;			
//			
//		case 7:
//		case 8:		
//		case 9:
//			System.out.println("秋天");
//			break;			
//
//		case 10:
//		case 11:
//		case 12:		
//			System.out.println("冬天");
//			break;			
//
//		}
//	}
	
//练习-阶乘
//	public static void main(String[] args) {
//		Scanner s = new Scanner(System.in);
//		System.out.println("请输入一个整数：");
//		int num = s.nextInt();
//		int i=1;
//		int result=1;
//		while(i<=num) {
//			result *=i;
//			i++;
//		}
//		System.out.println("阶乘是："+result);
//	}
	
//练习-乞丐
//	static int inCome(int day,int income) {
//		for(int i = 1; i<=day-1;i++) {
//			income=income*2;
//		}
//		return income;
//	}
//	
//	public static void main(String[] args) {
//		int income = 1;
//		int summy = 0;
//		for(int day=1;day<=10;day++) {
//			summy +=income;
//			income = inCome(day,2);
//		}
//		System.out.println(summy);
//	}
	
//练习-忽略倍数
//	public static void main(String[] args) {
//		for(int i=1;i<=100;i++) {
//			if(i%3==0 || i%5==0) {
//				continue;
//			}
//			System.out.println(i);
//		}
//	}
	
//练习-百万富翁
//	final float monthincome	=	3000;	//月收入
//	final float investment	=	1000;	//每月投资
//	final float p = 10000;	//本金
	
//练习-黄金分割点
//	public static void main(String[] args) {
//		float demominator	=	0;	//分母
//		float member	=	0;	//分子
//		float closer	=	0;	//最近的答案
//		float result	=	0;
//		float outputresult  = 0;
//		float i,j;
//		
//		
//		for(i=1;i<=20;i++) {
//			for(j=1;j<=20;j++) {
//				result = j	/	i;
//				
//				if(result>closer && result<0.618) {
//					closer=result;
//					member = j;
//					demominator	=	i;
//				}
//			}
//		}
//		outputresult = member / demominator;
//		System.out.print("离黄金分割点（0.618）最近的两个数相除是："+member+"/"+demominator+"="+outputresult);
//	}
	
//练习-水仙花数
//	public static void main(String[] args) {
//		int sum;
//		for(int i=1;i<=9;i++) {
//			for(int j = 0;j<=9;j++) {
//				for(int k = 0;k<=9;k++) {
//					sum=i*100+j*10+k;
//					if(sum==i*i*i+j*j*j+k*k*k) {
//						System.out.println(sum);
//					}
//				}
//			}
//		}
//	}
	
//练习-小学算术题
//	public static void main(String[] args) {
//		int a,b,c,d;
//		for(a=0;a<100;a++) {
//			for(b=0;b<100;b++) {
//				for(c=0;c<100;c++) {
//					for(d=0;d<100;d++) {
//						if(a+b==8 && a+c==14 && b+d==10 &&c-d==6) {
//							System.out.println("a="+a+",b="+b+",c="+c+",d="+d);
//						}
//					}
//				}
//			}
//		}
//	}
	
//练习-数组最小数值
//	public static void main(String[] args) {
//		int []a = new int[5];
//		a[0] = (int) (Math.random() * 100);
//		a[1] = (int) (Math.random() * 100);
//		a[2] = (int) (Math.random() * 100);
//		a[3] = (int) (Math.random() * 100);
//		a[4] = (int) (Math.random() * 100);
//		
//		System.out.println("数组中的各个随机数是:");
//		for (int i = 0; i < a.length; i++) 
//			System.out.println(a[i]);
//		
//		int min=a[0];
//		for(int i =1;i<5;i++) {
//			if(min>a[i]) {
//				min=a[i];
//			}
//		}
//		System.out.println("该数组最小值为："+min);
//	}
	
//练习-数组反转
//	public static void main(String[] args) {
//		int []a = new int[5];
//		a[0] = (int) (Math.random() * 100);
//		a[1] = (int) (Math.random() * 100);
//		a[2] = (int) (Math.random() * 100);
//		a[3] = (int) (Math.random() * 100);
//		a[4] = (int) (Math.random() * 100);
//		
//		System.out.println("数组中的各个随机数是:");
//		for (int i = 0; i < a.length; i++) 
//			System.out.print(a[i]+"	");
//		
//		System.out.println();
//		
//		int []b=new int [5];
//		System.out.println("数组反转后:");
//		for(int i=0;i<b.length;i++) {
//			b[i]=a[4-i];
//			System.out.print(b[i]+"	");
//		}
//	}
	
//练习-排序
//	public static void printArray(int []a) {
//		for(int i = 0;i<a.length;i++) {
//			System.out.print(a[i]+"	");
//		}
//		System.out.println(" ");
//	}
//	
//	public static void main(String[] args) {
//		int []a = new int[5];
//		a[0] = (int) (Math.random() * 100);
//		a[1] = (int) (Math.random() * 100);
//		a[2] = (int) (Math.random() * 100);
//		a[3] = (int) (Math.random() * 100);
//		a[4] = (int) (Math.random() * 100);
//		
//		System.out.println("数组中的各个随机数是:");
//		printArray(a);
//			
//		System.out.println("选择法正排序:");
//		int temp;
//		int min;
//		for(int i=0;i<a.length-1;i++) {
//			min = a[i];
//			for(int j = i;j<a.length;j++) {
//				if(a[j]<min) {
//					temp=a[i];
//					a[i]=a[j];
//					a[j]=temp;
//					}
//				}
//			}
//		printArray(a);
//		
//		System.out.println("冒泡法倒排序");
//		for(int j = 0;j<a.length-1;j++) {
//			for(int i=0;i<a.length-1;i++) {
//				if(a[i]<a[i+1]) {
//					temp=a[i];
//					a[i]=a[i+1];
//					a[i+1]=temp;
//				}
//			}
//		}
//		printArray(a);
//		}
	
//练习-最大值
//	public static void main(String[] args) {
//		int []a = new int[5];
//		a[0] = (int) (Math.random() * 100);
//		a[1] = (int) (Math.random() * 100);
//		a[2] = (int) (Math.random() * 100);
//		a[3] = (int) (Math.random() * 100);
//		a[4] = (int) (Math.random() * 100);
//		
//		System.out.println("数组中的各个随机数是:");
//		for(int i = 0;i<a.length;i++) {
//			System.out.print(a[i]+"	");
//		}
//		System.out.println(" ");
//		int max=a[0];
//		for(int each:a) {	
//			if(each>max) {
//				max=each;
//			}
//		}
//		System.out.println("max="+max);
//	}
	
//练习-合并数组
//	public static void main(String[] args) {
//		int alength =(int) (Math.random()*10);
//		int blength =(int) (Math.random()*10);
//		int []a = new int[alength];
//		int []b = new int[blength];
//		int []c = new int[alength+blength];
//
//		System.out.println("数组a的内容：");
//		for(int i=0;i<a.length;i++) {
//			a[i]= (int) (Math.random() * 100);
//			System.out.print(a[i]+" ");
//		}
//		System.out.println(" ");
//		
//		System.out.println("数组b的内容：");
//		for(int i=0;i<b.length;i++) {
//			b[i]= (int) (Math.random() * 100);
//			System.out.print(b[i]+" ");
//		}
//		System.out.println(" ");
//		
//		System.arraycopy(a, 0, c, 0, a.length);
//		System.arraycopy(b, 0, c, a.length,b.length);
//		
//		System.out.println("数组c的内容：");
//		for(int each:c) {
//			System.out.print(each+" ");
//		}
//	}
	
//练习-二维数组
//	public static void main(String[] args) {
//		int [][] a = new int[5][5];
//		for(int i=0 ;i<5;i++) {
//			for(int j = 0 ;j<5;j++) {
//				a[i][j]	=(int) (Math.random() * 100);
//				System.out.print(a[i][j]+"	");
//			}
//			System.out.println(" ");
//		}
//		
//		int x=0,y=0;
//		int max = a[0][0];
//		for(int i=0 ;i<5;i++) {
//			for(int j = 0 ;j<5;j++) {
//				if(max<a[i][j]) {
//					max=a[i][j];
//					x=i;
//					y=j;
//				}
//			}
//		}
//		System.out.println("找出来最大的是："+max);
//		System.out.println("其坐标是["+x+"] ["+y+"]");
//	}
	
//练习-二维数组排序
//	public static void main(String[] args) {
//		int [][]a = new int[5][8];
//		int []b = new int [5*8];
//		System.out.println("整理前数组：");
//		for(int i = 0;i<5;i++) {
//			for(int j = 0;j<8;j++) {
//				a[i][j]	=(int) (Math.random() * 100);
//				System.out.print(a[i][j]+"	");
//			}
//			System.out.println(" ");
//		}
//		
//		System.out.println(" ");
//		for(int i=0;i<5;i++) {
//			System.arraycopy(a[i],0, b, i*8, 8);
//		}
//		Arrays.sort(b);
//		
//		for(int i=0;i<5;i++) {
//			System.arraycopy(b, 8*i, a[i], 0, 8);
//		}
//		
//		
//		System.out.println("整理后数组：");
//		for(int []each:a) {
//			for(int j:each) {
//				System.out.print(j+"	");
//			}
//			System.out.println();
//		}
//	}
} 
