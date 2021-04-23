package 例题;
class MyDate{     //设置一个MyDate类
	private int year;      //设置成员变量：年，月，日
	private int month;
	private int day;
	public MyDate(int year,int month,int day) { //成员方法：录入年月日
		this.year=year;
		this.month=month;
		this.day=day;
	}
	public MyDate(){  //成员方法：自动默认设置MyDate日期为2020.1.1
		this(2020,1,1);
	}
	public MyDate(MyDate oday) { //成员方法：调用某日期
		this(oday.year,oday.month,oday.day);
	}
	public void setYear(int year) {  //成员方法：单独录入年份
		this.year=year;
	}
	public int getYear() {  //成员方法：返回该年年份
		return year;
	}
	public void setMonth() { //成员方法：单独录入月份
		this.month=month;
	}
	public int getMonth() {  //成员方法：返回该年月份
		return month;
	}
	public void setDay(int day) {  //成员方法：单独录入日期
		this.day=day;
	}
	public int getDay() {  //成员方法：返回日期
		return this.day=((day>=1)&(day<=31))?day:1;
	}
	public String toString() { //成员方法：返回间单独的年月日组合好的日期
		return this.year+"-"+this.month+"-"+this.day;
	}
	public void print() { //成员方法：输入组合后的日期
		System.out.println("date is "+this.toString());
	}
}

public class Date {
	public static void main(String[] args) {
		MyDate oday1=new MyDate();
		MyDate oday2=new MyDate(2020,1,1);
		MyDate oday3=new MyDate(oday2);
		oday1.print();
		oday2.print();
		oday3.print();
		}
}
