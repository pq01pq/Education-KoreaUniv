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
		Test04Box<String> b = new Test04Box<>(); // �����Ϸ��� Ŭ�������� �߷� ������ ��� ���� ����
		// <> �ȿ��� ��ü Ŭ���� Ÿ���� ������
		b.setData("�ڹ�");
		String s = b.getData();
		System.out.println(s);
		
		//Test04Box<Integer> b2 = new Test04Box<Integer>();
		Test04Box<Integer> b2 = new Test04Box<>();
		b2.setData(10);
		int i = b2.getData();
		System.out.println(i);
	}
}
