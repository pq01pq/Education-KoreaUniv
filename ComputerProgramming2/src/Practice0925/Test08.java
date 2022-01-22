package Practice0925;

public class Test08 {

	public static void main(String[] args) {
		// TODO Auto-generated method stub
		//int i, sum;
		for(int i = 1, sum = 0; i < 11; i++) {
			sum += i;
			
			System.out.printf("%d ", i);
			
			if (i < 10)
				System.out.print("+ ");
			else
				System.out.printf("= %d", sum);
				
		}
		// System.out.printf("= %d", sum);
	}

}
