package 例题;

import java.awt.Container;
import java.awt.FlowLayout;
import java.awt.event.ActionEvent;
import java.awt.event.ActionListener;
import javax.swing.JButton;
import javax.swing.JFrame;
import javax.swing.JLabel;

public class Exam4_11 extends JFrame implements ActionListener {
	int i = 0;
	JLabel	lab;
	Container c;	
	Exam4_11(){	//构造函数
		super("事件处理");	//窗口标题
		c=getContentPane();	//创建容器c
		c.setLayout(new FlowLayout());	//容器c采用流式布局
		JButton button1 =new JButton("按钮");	//创建按钮button1
		c.add(button1);	//把按钮button1添加到容器c上
		button1.addActionListener(this);	//注册按钮button1为事件源的监听器
		lab=new JLabel("单击按钮"+i+"次");	//添加标签lab
		c.add(lab);	//把标签lab添加到容器c上
	}
	
	public void paint() 
	{
		String s ="单击按钮"+i+"次";
		lab.setText(s);	//每按一次从新设置标签
		
		
		repaint();
	}
	
	public static void main(String[] args) {
		Exam4_11 ob=new Exam4_11();	//创建对象ob
		ob.setSize(600,300);	//设置容器大小
		ob.setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);	//设置关闭选项
		ob.setVisible(true);	//显示整个项目
		}
	
	public void actionPerformed(ActionEvent arg0) 
	{
		i++;
		paint();
	}
}
