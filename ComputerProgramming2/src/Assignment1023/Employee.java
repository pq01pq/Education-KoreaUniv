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
		System.out.println("현재 직원 수 = " + count);
	}

	public static void main(String[] args) {
		Scanner scan = new Scanner(System.in);
		Employee[] employee = new Employee[MAX_EMPLOYEE]; // 배열의 메모리를 할당
		String name;
		int annualIncome;
		
		for(int i = 0; i < employee.length; i++)
		{
			System.out.print("이름>> ");
			name = scan.next();
			System.out.print("연봉>> ");
			annualIncome = scan.nextInt();
			employee[i] = new Employee(name, annualIncome); // 객체의 메모리를 할당
			employee[i].getCount();
			System.out.println();
		}
		scan.close();
	}
}
