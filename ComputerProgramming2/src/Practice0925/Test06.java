package Practice0925;
import java.util.Scanner;

public class Test06 {

	public static void main(String[] args) {
		// TODO Auto-generated method stub
		Scanner scan = new Scanner(System.in);
		
		System.out.printf("�Է� : ");
		String coffee = scan.next();
		
		String order;
		switch (coffee){
			case "����������" :
			case "īǪġ��" :
			case "ī���" :
				order = "3500��";
				break;
			case "�Ƹ޸�ī��" :
				order = "2000��";
				break;
			default :
				order = "�޴��� �����ϴ�!";
				break;
		}
		System.out.println(order);
		
		scan.close();
	}
}
