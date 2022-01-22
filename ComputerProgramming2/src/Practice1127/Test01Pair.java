package Practice1127;

public class Test01Pair <F, V> {
	private F data1;
	private V data2;
	
	public Test01Pair(F field, V value) {
		this.data1 = field;
		this.data2 = value;
	}
	public F getKey() {
		return data1;
	}
	public V getValue() {
		return data2;
	}

	public static void main(String[] args) {
		// TODO Auto-generated method stub
		Test01Pair<String, Integer> p1 = new  Test01Pair <String, Integer>("학번:", 12345678);
		System.out.println(p1.getKey() + " " + p1.getValue());
		Test01Pair<String, String> p2 = new Test01Pair<String, String>("이름:", "홍길동");
		System.out.println(p2.getKey() + " " + p2.getValue());
	}
}


