package 额外例题;

import java.awt.Container;
import java.awt.FlowLayout;
import javax.swing.JFrame;
import javax.swing.JLabel;
import javax.swing.JPasswordField;
import javax.swing.JTextField;
import javax.swing.ButtonGroup;
import javax.swing.JCheckBox;
import javax.swing.JRadioButton;
import javax.swing.JComboBox;
import javax.swing.JList;
import javax.swing.JScrollBar;
import javax.swing.JTextArea;
import java.awt.Color;
import java.awt.Dimension;
import javax.swing.JPanel;
import javax.swing.JSlider;
public class 校园登录界面 extends JFrame {
	校园登录界面()
	{
		super("校园管理系统登陆界面");
		Container c = getContentPane();
		c.setLayout(new FlowLayout());
		JLabel lab1 = new JLabel("用户名：");
		c.add(lab1);
		JTextField txt = new JTextField(6);
		c.add(txt);
		JLabel lab2 = new JLabel("密码：");
		c.add(lab2);
		JPasswordField jp = new JPasswordField(8);
		c.add(jp);
		
		JCheckBox jb1 =new JCheckBox("显示密码");
		c.add(jb1);
		
		JLabel lab3 = new JLabel("身份：");
		c.add(lab3);
		JRadioButton student=new JRadioButton("学生");
		JRadioButton teacher=new JRadioButton("老师");
		ButtonGroup bg = new ButtonGroup();
		bg.add(teacher);
		bg.add(student);
		c.add(teacher);
		c.add(student);
		
		JLabel lab4 = new JLabel("所处校区：");
		c.add(lab4);
		String s[]={"广州校区","滨海校区"};
		JComboBox jc = new JComboBox(s);
		c.add(jc);
	}
	public static void main(String[] args)
	{
		校园登录界面 jf = new 校园登录界面();
		jf.setSize(300,200);
		jf.setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
		jf.setVisible(true);
	}
}
