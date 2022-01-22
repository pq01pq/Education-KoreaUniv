package Practice0918;

public class Test1 {

	public static void main(String[] args) {
		// TODO Auto-generated method stub
		//�����ڵ�
		char a = 'A';
		char b = 'B';
		char c = '\u0041';
		char d = '\uae00';
		
		System.out.println(a + ", " + b);
		System.out.println(c + "\n" + d);
		System.out.println("\"");
		System.out.println("\\");
		System.out.println("\t");
		
		//���ڿ�
		//String toolName = "JDK";
		String toolName = new String("JDK");
		
		System.out.println(toolName + "���");
		
		System.out.println(toolName + 12);
		System.out.println("(" + 3 + "," + 5 + ")");
	}

}
