package Practice0918;
import java.util.Scanner;

public class Test9 {

	public static void main(String[] args) {
		// TODO Auto-generated method stub
		Scanner scan = new Scanner(System.in);
		
		System.out.print("�����Է� : ");
		int time = scan.nextInt();
		int second = time % 60;
		int minute = (time / 60) % 60;
		int hour = (time / 60) / 60;
		
		System.out.print(time + "�� = ");
		System.out.print(hour + "�ð� " + minute + "�� " + second + "��");
		
		scan.close();
	}

}
