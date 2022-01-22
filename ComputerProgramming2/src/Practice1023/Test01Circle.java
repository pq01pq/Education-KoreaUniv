package Practice1023;

public class Test01Circle {

	int radius;
	
	public Test01Circle() {
		this.radius = 1;
	}
	public Test01Circle(int radius) {
		this.radius = radius; // this.radius는 Circle 클래스의 멤버, radius는 메인함수의 객체
	}
	double getArea() {
		return 3.14 * this.radius * this.radius;
	}
	
	public static void main(String[] args) {
		// TODO Auto-generated method stub

		Test01Circle donut = new Test01Circle();
		System.out.println(donut.getArea());
		
		Test01Circle pizza = new Test01Circle(10);
		System.out.println(pizza.getArea());
	}

}
