package Practice0925;
import java.util.Scanner;

public class Test02 {

	public static void main(String[] args) {
		// TODO Auto-generated method stub
		Scanner scan = new Scanner(System.in);
		
		System.out.printf("���� �Է��Ͻÿ� : ");
		int n = scan.nextInt();
		
		if ( n > 80) {
			System.out.println("����� �հ��Դϴ�.");
		}
		
		if ( (n % 3) == 0) {
			System.out.println("3�� ����Դϴ�.");
		}
		else {
			System.out.println("3�� ����� �ƴմϴ�.");
		}
		
		scan.close();
	}
}
