package Practice1002;
import java.util.Scanner;

public class Test06 {

	public static void main(String[] args) {
		// TODO Auto-generated method stub
		Scanner scan = new Scanner(System.in);
		
		int[] a = new int[5];
		int max = 0;
		
		System.out.print("��� 5�� �Է� : ");
		for(int i = 0; i < a.length; i++) {
			a[i] = scan.nextInt();
			if (a[i] > max)
				max = a[i];
		}
		System.out.printf("���� ū �� : %d", max);
		
		scan.close();
	}

}
