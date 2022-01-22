package Practice0925;
import java.util.Scanner;

public class Test09 {

	public static void main(String[] args) {
		// TODO Auto-generated method stub
		Scanner scan = new Scanner(System.in);
		
		int n = 1, cnt = 0, sum = 0;
		double ave = 0;
		System.out.print("정수들 입력 (종료 : -1) : ");
		
		n = scan.nextInt();
		while(n != -1) {
			cnt++;
			sum += n;
			ave = (double) sum / cnt;
			
			n = scan.nextInt();
		}
		if (cnt > 0) {
			System.out.printf("정수의 개수 = %d개\n", cnt);
			System.out.printf("평균 = %f\n", ave);
		}
		else
			System.out.printf("입력된 수 없음!");
		
		scan.close();
	}

}
