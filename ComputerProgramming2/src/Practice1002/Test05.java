package Practice1002;
import java.util.Scanner;

public class Test05 {

	public static void main(String[] args) {
		// TODO Auto-generated method stub
		Scanner scan = new Scanner(System.in);
		System.out.println("exit 입력시 종료");
		
		String s;
		while(true) {
			System.out.print("입력 : ");
			s = scan.next();
			if (s.equals("exit")) {
				System.out.println("종료합니다...");
				break;
			}
		}
		
		scan.close();
	}

}
