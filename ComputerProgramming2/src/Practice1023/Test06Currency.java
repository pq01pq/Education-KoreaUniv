package Practice1023;
import java.util.Scanner;

public class Test06Currency {
	
	private static double rate;	// ��ȭ�� ���� ȯ��
	
	public static double toDollar(double won) {
		return won/rate;		// ��ȭ�� �޷��� ��ȯ
	}
	
	public static double toKWR(double dollar) {
		return dollar * rate;	// �޷��� ��ȭ�� ��ȯ
	}
	
	public static void setRate(double r) {
		rate = r;				// ȯ�� ���� (KWR/$1)
	}

	public static void main(String[] args) {
		// TODO Auto-generated method stub

		Scanner scan = new Scanner(System.in);
		
		System.out.print("ȯ��(1�޷�)>> "); // 1172
		double rate = scan.nextDouble();
		Test06Currency.setRate(rate); // �̱� �޷� ȯ�� ����
		
		System.out.print("��ȭ �Է�>> "); // 1000000
		int won = scan.nextInt();
		System.out.println("$" + Test06Currency.toDollar(won));
		
		System.out.print("�޷� �Է�>> "); // 100
		int dol = scan.nextInt();
		System.out.println(Test06Currency.toKWR(dol) + "��");
		
		scan.close();
	}

}
