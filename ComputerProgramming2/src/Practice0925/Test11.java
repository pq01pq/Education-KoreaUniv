package Practice0925;
import java.util.Scanner;

public class Test11 {

	public static void main(String[] args) {
		// TODO Auto-generated method stub
		Scanner scan = new Scanner(System.in);
		
		int month = 1;
		do {
			System.out.print("�� �Է� [1-12] : ");
			month = scan.nextInt();
		} while ( (month < 1) || (month > 12) );
		
		System.out.printf("����� �Է� : %d��\n", month);
		
		scan.close();
	}

}
