package Practice1002;
import java.util.InputMismatchException;
import java.util.Scanner;

public class Test12 {

	public static void main(String[] args) {
		// TODO Auto-generated method stub
		Scanner scan = new Scanner(System.in);
		
		int num, sum = 0;
		System.out.println("���� 3���� �Է��ϼ���");
		for (int i = 0; i < 3; i++) {
			try {
				System.out.printf("���� %d : ", i + 1);
				num = scan.nextInt();
			}
			catch (InputMismatchException e) {
				System.out.println("���� �ƴ�! �ٽ� �Է��϶��s!");
				scan.next(); // ������ �Է����� �ʾ��� �ÿ� �Էµ� ���� �������� �ʾƼ� ������
				i--;
				continue;
			}
			sum += num;
		}
		System.out.println("�� = " + sum);
		scan.close();
	}

}
