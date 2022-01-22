package Practice1106;
class Test03Shape {
	protected int x, y;
	
	public void draw() {
		System.out.println("Test03Shape Draw");
	}
}

class Test03Rectangle extends Test03Shape {
	private int width, height;
	@Override // 슈퍼클래스와 형식 똑같아야 오버라이딩 됨
	public void draw() {
		System.out.println("Test03Rectangle Draw");
	}
}

class Test03Circle extends Test03Shape {
	private int radius;
	@Override
	public void draw() {
		System.out.println("Test03Circle Draw");
	}
}

public class Test03 {

	public static void main(String[] args) {
		// TODO Auto-generated method stub
		Test03Shape s1 = new Test03Shape();
		Test03Rectangle s2 = new Test03Rectangle();
		Test03Circle s3 = new Test03Circle();
		
		s1.draw();
		s2.draw();
		s3.draw();
	}
}
