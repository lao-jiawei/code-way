package 例题;
import java.awt.Container;
import java.awt.FlowLayout;
import javax.swing.JComboBox;
import javax.swing.JFrame;
import javax.swing.JList;
import javax.swing.JScrollPane;
import javax.swing.JTextArea;
public class Exam4_6 extends JFrame{
	Exam4_6(){
		super("文本信息实例");
		Container c = getContentPane();
		c.setLayout(new FlowLayout());
		String s[]= {"北京","上海","大连"};
		JComboBox jc = new JComboBox(s);
		c.add(jc);
		JList j1 =new JList(s);
		c.add(j1);
		JTextArea jt = new JTextArea("北京\n上海\n大连\n天津\n重庆\n沈阳\n",3,3);
		JScrollPane sp = new JScrollPane(jt);
		c.add(sp);
	}
	public static void main(String[] args) {
		Exam4_6 jf = new Exam4_6();
		jf.setSize(400,300);
		jf.setVisible(true);
		}
}
