package Practice1002;
import java.util.Scanner;

public class Test07 {

	public static void main(String[] args) {
		// TODO Auto-generated method stub
		Scanner scan = new Scanner(System.in);
		
		int[] a = new int[5];
		int sum = 0;
		double ave = 0;
		
		System.out.printf("%d개의 정수 입력 : ", a.length);
		for(int i = 0; i < a.length; i++) {
			a[i] = scan.nextInt();
		}
		for (int k : a)
			sum += k;
		ave = (double) sum / a.length;
		System.out.printf("평균 : " + ave);
		
		scan.close();
	}

}
