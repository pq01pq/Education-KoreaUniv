package Practice1023;
// Book
public class Test02Book {
	String title;
	String author;
	
	void show() {
		System.out.println(title + ":" + author);
	}
	public Test02Book() {
		this("", "");
	}
	public Test02Book(String title) {
		this(title, "���ڹ̻�");
	}
	
	public Test02Book(String title, String author) {
		this.title = title;
		this.author = author;
	}
	public static void main(String[] args) {
		// TODO Auto-generated method stub
		Test02Book emptyBook = new Test02Book();
		emptyBook.show();
		
		Test02Book loveStory = new Test02Book("���ⵯ");
		loveStory.show();
		
		Test02Book littlePrince = new Test02Book("�����", "�������丮");
		littlePrince.show();
	}

}