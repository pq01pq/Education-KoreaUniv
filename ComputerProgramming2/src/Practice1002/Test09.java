package Practice1002;

public class Test09 {

	public static void main(String[] args) {
		// TODO Auto-generated method stub
		int[][] a = { {10, 20, 30, 40},
				{50, 60, 70, 80},
				{90, 100, 110, 120}
		};
		
//		for(int row = 0; row < a.length; row++) {
//			for(int column = 0; column < a[row].length; column++)
//				System.out.print(a[row][column] + " ");
//			System.out.println();
//		}
		for(int[] row : a) {
			for(int column : row)
				System.out.print(column + " ");
			System.out.println();
		}
	}

}
