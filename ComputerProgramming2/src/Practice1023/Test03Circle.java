package Practice1023;

public class Test03Circle {

	int radius;
	
	public Test03Circle(int radius) {
		this.radius = radius;
	}
	
	public double getArea() {
		return 3.14 * radius * radius;
	}
	
	public static void main(String[] args) {
		// TODO Auto-generated method stub

		Test03Circle[] c = new Test03Circle[5];
		
		for(int i = 0; i < c.length; i++)
			c[i] = new Test03Circle(i);
		
		for(int i = 0; i < c.length; i++)
			System.out.println(c[i].getArea());
	}

}
