package Practice1127;
import java.util.HashMap;
import java.util.Scanner;

public class Test06 {

	public static void main(String[] args) {
		// TODO Auto-generated method stub
		HashMap<String, String> dic = new HashMap<String, String>();
		
		dic.put("baby", "�Ʊ�");
		dic.put("love", "���");
		dic.put("apple", "���");
		
		System.out.println(dic);
		
		System.out.println(dic.entrySet());
		System.out.println(dic.keySet());
		System.out.println(dic.values());
		
		Scanner scanner = new Scanner(System.in);
		boolean keep = true;
		while(keep) {
			System.out.print("�ܾ�? ");
			String eng = scanner.next();
			if(eng.equals("exit")) {
				System.out.println("�����մϴ�...");
				keep = false;
			}
			else {
				String kor = dic.get(eng);
				if(kor == null)
					System.out.println("���� �ܾ�!");
				else
					System.out.println(kor);
			}
		}
		scanner.close();
	}
}


