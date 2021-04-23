package 例题;
import java.util.Arrays; //程序导入JDK类库提供的Arrays类，该类可以对数组进行操作
public class Exam2_11 {
	public static void main(String[] args) 
	{
		int[]a= {1,2,3,4,500,600,700,800};
		int[]b,c,d;
		b=new int[8];
		c=new int[8];
		d=new int[8];
		System.out.println(Arrays.toString(a));//输出a数组Arrays.toString()为直接输出数组
		System.arraycopy(a,0,b,0,a.length);//从a数组的第一个数开始复制直到最后一个，复制到b数组的第一个开始替换
		System.out.println(Arrays.toString(b));
		System.arraycopy(a,0,c,0,4);//arraycopy为取数组元素功能，格式：arraycopy(数组1的名，数组1开始复制元素下标，数组2的名，数组2开始复制元素下标，复制个数)
		//调用arraycopy方法复制数组a前4歌元素到数组c中的前4个元素
		System.out.println(Arrays.toString(c));
		//Arrays调用toString方法返回数组c的元素值
		System.arraycopy(a,4,d,0,4);
		//调用arraycopy方法复制数组a的后4个元素到数组d中的前4个元素
		System.out.println(Arrays.toString(d));
		c[c.length-1]=-100;
		//将-100赋给数组c的最后一个元素
		d[d.length-1]=-200;
		System.out.println(Arrays.toString(c));
		System.out.println(Arrays.toString(d));
	}
}
