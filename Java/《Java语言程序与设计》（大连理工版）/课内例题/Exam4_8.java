package 例题;

import java.awt.Container;
import java.awt.FlowLayout;
import javax.swing.JButton;
import javax.swing.JFrame;
public class Exam4_8 extends JFrame{
	Exam4_8()
	{
		super("顺序布局");
		Container c= getContentPane();
		c.setLayout(new FlowLayout());
		JButton button1=new JButton("按钮1");
		JButton button2=new JButton("按钮2");
		JButton button3=new JButton("按钮3");
		c.add(button1);
		c.add(button2);
		c.add(button3);
	}
	public static void main(String[] args)
	{
		Exam4_8 ob =new Exam4_8();
		ob.setSize(600,300);
		ob.setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
		ob.setVisible(true);
	}
}

