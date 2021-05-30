package 例题;

import java.awt.Color;
import java.awt.GridBagLayout;
import java.awt.GridLayout;
import java.awt.Container;

import javax.swing.JButton;
import javax.swing.JFrame;

public class Exam4_10 extends JFrame {
	Exam4_10()
	{
		super("网格布局");
		Container c=getContentPane();
		c.setLayout(new GridLayout(2,3));
		JButton button1 = new JButton("按钮1");
		JButton button2 = new JButton("按钮2");
		JButton button3 = new JButton("按钮3");
		JButton button4 = new JButton("按钮4");
		JButton button5 = new JButton("按钮5");
		c.add(button1);
		c.add(button2);
		c.add(button3);
		c.add(button4);
		c.add(button5);
		
	}
	public static void main(String[] args)
	{
		Exam4_10 ob=new Exam4_10();
		ob.setSize(600,300);
		ob.setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
		ob.setVisible(true);
	}
}