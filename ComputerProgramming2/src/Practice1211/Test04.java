package Practice1211;

public class Test04 implements Runnable {
	String name;
	public Test04(String name) {
		this.name = name;
	}
	public void run()  // �����尡 ������ �۾� ���
	{
		for(int i = 10; i >= 0; i--) {
			System.out.print(name + i + " ");
		}
	}
	
	public static void main(String[] args) {
		// TODO Auto-generated method stub
		Thread t1 = new Thread(new Test04("A"));
		t1.start();
		Thread t2 = new Thread(new Test04("B"));
		t2.start();
		//new Thread(new Test04()).start();
	}

}
