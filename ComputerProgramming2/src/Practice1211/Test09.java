package Practice1211;
import java.awt.Color;
import java.awt.Container;
import java.awt.FlowLayout;
import java.awt.event.KeyAdapter;
import java.awt.event.KeyEvent;

import javax.swing.JFrame;
import javax.swing.JLabel;

public class Test09 extends JFrame {
	private JLabel la= new JLabel();
	Container c;// ����Ŭ�����������ٰ���
	public Test09() {
		setTitle("����Ʈ�����ǹ��������ϱ�");
		setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
		c= getContentPane();
		c.setLayout(new FlowLayout());
		c.addKeyListener(new Test09MyKeyListener());
		c.add(la);
		setSize(300,150);setVisible(true);
		c.setFocusable(true);c.requestFocus();
	}
	class Test09MyKeyListener extends KeyAdapter{
		public void keyPressed(KeyEvent e) {
			la.setText(e.getKeyText(e.getKeyCode()));
			if (e.getKeyChar() == 'y')// ��ҹ����Է±���
				c.setBackground(Color.YELLOW);
			else if (e.getKeyCode() == KeyEvent.VK_F1)
				c.setBackground(Color.GREEN);
		}
	}
	public static void main(String[] args) { new Test09(); }
}