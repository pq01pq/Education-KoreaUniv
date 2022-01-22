package Practice1120;

public class Test01 {

	public static void main(String[] args) {
		// TODO Auto-generated method stub
		// 명령프롬프트로 실행
		double sum = 0.0;
		
		for(int i = 0; i < args.length; i++)
			sum += Double.parseDouble(args[i]);
		
		System.out.println("합계 : " + sum);
	}
}