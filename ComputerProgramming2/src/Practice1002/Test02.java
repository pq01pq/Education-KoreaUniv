package Practice1002;
import java.util.Scanner;

public class Test02 {

	public static void main(String[] args) {
		// TODO Auto-generated method stub
		Scanner scan = new Scanner(System.in);
		int integer = 0, sum = 0;
		// 5개 입력받고 양수의 합
		for (int i = 0; i < 5; i++)
		{
			System.out.print("정수를 입력하시오 : ");
			if ( (integer = scan.nextInt()) > 0)
				sum += integer;
		}
		System.out.print("양수의 합 = " + sum);

		scan.close();
	}

}
