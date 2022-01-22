package Practice1204;
import java.io.FileWriter;
import java.io.IOException;
import java.util.Scanner;

public class Test01 {

	public static void main(String[] args) throws IOException {
		// TODO Auto-generated method stub
		FileWriter fout = null;
		Scanner scan = new Scanner(System.in);
		String line;
		
		fout = new FileWriter("Test2.txt");
		// fout.write(String, offset, length)
		// offset : 현재 위치, length : 길이만큼 파일에 써줌
		while(true)
		{
			System.out.print("입력>> ");
			line = scan.nextLine();
			if(line.length() == 0)
				break;
			fout.write(line, 0, line.length());
			fout.write("\r\n", 0, 2);
		}
		
		fout.close();
		scan.close();
	}

}
