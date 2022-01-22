package Practice1211;
import java.awt.Container;
import java.awt.FlowLayout;
import java.awt.event.ActionEvent;
import java.awt.event.ActionListener;

import javax.swing.JButton;
import javax.swing.JFrame;

class Test07MyActionListener implements ActionListener {
	public void actionPerformed(ActionEvent e) {
		JButton b = (JButton)e.getSource();
		if (b.getText().equals("Action")) b.setText("액션");
		else b.setText("Action");
	}
}

public class Test07 extends JFrame {
	public Test07() {
			setTitle("Action 이벤트리스너예제");
			setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
			Container c= getContentPane();
			c.setLayout(new FlowLayout());
			JButton btn= new JButton("Action");
			btn.addActionListener(new Test07MyActionListener()); // Action리스너달기
			c.add(btn);
			setSize(350, 150);
			setVisible(true);
	}
	
	public static void main(String[] args) {
		new Test07();
	}
}
