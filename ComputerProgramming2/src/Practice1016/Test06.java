package Practice1016;
import java.util.Scanner;
// Rectangle
public class Test06 {
	double width;
	double height;
	
	public Test06() {
		width = 3.14;
		height = 2.72;
	}
	
	public double getArea() {
		return width * height;
	}
	public static void main(String[] args) {
		// TODO Auto-generated method stub
		Test06 rect = new Test06();
		Scanner scan = new Scanner(System.in);
		
		//System.out.print("�ʺ� �Է� : ");
		//rect.width = scan.nextDouble();
		//System.out.print("���� �Է� : ");
		//rect.height = scan.nextDouble();
		
		System.out.println("�簢���� ���� : " + rect.getArea());
		
		scan.close();
	}

}
