package Practice1002;

public class Test10 {
	
	public static void main(String[] args) {
		// TODO Auto-generated method stub

		double score[][] = {
				{3.3, 3.4},
				{3.5, 3.6},
				{3.7, 4.0},
				{4.1, 4.2}
		};
		
		double sum = 0;
		
		for(int year = 0; year < score.length; year++) {
			for(int term = 0; term < score[year].length; term++) {
				sum += score[year][term];
			}
		}
		int n = score.length;
		int m = score[0].length;
		System.out.println("전체 평점 평균 : " + sum / (n * m));
	}

}
