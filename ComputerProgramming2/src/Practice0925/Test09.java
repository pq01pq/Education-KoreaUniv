package Practice0925;
import java.util.Scanner;

public class Test09 {

	public static void main(String[] args) {
		// TODO Auto-generated method stub
		Scanner scan = new Scanner(System.in);
		
		int n = 1, cnt = 0, sum = 0;
		double ave = 0;
		System.out.print("������ �Է� (���� : -1) : ");
		
		n = scan.nextInt();
		while(n != -1) {
			cnt++;
			sum += n;
			ave = (double) sum / cnt;
			
			n = scan.nextInt();
		}
		if (cnt > 0) {
			System.out.printf("������ ���� = %d��\n", cnt);
			System.out.printf("��� = %f\n", ave);
		}
		else
			System.out.printf("�Էµ� �� ����!");
		
		scan.close();
	}

}
