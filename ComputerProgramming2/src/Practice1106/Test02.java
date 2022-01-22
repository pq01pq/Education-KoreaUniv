package Practice1106;
class Test02Person { }
class Test02Student extends Test02Person { }
class Test02Researcher extends Test02Person { }
class Test02Professor extends Test02Researcher { }

public class Test02 {
	static void print(Test02Person p) {
		if (p instanceof Test02Person)
			System.out.print("Test02Person! ");
		if (p instanceof Test02Student)
			System.out.print("Test02Student! ");
		if (p instanceof Test02Researcher)
			System.out.print("Test02Researcher! ");
		if (p instanceof Test02Professor)
			System.out.print("Test02Professor! ");
	}
	
	public static void main(String[] args) {
		// TODO Auto-generated method stub
		System.out.print("new Test02Student() ->\t");
		print(new Test02Student());
		System.out.println();
		
		System.out.print("new Test02Researcher() ->\t");
		print(new Test02Researcher());
		System.out.println();
		
		System.out.print("new Test02Professor() ->\t");
		print(new Test02Professor());
		System.out.println();
		
		Test02Professor pr = new Test02Professor();
		System.out.println(pr.getClass());
		System.out.println(pr.getClass().getName());
	}

}
