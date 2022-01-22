package Practice1106;
abstract class Test07Shape {
	private int x, y;
	public void move(int x, int y) {
		this.x = x;
		this.y = y;
	}
	public abstract void draw();
}

class Test07Rectangle extends Test07Shape {
	private int width, height;
	public void draw() { // 추상 메소드 구현
		System.out.println("사각형 그리기");
	}
}

class Test07Circle extends Test07Shape {
	private int radius;
	public void draw() { // 추상 메소드 구현
		System.out.println("원 그리기");
	}
}
public class Test07BankTest {

	public static void main(String[] args) {
		// TODO Auto-generated method stub
		Test07Rectangle obj1 = new Test07Rectangle();
		Test07Circle obj2 = new Test07Circle();
		obj1.draw();
		obj2.draw();
	}
}
