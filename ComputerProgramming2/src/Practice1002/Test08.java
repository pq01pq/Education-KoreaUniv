package Practice1002;

public class Test08 {
	enum Weekday {월, 화, 수, 목, 금}
	
	public static void main(String[] args) {
		// TODO Auto-generated method stub
		String names[] = {"월", "화", "수", "목", "금"};
		
		for (String s : names)
			System.out.print(s + "요일 ");
		System.out.println();
		
		for (Weekday days : Weekday.values())
			System.out.print(days + "요일 ");
		System.out.println();
	}

}
