package 例题;
import java.awt.Color;
import java.awt.Container;
import java.awt.Dimension;
import java.awt.FlowLayout; 
import javax.swing.JFrame;
import javax.swing.JPanel;
import javax.swing.JSlider;
public class Exam4_7 extends JFrame{
	Exam4_7(){
		super("面板和滚动条实例");
		Container c=getContentPane();
		c.setLayout(new FlowLayout());
		JSlider s=new JSlider(JSlider.HORIZONTAL,0,26,6);
		c.add(s);
		JPanel p = new JPanel();
		p.setPreferredSize(new Dimension(100,60));
		p.setBackground(Color.red);
		c.add(p);
	}
	public static void main(String[] args) {
		Exam4_7 jf = new Exam4_7();
		jf.setSize(400,300);
		jf.setVisible(true);
		}
}
