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
			System.out.printf("%d반 점수 입력\n", i + 1);
			for (int j = 0; j < STUDENTS; j++)
			{
				System.out.printf("학생%d 점수 입력\n", j + 1);
				System.out.print("국어 점수 입력 : ");
				korean = scan.nextDouble();
				System.out.print("영어 점수 입력 : ");
				english = scan.nextDouble();
				studentSum = korean + english;
				studentAve = studentSum / 2;
				System.out.printf("합 : %f 평균 : %f\n", studentSum, studentAve);
				totalSum += studentSum;
			}
			System.out.println();
		}
		totalAve = totalSum / (CLASSES * STUDENTS);
		System.out.printf("총합 = %f 과목당 평균 = %f", totalSum, totalAve);
		
		scan.close();
	}
	
}

