package Assignment1002;
import java.util.Scanner;

public class Score {

	public static void main(String[] args) {
		// TODO Auto-generated method stub
		final int CLASSES = 2;
		final int STUDENTS = 3;
		
		Scanner scan = new Scanner(System.in);
		
		double korean, english;
		double studentSum, studentAve;
		double totalSum = 0, totalAve;
		
		for (int i = 0; i < CLASSES; i++)
		{
			System.out.printf("%d�� ���� �Է�\n", i + 1);
			for (int j = 0; j < STUDENTS; j++)
			{
				System.out.printf("�л�%d ���� �Է�\n", j + 1);
				System.out.print("���� ���� �Է� : ");
				korean = scan.nextDouble();
				System.out.print("���� ���� �Է� : ");
				english = scan.nextDouble();
				studentSum = korean + english;
				studentAve = studentSum / 2;
				System.out.printf("�� : %f ��� : %f\n", studentSum, studentAve);
				totalSum += studentSum;
			}
			System.out.println();
		}
		totalAve = totalSum / (CLASSES * STUDENTS);
		System.out.printf("���� = %f ����� ��� = %f", totalSum, totalAve);
		
		scan.close();
	}
	
}

