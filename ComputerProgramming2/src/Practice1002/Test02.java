package Practice1002;
import java.util.Scanner;

public class Test02 {

	public static void main(String[] args) {
		// TODO Auto-generated method stub
		Scanner scan = new Scanner(System.in);
		int integer = 0, sum = 0;
		// 5�� �Է¹ް� ����� ��
		for (int i = 0; i < 5; i++)
		{
			System.out.print("������ �Է��Ͻÿ� : ");
			if ( (integer = scan.nextInt()) > 0)
				sum += integer;
		}
		System.out.print("����� �� = " + sum);

		scan.close();
	}

}
