package 例题;
import java.awt.Container;
import java.awt.FlowLayout;
import javax.swing.JFrame;
import javax.swing.JMenu;
import javax.swing.JMenuBar;
import javax.swing.JMenuItem;

public class Exam4_13 extends JFrame{
	Exam4_13()
	{
		super("菜单实例");
		Container c =getContentPane();
		c.setLayout(new FlowLayout());
		JMenuBar jm =new JMenuBar();
		JMenu file = new JMenu("文件");
		JMenu edit = new JMenu("编辑");
		JMenuItem open = new JMenuItem("打开");
		JMenuItem save = new JMenuItem("保存");
		jm.add(file);
		jm.add(edit);
		file.add(open);
		file.add(save);
		this.setJMenuBar(jm);
	}
	public static void main(String[] args)
	{
		Exam4_13 jf= new Exam4_13();
		jf.setSize(400, 300);
		jf.setVisible(true);
	}

}
