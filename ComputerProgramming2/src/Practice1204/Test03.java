package Practice1204;
import java.io.FileInputStream;
import java.io.FileOutputStream;
import java.io.IOException;

public class Test03 {

	public static void main(String[] args) {
		// TODO Auto-generated method stub
		byte b1[] = {7,33,3,4,-1,18};
		int i;
		try {
			FileOutputStream fout = new FileOutputStream("Test3.out");
			
			for(i = 0; i < b1.length; i++)
			{
				fout.write(b1[i]);
			}
			fout.close();
		}
		catch(IOException e) {
			System.out.println("���� �Ұ�! ��� Ȯ��!");
			return;
		}
		System.out.println("���� ����!");
		
		byte b2[] = new byte[6];
		try {
			FileInputStream fin = new FileInputStream("Test3.out");
			int c;
			i = 0;
			while((c = fin.read()) != -1) {
				b2[i++] = (byte)c;
			}
			for(i = 0; i < b2.length; i++) {
				System.out.print(b2[i] + " ");
			}
			fin.close();
		}
		catch(IOException e) {
			System.out.println("���� �б� ����! ��� Ȯ��!");
		}
		
	}
}
