package Practice1002;
import java.util.Scanner;

public class Test11 {

	public static void main(String[] args) {
		// TODO Auto-generated method stub

		Scanner scan = new Scanner(System.in);
		System.out.print("���� �Է� : ");
		int i = scan.nextInt();
		System.out.print("�и� �Է� : ");
		int j = scan.nextInt();
		try {
			System.out.println(i / j);
		}
//		catch (ArithmeticException e) {
		catch (Exception e) {
			System.out.println("0���� ������ ���� �߻�");
			System.out.println(e.getMessage() );
			e.printStackTrace(); // ������ ���� ���� Ȯ��
		}
//		finally {
//			System.out.println("try/catch ���");
//		}
		
		scan.close();
	}

}
