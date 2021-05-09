package 例题;
import java.awt.Color;
import java.awt.Container;
import java.awt.FlowLayout; 
import javax.swing.JFrame;
import javax.swing.JLabel;
public class Exam4_1 extends JFrame{
	Exam4_1(){
		super("我的框架窗口");//调用父类构造方法设置窗口的标题
		Container c=getContentPane();
		c.setLayout(new FlowLayout(FlowLayout.CENTER));
		JLabel lab=new JLabel("欢迎学习Java图形用户界面设计编程");
		lab.setForeground(Color.red);
		c.add(lab);
	}
	public static void main(String[] args) {
		Exam4_1 ob=new Exam4_1();
		ob.setSize(600,300);
		ob.setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
		ob.setVisible(true);
		}
}

