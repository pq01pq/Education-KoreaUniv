package Practice1127;
import java.util.Vector;
import java.util.Iterator;

public class Test05 {

	public static void main(String[] args) {
		// TODO Auto-generated method stub
		Vector<Integer> v = new Vector<Integer>();	// �������� �ٷ�� ���׸� ����
		v.add(5);	v.add(4);	v.add(-1);			// ����
		v.add(2, 100);								// ���� �߰��� ���� 100 ����
		System.out.println(v);
		System.out.println(v.size());
		System.out.println(v.capacity());
		
		//for(int i = 0; i< v.size(); i++) {	// ��� ���(����) ����ϱ�
		//	int n = v.get(i);
		//	System.out.println(n);
		//}
		Iterator<Integer> it = v.iterator();
		while(it.hasNext()) {
			Integer n = it.next();
			System.out.println(n);
		}
		int sum = 0;
		//for(int i = 0; i < v.size(); i++) {	// ���� �� ��� ���� ���ϱ�
		//	int n = v.elementAt(i);
		//	sum += n;
		//}
		for(int num : v)
			sum += num;
		System.out.println(sum);
	}

}
