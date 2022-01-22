package Practice1120;
class Test05Pair<T> {
	private T data1, data2;
	public Test05Pair(T value1, T value2) {
		this.data1 = value1; this.data2 = value2;
	}
	public T getFirst() {
		return data1;
	}
	public T getSecond() {
		return data2;
	}
}

public class Test05 {

	public static void main(String[] args) {
		// TODO Auto-generated method stub
		//Box<String> b = new Box<String>();
		Test05Pair<String> pair = new Test05Pair<String>("Apple", "Tomato");
		System.out.println(pair.getFirst()+", "+pair.getSecond());
		
		Test05Pair<Double>db = new Test05Pair<Double>(1.5, 2.3);
		System.out.println(db.getFirst()+", "+db.getSecond());
	}
}
