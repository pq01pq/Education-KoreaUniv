package Practice1002;
import java.util.Scanner;

public class Test05 {

	public static void main(String[] args) {
		// TODO Auto-generated method stub
		Scanner scan = new Scanner(System.in);
		System.out.println("exit �Է½� ����");
		
		String s;
		while(true) {
			System.out.print("�Է� : ");
			s = scan.next();
			if (s.equals("exit")) {
				System.out.println("�����մϴ�...");
				break;
			}
		}
		
		scan.close();
	}

}
