package Practice1211;
import java.awt.Container;
import java.awt.GridLayout;

import javax.swing.JFrame;
import javax.swing.JLabel;
import javax.swing.JTextField;

public class Test02MyFrame extends JFrame {
	
	public Test02MyFrame() {
		setTitle("ContentPane�� JFrame");
		setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);	// ���� ��ư ������ ����
		
		Container c = getContentPane();
		//c.setBackground(Color.BLUE);
		c.setLayout(new GridLayout(4, 2, 0, 5));	// ��, ��, ���� ����, ���� ����
		
		c.add(new JLabel("�̸�", JLabel.CENTER)); c.add(new JTextField(""));
		c.add(new JLabel("�й�", JLabel.CENTER)); c.add(new JTextField(""));
		c.add(new JLabel("�а�", JLabel.CENTER)); c.add(new JTextField(""));
		c.add(new JLabel("����", JLabel.CENTER)); c.add(new JTextField(""));
		
		setSize(300, 200);
		setVisible(true);
	}
	
	public static void main(String[] args) {
		// TODO Auto-generated method stub
		new Test02MyFrame();
	}

}
