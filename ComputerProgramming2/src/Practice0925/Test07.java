package Practice0925;
import java.util.Scanner;

public class Test07 {

	public static void main(String[] args) {
		// TODO Auto-generated method stub
		Scanner scan = new Scanner(System.in);
		
		System.out.printf("점수를 입력하시오 : ");
		int score = scan.nextInt();
		
		String grade;
		switch (score / 10) {
		case 10 :
		case 9 :
			grade = "A";
			break;
		case 8 :
			grade = "B";
			break;
		case 7 :
			grade = "C";
			break;
		case 6 :
			grade = "D";
			break;
		default :
			grade = "F";
			break;
		}
		System.out.println(grade);
		
		scan.close();
	}

}
