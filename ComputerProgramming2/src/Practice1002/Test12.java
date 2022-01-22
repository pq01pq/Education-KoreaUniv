package Practice1002;
import java.util.InputMismatchException;
import java.util.Scanner;

public class Test12 {

	public static void main(String[] args) {
		// TODO Auto-generated method stub
		Scanner scan = new Scanner(System.in);
		
		int num, sum = 0;
		System.out.println("정수 3개를 입력하세요");
		for (int i = 0; i < 3; i++) {
			try {
				System.out.printf("정수 %d : ", i + 1);
				num = scan.nextInt();
			}
			catch (InputMismatchException e) {
				System.out.println("정수 아님! 다시 입력하라규s!");
				scan.next(); // 정수를 입력하지 않았을 시에 입력된 값을 배정하지 않아서 버려줌
				i--;
				continue;
			}
			sum += num;
		}
		System.out.println("합 = " + sum);
		scan.close();
	}

}
