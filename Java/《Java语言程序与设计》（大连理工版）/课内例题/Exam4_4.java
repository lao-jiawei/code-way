package 例题;
import java.awt.Container;
import java.awt.FlowLayout;
import javax.swing.JFrame;
import javax.swing.JLabel;
import javax.swing.JPasswordField;
import javax.swing.JTextField;
public class Exam4_4 extends JFrame{
	Exam4_4(){
		super("文本编辑框案例");
		Container c = getContentPane();
		c.setLayout(new FlowLayout());
		JLabel labl = new JLabel("用户名：");
		c.add(labl);
		JTextField txt = new JTextField(6);
		c.add(txt);
		JLabel lab2=new JLabel("密码：");
		c.add(lab2);
		JPasswordField jp = new JPasswordField(8);
		c.add(jp);
		}
	public static void main(String[] args) {
		Exam4_4 jf =new Exam4_4();
		jf.setSize(300,200);
		jf.setVisible(true);
		}
}
