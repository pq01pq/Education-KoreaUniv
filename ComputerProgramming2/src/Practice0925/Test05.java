package Practice0925;
import java.util.Scanner;

public class Test05 {

	public static void main(String[] args) {
		// TODO Auto-generated method stub
		Scanner scan = new Scanner(System.in);
		
		System.out.printf("�Է� : ");
		int i = scan.nextInt();
		
		String number;
		switch (i) {
			case 1 :
				number = "��";
				break;
			case 2 :
				number = "��";
				break;
			case 3 :
				number = "��";
				break;
			default :
				number = "��Ÿ";
				break;
		}
		System.out.println(number);
		
		scan.close();
	}

}
