package 例题;

import java.awt.BorderLayout;
import java.awt.Color;
import java.awt.Container;
import javax.swing.JButton;
import javax.swing.JFrame;

public class Exam4_9 extends JFrame {
	Exam4_9()
	{
		super("边界布局");
		Container c = getContentPane();
		c.setLayout(new BorderLayout());
		JButton button1 = new JButton("按钮1");
		JButton button2 = new JButton("按钮2");
		JButton button3 = new JButton("按钮3");
		JButton button4 = new JButton("按钮4");
		JButton button5 = new JButton("按钮5");
		c.add(button1,BorderLayout.EAST);
		c.add(button2,BorderLayout.SOUTH);
		c.add(button3,BorderLayout.WEST);
		c.add(button4,BorderLayout.NORTH);
		c.add(button5,BorderLayout.CENTER);
	}
	public static void main(String[] args)
	{
		Exam4_9 ob = new Exam4_9();
		ob.setSize(600,300);
		ob.setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
		ob.setVisible(true);
	}
}
