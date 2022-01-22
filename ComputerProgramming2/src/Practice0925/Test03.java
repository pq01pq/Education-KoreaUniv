package Practice0925;
import java.util.Scanner;

public class Test03 {

	public static void main(String[] args) {
		// TODO Auto-generated method stub
		Scanner scan = new Scanner(System.in);
		
		System.out.printf("점수를 입력하시오 : ");
		int score = scan.nextInt();
		
		if (score >= 90)
			System.out.println("학점 : A");
		else if (score >= 80)
			System.out.println("학점 : B");
		else if (score >= 70)
			System.out.println("학점 : C");
		else if (score >= 60)
			System.out.println("학점 : D");
		else
			System.out.println("학점 : F");
		
		scan.close();
	}

}
