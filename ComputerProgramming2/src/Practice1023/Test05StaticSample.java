package Practice1023;

public class Test05StaticSample {

	public int n;
	static public int m;
	
	protected void g() {
		m = 20;
	}
	
	protected void h() {
		m = 30;
	}
	
	static protected void f() {
		m = 5;
	} // static ¸â¹ö´Â °´Ã¼¸¦ ±»ÀÌ »ý¼ºÇÏÁö ¾Ê¾Æµµ µÊ
	public static void main(String[] args) {
		// TODO Auto-generated method stub

		Test05StaticSample S1, S2;
		
		S1 = new Test05StaticSample();
		S1.n = 5;
		S1.g();
//		S1.m = 50; // static
		Test05StaticSample.m = 50;
//		System.out.println(S1.m);
		System.out.println(Test05StaticSample.m);
		
		S2 = new Test05StaticSample();
		S2.n = 8;
		S2.h();
//		S2.f(); // static
		Test05StaticSample.f();
//		System.out.println(S2.m);
		System.out.println(Test05StaticSample.m);
	}

}
