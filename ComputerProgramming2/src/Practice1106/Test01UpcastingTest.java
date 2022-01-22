package Practice1106;
class Test01Person {
	String name;
	String id;
	
	public Test01Person(String name) {
		this.name = name;
	}
}

class Test01Student extends Test01Person {
	String grade;
	String department;
	
	public Test01Student(String name) {
		super(name);
	}
}

public class Test01UpcastingTest {

	public static void main(String[] args) {
		// upcasting test
		Test01Person p1;
		Test01Student s1 = new Test01Student("ȫ�浿");
		
		p1 = s1; // upcasting
		
		System.out.println(p1.name);
		
		//p1.grade = "A";
		//p1.department = "Com";
		
		s1.grade = "A";
		s1.department = "Com";
		
		// downcasting test
		Test01Person p2 = new Test01Student("ȫ�浿");
		Test01Student s2;
		
		s2 = (Test01Student) p2;
		
		s2.grade = "A";
		System.out.println(s2.name + ", " + s2.grade);
		//System.out.println(p2.name + ", " + p2.grade);
	}
}
