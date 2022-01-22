package Practice1016;
import java.util.Scanner;

public class Test02 {
	static void prn(int i, int j) throws Exception {
			System.out.println(i/j);
			// throws Exception : 예외처리를 자신을 호출한 상위 메소드로 떠넘김
			// 예외처리 전용 메소드로 만들 수 있음
	}

	public static void main(String[] args) {
		// TODO Auto-generated method stub
		Scanner s = new Scanner(System.in);
		
		System.out.print("첫 번째 수 : ");
		int i = s.nextInt();
		
		System.out.print("두 번째 수 : ");
		int j = s.nextInt();
		
		try {
			prn(i, j);
		} catch (Exception e) {
			System.out.println("0으로 나누기 오류 발생");
		}
		
		s.close();
	}
}
