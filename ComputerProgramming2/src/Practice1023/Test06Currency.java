package Practice1023;
import java.util.Scanner;

public class Test06Currency {
	
	private static double rate;	// 원화에 대한 환율
	
	public static double toDollar(double won) {
		return won/rate;		// 원화를 달러로 변환
	}
	
	public static double toKWR(double dollar) {
		return dollar * rate;	// 달러를 원화로 변환
	}
	
	public static void setRate(double r) {
		rate = r;				// 환율 설정 (KWR/$1)
	}

	public static void main(String[] args) {
		// TODO Auto-generated method stub

		Scanner scan = new Scanner(System.in);
		
		System.out.print("환율(1달러)>> "); // 1172
		double rate = scan.nextDouble();
		Test06Currency.setRate(rate); // 미국 달러 환율 설정
		
		System.out.print("원화 입력>> "); // 1000000
		int won = scan.nextInt();
		System.out.println("$" + Test06Currency.toDollar(won));
		
		System.out.print("달러 입력>> "); // 100
		int dol = scan.nextInt();
		System.out.println(Test06Currency.toKWR(dol) + "원");
		
		scan.close();
	}

}
