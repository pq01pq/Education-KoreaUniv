package Assignment0925;
import java.util.Scanner;

public class Month {

	public static void main(String[] args) {
		// TODO Auto-generated method stub
		Scanner scan = new Scanner(System.in);
		
		System.out.print("���� �̸� �Է� : ");
		String month = scan.next();
		
		if (month.equals("jan"))
			System.out.print("1��");
		else if (month.equals("feb"))
			System.out.print("2��");
		else if (month.equals("mar"))
			System.out.print("3��");
		else
			System.out.print("��Ÿ");
		
		scan.close();
	}
}
