package ÀýÌâ;
import java.applet.Applet;
import java.awt.FlowLayout;
import java.awt.Graphics;
import java.awt.event.MouseEvent;
import java.awt.event.MouseListener;
import java.awt.event.MouseMotionListener;

public class Exam4_12 extends Applet implements MouseListener,MouseMotionListener {
	int x1,y1,x2,y2;
	public void init()
	{
		addMouseListener(this);
		addMouseMotionListener(this);
	}
	public void paint(Graphics g)
	{
		g.drawLine(x1, y2, x2, y2);
		g.drawString("x1:"+x1+"y1:"+y1+"x2:"+x2+"y2:"+y2,50,50);
		}
		public void mouseDragged(MouseEvent e)
		{
			x2=e.getX();
			y2=e.getY();
			repaint();
			}
		public void mouseMoved(MouseEvent arg0)
		{
			
		}
		public void mouseClicked(MouseEvent arg0)
		{
		
		}
		public void mouseEntered(MouseEvent arg0)
		{
		
		}
		public void mouseExited(MouseEvent arg0)
		{
		
		}
		public void mousePressed(MouseEvent arg0)
		{
			x1=e.getX();
			y1=e.getY();
		}
		public void mouseReleased(MouseEvent arg0)
		{
			
		}
}
