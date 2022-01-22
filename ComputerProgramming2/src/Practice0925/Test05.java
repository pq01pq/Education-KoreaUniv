package Practice0925;
import java.util.Scanner;

public class Test05 {

	public static void main(String[] args) {
		// TODO Auto-generated method stub
		Scanner scan = new Scanner(System.in);
		
		System.out.printf("입력 : ");
		int i = scan.nextInt();
		
		String number;
		switch (i) {
			case 1 :
				number = "일";
				break;
			case 2 :
				number = "이";
				break;
			case 3 :
				number = "삼";
				break;
			default :
				number = "기타";
				break;
		}
		System.out.println(number);
		
		scan.close();
	}

}
