package Practice0918;

public class Test6 {

	public static void main(String[] args) {
		// TODO Auto-generated method stub
		int n = 300;
		byte b = (byte)n;
		
		System.out.println(n + ", " + b);
		
		double d = 1.9;
		int x = (int)d;
		System.out.println(d + ", " + x);
		
		double f = 10; // int(4byte) -> double(8byte)로 형변환
		System.out.println(f);
		
		//int i = 3.141592; //double(8byte) -> int(4byte)로 형변환 : 오류
		//System.out.println(i);
	}

}
