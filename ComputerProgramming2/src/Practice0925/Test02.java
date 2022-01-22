package Practice0925;
import java.util.Scanner;

public class Test02 {

	public static void main(String[] args) {
		// TODO Auto-generated method stub
		Scanner scan = new Scanner(System.in);
		
		System.out.printf("수를 입력하시오 : ");
		int n = scan.nextInt();
		
		if ( n > 80) {
			System.out.println("당신은 합격입니다.");
		}
		
		if ( (n % 3) == 0) {
			System.out.println("3의 배수입니다.");
		}
		else {
			System.out.println("3의 배수가 아닙니다.");
		}
		
		scan.close();
	}
}
