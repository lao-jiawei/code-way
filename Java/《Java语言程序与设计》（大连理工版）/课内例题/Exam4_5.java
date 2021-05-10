package 例题;
import java.awt.Container;
import java.awt.FlowLayout;
import javax.swing.ButtonGroup;
import javax.swing.JCheckBox;
import javax.swing.JFrame;
import javax.swing.JRadioButton;
public class Exam4_5 extends JFrame{
	Exam4_5(){
		super("按钮实例");
		Container c = getContentPane();
		c.setLayout(new FlowLayout());
		JCheckBox jb1= new JCheckBox("加粗");
		JCheckBox jb2= new JCheckBox("倾斜");
		c.add(jb1);
		c.add(jb2);
		JRadioButton red = new JRadioButton("红色");
		JRadioButton blue = new JRadioButton("蓝色");
		ButtonGroup bg = new ButtonGroup();
		bg.add(red);
		bg.add(blue);
		c.add(red);
		c.add(blue);
		}
	public static void main(String[] args) {
		Exam4_5 jf = new Exam4_5();
		jf.setSize(400,300);
		jf.setVisible(true);
		}
}
