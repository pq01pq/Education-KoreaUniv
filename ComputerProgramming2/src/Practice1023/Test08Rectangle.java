package Practice1023;
// BankTest

// �θ�
class Test08Shape {
	public Test08Shape() {
		System.out.println("Shape()");
	}
}

// �ڽ�
public class Test08Rectangle extends Test08Shape {
	public Test08Rectangle() {
		super();
		System.out.println("Rectangle()");
	}
	
	public static void main(String[] args) {
		// TODO Auto-generated method stub
		Test08Rectangle r = new Test08Rectangle();
	}
}