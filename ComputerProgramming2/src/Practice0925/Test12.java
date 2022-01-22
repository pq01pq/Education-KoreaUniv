package Practice0925;
import java.util.Scanner;

public class Test12 {

	public static void main(String[] args) {
		// TODO Auto-generated method stub
		Scanner scan = new Scanner(System.in);
		
		System.out.print("난수의 개수 : ");
		int n = scan.nextInt();
		int rand = 0, sum = 0;
		
		for (int i = 0; i < n; i++)
		{
			rand = (int) (Math.random() * 100);
			System.out.printf("난수 : %d\n", rand);
			sum += rand;
		}
		System.out.printf("난수 %d개의 합 : %d\n", n, sum);
		
		scan.close();
	}

}
