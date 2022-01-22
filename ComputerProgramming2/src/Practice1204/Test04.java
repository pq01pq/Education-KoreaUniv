package Practice1204;
import java.io.BufferedReader;
import java.io.FileInputStream;
import java.io.IOException;
import java.io.InputStreamReader;

public class Test04 {

	public static void main(String[] args) throws IOException {
		// TODO Auto-generated method stub
		FileInputStream file = new FileInputStream("Korean.txt");
		BufferedReader in = new BufferedReader(new InputStreamReader(file, "UTF8"));
		
		String str;
		while((str = in.readLine()) != null) {
			System.out.println(str);
		}
		
		in.close();
	}
}
