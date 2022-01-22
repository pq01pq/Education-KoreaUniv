package Assignment1023;
import java.util.Scanner;

public class Employee {
	
	public static final int MAX_EMPLOYEE = 3;
	
	String name;
	int annualIncome;
	static int count = 0;
	
	public Employee(String name, int annualIncome){
		this.name = name;
		this.annualIncome = annualIncome;
		count++;
	}
	
	void getCount() {
		System.out.println("���� ���� �� = " + count);
	}

	public static void main(String[] args) {
		Scanner scan = new Scanner(System.in);
		Employee[] employee = new Employee[MAX_EMPLOYEE]; // �迭�� �޸𸮸� �Ҵ�
		String name;
		int annualIncome;
		
		for(int i = 0; i < employee.length; i++)
		{
			System.out.print("�̸�>> ");
			name = scan.next();
			System.out.print("����>> ");
			annualIncome = scan.nextInt();
			employee[i] = new Employee(name, annualIncome); // ��ü�� �޸𸮸� �Ҵ�
			employee[i].getCount();
			System.out.println();
		}
		scan.close();
	}
}
