package Practice1023;
// BankTest

// 부모
class Test08Shape {
	public Test08Shape() {
		System.out.println("Shape()");
	}
}

// 자식
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