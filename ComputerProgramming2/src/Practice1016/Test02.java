package Practice1016;
import java.util.Scanner;

public class Test02 {
	static void prn(int i, int j) throws Exception {
			System.out.println(i/j);
			// throws Exception : ����ó���� �ڽ��� ȣ���� ���� �޼ҵ�� ���ѱ�
			// ����ó�� ���� �޼ҵ�� ���� �� ����
	}

	public static void main(String[] args) {
		// TODO Auto-generated method stub
		Scanner s = new Scanner(System.in);
		
		System.out.print("ù ��° �� : ");
		int i = s.nextInt();
		
		System.out.print("�� ��° �� : ");
		int j = s.nextInt();
		
		try {
			prn(i, j);
		} catch (Exception e) {
			System.out.println("0���� ������ ���� �߻�");
		}
		
		s.close();
	}
}
