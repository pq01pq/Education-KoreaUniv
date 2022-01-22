package Practice1023;
// PointTest

// 부모
class Test07Point {

	private int x, y;
	
	public void set(int x, int y) {
		this.x = x;
		this.y = y;
	}
	
	public void showPoint() {
		System.out.println("(" + x + ", " + y + ")");
	}
}

// 자식
public class Test07ColorPoint extends Test07Point {
	private String color;
	
	public void setColor(String color) {
		this.color = color;
	}
	
	public void showColorPoint() {
		System.out.print(color);
		showPoint();
	}
	
	public static void main(String[] args) {
		// TODO Auto-generated method stub
		Test07ColorPoint p = new Test07ColorPoint();
		p.set(3, 4);
		p.showPoint();
		
		Test07ColorPoint cp = new Test07ColorPoint();
		cp.set(3, 4);
		cp.setColor("red");
		cp.showColorPoint();
	}
}