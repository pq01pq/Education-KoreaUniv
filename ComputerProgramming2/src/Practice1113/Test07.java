package Practice1113;
class Test07Point {
	int x, y;
	public Test07Point(int x, int y) {
		this.x = x; this.y = y;
	}
}
public class Test07 {

	public static void main(String[] args) {
		// TODO Auto-generated method stub
		Test07Point p = new Test07Point(2,3);
		System.out.println(p);
		System.out.println(p.toString());
		System.out.println(p.getClass());
		System.out.println(p.getClass().getName());
		System.out.println(p.hashCode());
	}

}
