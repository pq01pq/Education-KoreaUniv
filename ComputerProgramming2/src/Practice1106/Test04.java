package Practice1106;
class Test04Shape {
	public Test04Shape next;
	public Test04Shape() {
		next = null;
	}
	
	public void draw() {
		System.out.println("Shape");
	}
}

class Test04Line extends Test04Shape {
	public void draw() {
		System.out.println("Line");
	}
}
class Test04Rect extends Test04Shape {
	public void draw() {
		System.out.println("Rect");
	}
}
class Test04Circle extends Test04Shape {
	public void draw() {
		System.out.println("Circle");
	}
}

public class Test04 {
	// 연결리스트로 도형 연결
	public static void main(String[] args) {
		// TODO Auto-generated method stub
		Test04Shape start, last, obj;
		start = new Test04Line(); // Line 객체 연결
		last = start;
		
		obj = new Test04Rect(); // Rect 객체 연결
		last.next = obj;
		last = obj;
		
		obj = new Test04Line(); // Line 객체 연결
		last.next = obj;
		last = obj;
		
		obj = new Test04Circle(); // Circle 객체 연결
		last.next = obj;
		last = obj;
		
		Test04Shape p = start;
		while(p != null) {
			p.draw();
			p = p.next;
		}
	}
}
