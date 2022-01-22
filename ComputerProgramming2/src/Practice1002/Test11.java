package Practice1002;
import java.util.Scanner;

public class Test11 {

	public static void main(String[] args) {
		// TODO Auto-generated method stub

		Scanner scan = new Scanner(System.in);
		System.out.print("분자 입력 : ");
		int i = scan.nextInt();
		System.out.print("분모 입력 : ");
		int j = scan.nextInt();
		try {
			System.out.println(i / j);
		}
//		catch (ArithmeticException e) {
		catch (Exception e) {
			System.out.println("0으로 나누기 오류 발생");
			System.out.println(e.getMessage() );
			e.printStackTrace(); // 오류에 대한 정보 확인
		}
//		finally {
//			System.out.println("try/catch 통과");
//		}
		
		scan.close();
	}

}
