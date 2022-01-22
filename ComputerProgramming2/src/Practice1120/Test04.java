package Practice1120;
class Test04Box<T> {
	private T data;
	
	public T getData() {
		return data;
	}

	public void setData(T data) {
		this.data = data;
	}
}

public class Test04 {

	public static void main(String[] args) {
		// TODO Auto-generated method stub
		//Test04Box<String> b = new Test04Box<String>();
		Test04Box<String> b = new Test04Box<>(); // 컴파일러가 클래스명을 추론 가능한 경우 생략 가능
		// <> 안에는 객체 클래스 타입이 들어가야함
		b.setData("자바");
		String s = b.getData();
		System.out.println(s);
		
		//Test04Box<Integer> b2 = new Test04Box<Integer>();
		Test04Box<Integer> b2 = new Test04Box<>();
		b2.setData(10);
		int i = b2.getData();
		System.out.println(i);
	}
}
