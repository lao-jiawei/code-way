package 例题;
import java.awt.Container;
import java.awt.FlowLayout;
import javax.swing.JDialog;
import javax.swing.JFrame;
public class Exam4_2 {
	public static void main(String[] args) {
		JFrame jf = new JFrame("对话框实例");
		Container c = jf.getContentPane();
		c.setLayout(new FlowLayout(FlowLayout.CENTER));
		jf.setSize(600,400);
		jf.setVisible(true);
		jf.setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
		JDialog jd = new JDialog(jf,"对话框",false);
		jd.setSize(200,100);
		jd.setVisible(true);
		}

}
