package Practice1002;

public class Test03 {

	public static void main(String[] args) {
		// TODO Auto-generated method stub
		String s = "no news is good news";
		
		int cnt = 0;
		
//		for(int i = 0; i < s.strlen(s); i++) {
//			if (s.charAt(i) == 'n')
//				cnt++;
//		}
		
		for(int i = 0; i < s.length(); i++) {
			if (s.charAt(i) != 'n')
				continue;
			
			cnt++;
		}
		System.out.println(cnt);
	}

}
