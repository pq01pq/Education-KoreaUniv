package Practice1023;
import java.util.Scanner;

public class Test04Book {

	String title, author;
	
	public Test04Book(String title, String author) {
		this.title = title;
		this.author = author;
	}
	
	public static void main(String[] args) {
		// TODO Auto-generated method stub
		Scanner scan = new Scanner(System.in);
		Test04Book[] book = new Test04Book[2];
		String title, author;
		
		for(int i = 0; i < book.length; i++) {
			System.out.print("제목 >> ");
			title = scan.nextLine();
			System.out.print("저자 >> ");
			author = scan.nextLine();
			book[i] = new Test04Book(title, author); // new 중요
		}
		
		for(int i = 0; i < book.length; i++) {
			System.out.println("(" + book[i].title + ":" + book[i].author + ")");
		}
		scan.close();
	}

}
