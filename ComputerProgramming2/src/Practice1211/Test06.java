package Practice1211;
class Test06Timer {
	private int value = 0;
	public synchronized void increment() {value++;}
	public synchronized void decrement() {value--;}
	public synchronized void prn() {
		System.out.println(Thread.currentThread().getName() + ":" + value);
	}
}

class Test06MyThread extends Thread {
	Test06Timer cnt;
	public Test06MyThread(Test06Timer c) {this.cnt = c;}
	public void run() {
		int i = 0;
		while(i < 20) {
			cnt.increment();
			cnt.decrement();
			cnt.prn();
			try {sleep( (int) Math.random() * 2);} // 난수 시간(0 or 1) 만큼
			catch (InterruptedException e) {System.out.println("Interruption");
			i++;
			}
		}
	}
}

class Test06 {
	public static void main(String[] args) {
		// TODO Auto-generated method stub
		Test06Timer c = new Test06Timer();
		new Test06MyThread(c).start();
		new Test06MyThread(c).start();
		new Test06MyThread(c).start();
	}
	
}