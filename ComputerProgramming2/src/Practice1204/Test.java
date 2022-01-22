package Practice1204;
import java.io.File;
import java.io.FileInputStream;
import java.io.FileOutputStream;
import java.io.IOException;

public class Test {

	public static void main(String[] args) {
		// TODO Auto-generated method stub
		File src = new File("C:\\Windows\\Web\\Wallpaper\\Theme1\\img1.jpg");
		File dest = new File("copyimg.jpg");
		//int c;
		try {
			FileInputStream fi = new FileInputStream(src);
			FileOutputStream fo = new FileOutputStream(dest);
			/*while((c = fi.read()) != -1) {	// �� ����Ʈ �а�
				fo.write((char)c);				// �� ����Ʈ ����
			}*/
			byte[] buf = new byte[1024 * 10];	// 10KB ����
			while(true) {
				int n = fi.read(buf);			// ���۷� �о��(n�� ���� ���� ����Ʈ)
				fo.write(buf, 0, n);			// buf[0]���� n����Ʈ ����
				if (n < buf.length) break;
			}
			fi.close();
			fo.close();
			System.out.println(src.getPath() + "�� " + dest.getPath() + "�� ������");
		}
		catch (IOException e) {
			System.out.println("���� ���� ����");
		}
	}

}
