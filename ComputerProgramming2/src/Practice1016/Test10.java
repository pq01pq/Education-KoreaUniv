package Practice1016;
// Book
public class Test10 {
	String title;
	String author;
	
	public Test10(String t) {
		title = t;
		author = "���ڹ̻�";
	}
	
	public Test10(String t, String a) {
		title = t;
		author = a;
	}
	public static void main(String[] args) {
		// TODO Auto-generated method stub
		Test10 loveStory = new Test10("���ⵯ");
		Test10 littlePrince = new Test10("�����", "�������丮");
		
		System.out.println(littlePrince.title + " : " + littlePrince.author);
		System.out.println(loveStory.title + " : " + loveStory.author);
	}

}