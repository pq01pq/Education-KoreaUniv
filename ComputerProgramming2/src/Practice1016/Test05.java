package Practice1016;
// Circle
public class Test05 {
	String name;
	int radius;
	
	public Test05() {
		radius = 1;
		name = "";
	}
	public Test05(int r, String s) {
		radius = r;
		name = s;
	}
	
	public double getArea() {
		return 3.14 * radius * radius;
	}
	
	public static void main(String[] args) {
		// TODO Auto-generated method stub
		Test05 pizza;
		pizza = new Test05(10, "����");
		//pizza.name = "����";
		//pizza.radius = 10;
		double area = pizza.getArea();
		System.out.println(pizza.name + "�� ���� : " + area);
		
		Test05 donut = new Test05();
		//donut.name = "����";
		//donut.radius = 2;
		area = donut.getArea();
		System.out.println(donut.name + "�� ���� : " + area);
	}
}
