package Practice0925;
import java.util.Scanner;

public class Test04 {

	public static void main(String[] args) {
		// TODO Auto-generated method stub
		Scanner scan = new Scanner(System.in);
		
		System.out.printf("������ �Է��Ͻÿ� : ");
		int score = scan.nextInt();
		System.out.printf("�г��� �Է��Ͻÿ� : ");
		int year = scan.nextInt();
		
		if (score >= 70)
			System.out.println("�հ�!");
		else if (score >= 60)
		{
			if (year == 3)
				System.out.println("�հ�!");
			if (year == 4)
				System.out.println("���հ�!");
		}
		else
			System.out.println("���հ�!");
		
		scan.close();
	}

}
