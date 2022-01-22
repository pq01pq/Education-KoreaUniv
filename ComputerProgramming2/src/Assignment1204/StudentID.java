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
	// ���θ� ���ؼ� �Ϻη� �����ϰ� �����Ͽ���
	public static void main(String[] args) throws IOException {
		// TODO Auto-generated method stub
		Scanner scan = new Scanner(System.in);
		FileOutputStream fOut;	OutputStreamWriter write;	BufferedWriter bWrite;
		FileInputStream fIn;	InputStreamReader read;	BufferedReader bRead;
		String idName;
		
		System.out.println("1 : ������ �Է�\n2 : ������ ���\n3 : ���� ����");
		int choose = 0;
		while(choose < 4) {
			System.out.println();
			System.out.print("�Է� : ");	choose = scan.nextInt();
			switch(choose) {
			case 1 :
				System.out.print("�й� : ");	String id = scan.next();
				System.out.print("�̸� : ");	String name = scan.next();
				idName = id + " " + name;
				try {
					fOut = new FileOutputStream("������.txt");
					write = new OutputStreamWriter(fOut, "UTF8");
					bWrite = new BufferedWriter(write, 20);
					bWrite.write(idName);
					bWrite.close();	write.close();	fOut.close();
					System.out.println("������ �Է� �Ϸ�");
				}
				catch (IOException e) {
					System.out.println("������ �Է� ����");
				}
				break;
			case 2 :
				try {
					fIn = new FileInputStream("������.txt");
					read = new InputStreamReader(fIn, "UTF8");
					bRead = new BufferedReader(read);
					System.out.println("���� �б� �Ϸ�");
					
					while((idName = bRead.readLine()) != null)
						System.out.println(idName);
					bRead.close();	read.close();	fIn.close();
				}
				catch (IOException e) {
					System.out.println("���� �б� ����");
				}
				break;
			case 3 :
				File original = new File("������.txt");
				File copy = new File("������2.txt");
				try {
					fIn = new FileInputStream(original);
					read = new InputStreamReader(fIn, "UTF8");
					bRead = new BufferedReader(read);
					System.out.println("���� �б� �Ϸ�");
					try {
						fOut = new FileOutputStream(copy);
						write = new OutputStreamWriter(fOut, "UTF8");
						bWrite = new BufferedWriter(write, 20);
						
						while((idName = bRead.readLine()) != null) {
							bWrite.write(idName);
						}
						bWrite.close();	write.close();	fOut.close();
						bRead.close();	read.close();	fIn.close();
						System.out.println("������ ���� �Ϸ�");
					}
					catch (IOException e2) {
						System.out.println("������ ���� ����");
					}
				}
				catch (IOException e1) {
					System.out.println("���� �б� ����");
				}
				break;
			default :
				break;
			}
		}
		scan.close();
	}
}
