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
		// offset : ���� ��ġ, length : ���̸�ŭ ���Ͽ� ����
		while(true)
		{
			System.out.print("�Է�>> ");
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
