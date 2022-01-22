package Practice1127;

public class Test02MyArray {
	public static <T> T getLast(T[] a) {
		return a[a.length - 1];
	}

	public static void main(String[] args) {
		// TODO Auto-generated method stub
		String[] language = {"C++","C#","JAVA"};
		String last = Test02MyArray./*<String>*/getLast(language);
		System.out.println(last);
		
		Integer[] value = {1,3,2,5,4};
		Integer i = Test02MyArray./*<Integer>*/getLast(value);
		System.out.println(i);
	}
}


