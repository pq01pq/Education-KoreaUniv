package Practice1127;
import java.util.ArrayList;
import java.util.Iterator;
import java.util.Scanner;

public class Test04 {

	public static void main(String[] args) {
		// TODO Auto-generated method stub
		ArrayList<String> a = new ArrayList<String>();
		Scanner scanner = new Scanner(System.in);
		for(int i = 0; i < 4; i++) {
			System.out.print("�̸� �Է�>> "); // apple, grape, banana, pear
			String s = scanner.next();
			a.add(s);
		}
		System.out.println(a.size());
		Iterator<String> it = a.iterator();
		while(it.hasNext()) {
			System.out.print(it.next() + " ");
		}
		it.remove();
		int longest = 0;
		for(int i = 1; i< a.size(); i++)
			if(a.get(longest).length() < a.get(i).length())
				longest = i;
		
		System.out.println("\n���� �� �̸�: " + a.get(longest));
		
		scanner.close();
	}

}
