package Assignment1204;
import java.io.BufferedReader;
import java.io.BufferedWriter;
import java.io.File;
import java.io.FileInputStream;
import java.io.FileOutputStream;
import java.io.IOException;
import java.io.InputStreamReader;
import java.io.OutputStreamWriter;
import java.util.Scanner;

public class StudentID {
	// 공부를 위해서 일부러 복잡하게 구성하였음
	public static void main(String[] args) throws IOException {
		// TODO Auto-generated method stub
		Scanner scan = new Scanner(System.in);
		FileOutputStream fOut;	OutputStreamWriter write;	BufferedWriter bWrite;
		FileInputStream fIn;	InputStreamReader read;	BufferedReader bRead;
		String idName;
		
		System.out.println("1 : 데이터 입력\n2 : 데이터 출력\n3 : 파일 복사");
		int choose = 0;
		while(choose < 4) {
			System.out.println();
			System.out.print("입력 : ");	choose = scan.nextInt();
			switch(choose) {
			case 1 :
				System.out.print("학번 : ");	String id = scan.next();
				System.out.print("이름 : ");	String name = scan.next();
				idName = id + " " + name;
				try {
					fOut = new FileOutputStream("오정석.txt");
					write = new OutputStreamWriter(fOut, "UTF8");
					bWrite = new BufferedWriter(write, 20);
					bWrite.write(idName);
					bWrite.close();	write.close();	fOut.close();
					System.out.println("데이터 입력 완료");
				}
				catch (IOException e) {
					System.out.println("데이터 입력 실패");
				}
				break;
			case 2 :
				try {
					fIn = new FileInputStream("오정석.txt");
					read = new InputStreamReader(fIn, "UTF8");
					bRead = new BufferedReader(read);
					System.out.println("파일 읽기 완료");
					
					while((idName = bRead.readLine()) != null)
						System.out.println(idName);
					bRead.close();	read.close();	fIn.close();
				}
				catch (IOException e) {
					System.out.println("파일 읽기 실패");
				}
				break;
			case 3 :
				File original = new File("오정석.txt");
				File copy = new File("오정석2.txt");
				try {
					fIn = new FileInputStream(original);
					read = new InputStreamReader(fIn, "UTF8");
					bRead = new BufferedReader(read);
					System.out.println("파일 읽기 완료");
					try {
						fOut = new FileOutputStream(copy);
						write = new OutputStreamWriter(fOut, "UTF8");
						bWrite = new BufferedWriter(write, 20);
						
						while((idName = bRead.readLine()) != null) {
							bWrite.write(idName);
						}
						bWrite.close();	write.close();	fOut.close();
						bRead.close();	read.close();	fIn.close();
						System.out.println("데이터 복사 완료");
					}
					catch (IOException e2) {
						System.out.println("데이터 복사 실패");
					}
				}
				catch (IOException e1) {
					System.out.println("파일 읽기 실패");
				}
				break;
			default :
				break;
			}
		}
		scan.close();
	}
}
