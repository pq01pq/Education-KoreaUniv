package Practice1211;
import java.awt.Container;
import java.awt.GridLayout;

import javax.swing.JFrame;
import javax.swing.JLabel;
import javax.swing.JTextField;

public class Test02MyFrame extends JFrame {
	
	public Test02MyFrame() {
		setTitle("ContentPane과 JFrame");
		setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);	// 종료 버튼 누르면 종료
		
		Container c = getContentPane();
		//c.setBackground(Color.BLUE);
		c.setLayout(new GridLayout(4, 2, 0, 5));	// 행, 열, 가로 간격, 세로 간격
		
		c.add(new JLabel("이름", JLabel.CENTER)); c.add(new JTextField(""));
		c.add(new JLabel("학번", JLabel.CENTER)); c.add(new JTextField(""));
		c.add(new JLabel("학과", JLabel.CENTER)); c.add(new JTextField(""));
		c.add(new JLabel("과목", JLabel.CENTER)); c.add(new JTextField(""));
		
		setSize(300, 200);
		setVisible(true);
	}
	
	public static void main(String[] args) {
		// TODO Auto-generated method stub
		new Test02MyFrame();
	}

}
