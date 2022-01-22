package Practice1106;
abstract class Test08Calculator {
	public abstract int add(int a, int b);
	public abstract int subtract(int a, int b);
	public abstract double average(int[] a);
}

public class Test08GoodCalc extends Test08Calculator {
	//@Override
	public int add(int a, int b) {
		return a + b;
	}
	
	//@Override
	public int subtract(int a, int b) {
		return a - b;
	}
	
	//@Override
	public double average(int[] a) {
		double sum = 0;
		for(int i = 0; i < a.length; i++)
			sum += a[i];
		return sum / a.length;
	}
	
	public static void main(String[] args) {
		// TODO Auto-generated method stub
		Test08GoodCalc c = new Test08GoodCalc();
		System.out.println("2 + 3 = " + c.add(2, 3));
		System.out.println("2 - 3 = " + c.subtract(2, 3));
		System.out.println("2 ~ 4 ЦђБе = " + c.average(new int[] {2, 3, 4}));
	}

}
