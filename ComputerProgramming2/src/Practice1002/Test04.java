package Practice1002;
import java.util.Scanner;

public class Test04 {

	public static void main(String[] args) {
		// TODO Auto-generated method stub
		Scanner scan = new Scanner(System.in);
		
		int num = 0;
		int cnt = 0;
		int sum = 0;
		double ave = 0;
		
		while(true) {
			System.out.print("점수 입력 : ");
			num = scan.nextInt();
			if(num < 0)
				break;
			cnt++;
			sum += num;
			ave = (double)sum / cnt;
		}
		System.out.printf("평균 : %f", ave);
		
		scan.close();
	}

}
