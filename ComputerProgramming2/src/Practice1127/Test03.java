package Practice1127;
import java.util.ArrayList;
import java.util.Iterator;
import java.util.Scanner;

public class Test03 {
	public static <T> T getLast(T[] a) {
		return a[a.length - 1];
	}

	public static void main(String[] args) {
		// TODO Auto-generated method stub
		ArrayList<String> a = new ArrayList<String>();
		Scanner scanner = new Scanner(System.in);
		for(int i = 0; i < 4; i++) {
			System.out.print("이름 입력>> ");
			String s = scanner.next();
			a.add(s);
		}
		System.out.println(a.size());
		/*for(int i = 0; i < a.size(); i++) {
		String name = a.get(i);
		System.out.print(name + " ");
		}*/
		Iterator<String> it = a.iterator();
		while(it.hasNext()) {
			System.out.println(it.next());
		}
		
		System.out.print("\n삭제할 번호>> ");
		int i =scanner.nextInt();
		a.remove(i);
		System.out.println(a);
		
		scanner.close();
	}
}


