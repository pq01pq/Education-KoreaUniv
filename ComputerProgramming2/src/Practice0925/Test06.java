package Practice0925;
import java.util.Scanner;

public class Test06 {

	public static void main(String[] args) {
		// TODO Auto-generated method stub
		Scanner scan = new Scanner(System.in);
		
		System.out.printf("입력 : ");
		String coffee = scan.next();
		
		String order;
		switch (coffee){
			case "에스프레소" :
			case "카푸치노" :
			case "카페라떼" :
				order = "3500원";
				break;
			case "아메리카노" :
				order = "2000원";
				break;
			default :
				order = "메뉴에 없습니다!";
				break;
		}
		System.out.println(order);
		
		scan.close();
	}
}
