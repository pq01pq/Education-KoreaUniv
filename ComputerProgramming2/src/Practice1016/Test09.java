package Practice1016;
// MyCounter
public class Test09 {
	int counter;
	Test09(int value) {
		counter = value;
	}
	public static void main(String[] args) {
		// TODO Auto-generated method stub
		Test09 obj1 = new Test09(100);
		Test09 obj2 = new Test09(200);
		System.out.println("counter1 = " + obj1.counter);
		System.out.println("counter2 = " + obj2.counter);
	}
}
