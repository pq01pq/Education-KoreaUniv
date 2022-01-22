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
			/*while((c = fi.read()) != -1) {	// 한 바이트 읽고
				fo.write((char)c);				// 한 바이트 쓰기
			}*/
			byte[] buf = new byte[1024 * 10];	// 10KB 버퍼
			while(true) {
				int n = fi.read(buf);			// 버퍼로 읽어옴(n은 실제 읽은 바이트)
				fo.write(buf, 0, n);			// buf[0]부터 n바이트 쓰기
				if (n < buf.length) break;
			}
			fi.close();
			fo.close();
			System.out.println(src.getPath() + "를 " + dest.getPath() + "로 복사함");
		}
		catch (IOException e) {
			System.out.println("파일 복사 오류");
		}
	}

}
