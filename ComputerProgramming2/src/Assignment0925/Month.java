package Assignment0925;
import java.util.Scanner;

public class Month {

	public static void main(String[] args) {
		// TODO Auto-generated method stub
		Scanner scan = new Scanner(System.in);
		
		System.out.print("달의 이름 입력 : ");
		String month = scan.next();
		
		if (month.equals("jan"))
			System.out.print("1월");
		else if (month.equals("feb"))
			System.out.print("2월");
		else if (month.equals("mar"))
			System.out.print("3월");
		else
			System.out.print("기타");
		
		scan.close();
	}
}
