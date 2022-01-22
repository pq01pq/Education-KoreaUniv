package Practice1016;
import java.util.Scanner;

public class Test01 {

	public static void main(String[] args) {
		// TODO Auto-generated method stub
		Scanner s = new Scanner(System.in);
		
		System.out.print("첫 번째 수 : ");
		int i = s.nextInt();
		
		System.out.print("두 번째 수 : ");
		int j = s.nextInt();
		
		try {
			System.out.println(i/j);
		} catch (ArithmeticException e) {
			System.out.println("0으로 나누기 오류 발생");
		}
		s.close();
	}

}
