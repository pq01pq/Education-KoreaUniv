package Practice1211;

public class Test03 extends Thread {
	String name;
	public Test03(String name) {
		this.name = name;
	}
	public void run() // 스레드가 수행할 작업 명시
	{
		for(int i = 10; i >= 0; i--) {
			System.out.print(name + i + " ");
		}
	}
	
	public static void main(String[] args) {
		// TODO Auto-generated method stub
		Thread t1 = new Test03("A");
		t1.start();
		Thread t2 = new Test03("B");
		t2.start();
		//t.start();
		//new Test03().start();
	}

}
