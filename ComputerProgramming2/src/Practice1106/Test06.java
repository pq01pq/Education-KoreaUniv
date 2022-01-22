package Practice1106;
class Test06Shape {
	int x, y;
	//static
	public void draw() {
		System.out.println("Shape");
	}
}

class Test06Circle extends Test06Shape {
	int x = 1, y = 1;
	@Override
	public void draw() {
		System.out.println("Circle");
	}
}

class Test06Rectangle extends Test06Shape {
	int x = 2, y = 2;
	@Override
	public void draw() {
		System.out.println("Rectangle");
	}
}

class Test06Triangle extends Test06Shape {
	int x = 3, y = 3;
	@Override
	public void draw() {
		System.out.println("Triangle");
	}
}
public class Test06 {

	public static void main(String[] args) {
		// TODO Auto-generated method stub
		Test06Shape s1 = new Test06Circle();
		Test06Shape s2 = new Test06Rectangle();
		Test06Shape s3 = new Test06Triangle();
		System.out.println(s1.x + ", " + s1.y);
		System.out.println(s2.x + ", " + s2.y);
		System.out.println(s2.x + ", " + s2.y);
		s1.draw();
		s2.draw();
		s3.draw();
	}

}
