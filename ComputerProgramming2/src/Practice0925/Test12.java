package Practice0925;
import java.util.Scanner;

public class Test12 {

	public static void main(String[] args) {
		// TODO Auto-generated method stub
		Scanner scan = new Scanner(System.in);
		
		System.out.print("������ ���� : ");
		int n = scan.nextInt();
		int rand = 0, sum = 0;
		
		for (int i = 0; i < n; i++)
		{
			rand = (int) (Math.random() * 100);
			System.out.printf("���� : %d\n", rand);
			sum += rand;
		}
		System.out.printf("���� %d���� �� : %d\n", n, sum);
		
		scan.close();
	}

}
