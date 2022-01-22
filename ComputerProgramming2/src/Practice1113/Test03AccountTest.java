package Practice1113;

public class Test03AccountTest {

	public static void main(String[] args) {
		// TODO Auto-generated method stub
		Test03Account obj = new Test03Account();
		obj.setName("Tom");
		obj.setBalance(100000);
		System.out.println("이름 = " + obj.getName());
		System.out.println("통장 잔고 = " + obj.getBalance());
	}
}