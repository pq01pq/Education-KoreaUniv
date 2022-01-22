package Assignment0925;
import java.util.Scanner;

public class Tax {

	public static void main(String[] args) {
		// TODO Auto-generated method stub

		System.out.print("���� ǥ�� �Է�(���� ����) : ");
		Scanner scan = new Scanner(System.in);
		int income = scan.nextInt();
		double tax = 0;
		
		//System.out.println((income - (income % 1000) ) / 1000);
		switch ( (income - (income % 1000) ) / 1000) // a = d * q + r -> q = (a - r) / d
		{
			case 0:
				tax = (8.0 / 100) * income;
				break;
			case 1:
			case 2:
			case 3:
				tax = (17.0 / 100) * income;
				break;
			case 4:
			case 5:
			case 6:
			case 7:
				tax = (26.0 / 100) * income;
				break;
			default :
				tax = (35.0 / 100) * income;
		}
		//System.out.println(tax);
		System.out.printf("�ҵ漼�� %d�����Դϴ�.", (int) tax);
		
		scan.close();
	}
}
