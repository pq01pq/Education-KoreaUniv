package Practice1113;

public class Test04 {

	public static void main(String[] args) {
		// TODO Auto-generated method stub
		Test04Person p = new Test04Person();
		System.out.print(p.getWeight());
		System.out.println(", " + p.age + ", " + p.height + ", " + p.name);
		
		Test04Student s = new Test04Student();
		s.set();
		System.out.print(s.getWeight());
		System.out.println(", " + s.age + ", " + s.height + ", " + s.name);
	}

}
