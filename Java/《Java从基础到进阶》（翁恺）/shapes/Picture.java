package shapes;
import java.awt.Graphics;
import java.util.ArrayList;

import javax.swing.JFrame;
import javax.swing.JPanel;
public class Picture extends JFrame{
	private static final long serialVersionUID = 1L;
	private int width;
	private int height;
	
	private ArrayList<Shape> listShape = new ArrayList<Shape>();
	
	private class ShapesPanel extends JPanel {
		private static final long serialVersionUID = 1L;

		@Override
		protected void paintComponent(Graphics g) {
			super.paintComponent(g);
			for ( Shape s : listShape )
			{
				s.draw(g);
			}			
		}
	}
}
