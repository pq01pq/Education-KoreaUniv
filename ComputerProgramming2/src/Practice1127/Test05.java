package Practice1127;
import java.util.Vector;
import java.util.Iterator;

public class Test05 {

	public static void main(String[] args) {
		// TODO Auto-generated method stub
		Vector<Integer> v = new Vector<Integer>();	// 정수값만 다루는 제네릭 벡터
		v.add(5);	v.add(4);	v.add(-1);			// 삽입
		v.add(2, 100);								// 벡터 중간에 정수 100 삽입
		System.out.println(v);
		System.out.println(v.size());
		System.out.println(v.capacity());
		
		//for(int i = 0; i< v.size(); i++) {	// 모든 요소(정수) 출력하기
		//	int n = v.get(i);
		//	System.out.println(n);
		//}
		Iterator<Integer> it = v.iterator();
		while(it.hasNext()) {
			Integer n = it.next();
			System.out.println(n);
		}
		int sum = 0;
		//for(int i = 0; i < v.size(); i++) {	// 벡터 내 모든 정수 더하기
		//	int n = v.elementAt(i);
		//	sum += n;
		//}
		for(int num : v)
			sum += num;
		System.out.println(sum);
	}

}
