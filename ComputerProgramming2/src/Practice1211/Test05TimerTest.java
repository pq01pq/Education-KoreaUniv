package Practice1211;
import java.awt.Container;
import java.awt.FlowLayout;
import java.awt.Font;

import javax.swing.JFrame;
import javax.swing.JLabel;

class Test05Timer extends Thread {
	private JLabel l;
	public Test05Timer(JLabel l) {
		this.l = l;
	}
	@Override
	public void run() {
		int n = 0;
		while(true) {
			l.setText(Integer.toString(n));
			n++;
			try {
				Thread.sleep(1000); // millisecond
			} catch (InterruptedException e) {
				// TODO Auto-generated catch block
				e.printStackTrace();
			}
		}
	}
}

public class Test05TimerTest extends JFrame {
	
	public Test05TimerTest() {
		setTitle("Ÿ�̸� ������");
		setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);	// ���� ��ư ������ ����
		
		Container c = getContentPane();
		//c.setBackground(Color.BLUE);
		c.setLayout(new FlowLayout());	// ��, ��, ���� ����, ���� ����
		
		JLabel l = new JLabel();
		l.setFont(new Font("Gothic", Font.ITALIC, 80));
		c.add(l);
		
		Test05Timer th = new Test05Timer(l);
		th.start();
		
		setSize(300, 200);
		setVisible(true);
	}
	
	public static void main(String[] args) {
		// TODO Auto-generated method stub
		new Test05TimerTest();
	}

}
