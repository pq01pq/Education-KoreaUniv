package Practice0925;
import java.util.Scanner;

public class Test04 {

	public static void main(String[] args) {
		// TODO Auto-generated method stub
		Scanner scan = new Scanner(System.in);
		
		System.out.printf("점수를 입력하시오 : ");
		int score = scan.nextInt();
		System.out.printf("학년을 입력하시오 : ");
		int year = scan.nextInt();
		
		if (score >= 70)
			System.out.println("합격!");
		else if (score >= 60)
		{
			if (year == 3)
				System.out.println("합격!");
			if (year == 4)
				System.out.println("불합격!");
		}
		else
			System.out.println("불합격!");
		
		scan.close();
	}

}
