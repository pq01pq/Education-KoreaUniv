package Practice1106;
class Test05Point {
	private int x, y;
	
	public Test05Point(int a, int b) {
		x = a;
		y = b;
	}
	@Override
	public String toString() {
		return "[X=" + x + ", Y=" + y + "]";
	}
}

class Test05Circle {
	private int radius;
	private Test05Point center;
	
	public Test05Circle(Test05Point p, int r) {
		center = p;
		radius = r;
	}
	@Override
	public String toString() {
		return "반지름 : " + radius + "\n중심 : " + center;
	}
}
public class Test05 {

	public static void main(String[] args) {
		// TODO Auto-generated method stub
		Test05Point p = new Test05Point(25, 78);
		System.out.println(p); // toString() 호출
		//System.out.println(p.toString());
		
		Test05Circle c = new Test05Circle(p, 10);
		System.out.println(c); // toString() 호출
		//System.out.println(c.toString());
	}

}
