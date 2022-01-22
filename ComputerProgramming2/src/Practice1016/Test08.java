package Practice1016;
// 오버로딩
public class Test08 {
	
	int square(int i) {
		return i * i;
	}
	
	double square(double i) {
		return i * i;
	}
	
	public static void main(String[] args) {
		// TODO Auto-generated method stub
		int num1 = 20;
		double num2 = 3.14;
		Test08 obj = new Test08();
		System.out.println(obj.square(num1));
		System.out.println(obj.square(num2));
	}
}
