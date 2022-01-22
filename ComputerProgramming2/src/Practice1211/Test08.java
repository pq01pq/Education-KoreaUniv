package Practice1211;
import java.awt.Container;
import java.awt.event.MouseEvent;
import java.awt.event.MouseListener;

import javax.swing.JFrame;
import javax.swing.JLabel;

public class Test08 extends JFrame {
	private JLabel la= new	JLabel("Hello");// 내부클래스에서접근가능
	public Test08() {
		setTitle("Mouse 이벤트예제");
		setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
		Container c	= getContentPane();
		c.addMouseListener(new Test08MyMouseListener());
		c.setLayout(null);
		la.setSize(50, 20);la.setLocation(30, 30);c.add(la);
		setSize(250, 250);setVisible(true);
	}
	
	class Test08MyMouseListener implements MouseListener {
		public void mousePressed(MouseEvent e) {
			int x= e.getX(); int y= e.getY();
			la.setLocation(x, y);
		}
		public void mouseReleased(MouseEvent e) {}// 사용하지않아도작성해야함
		public void mouseClicked(MouseEvent e) {}
		public void mouseEntered(MouseEvent e) {}
		public void mouseExited(MouseEvent e) {}
	}
	
	public static void main(String[] args) { new Test08(); }
}
