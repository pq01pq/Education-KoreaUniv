package Practice0918;
import java.util.Scanner;

public class Test8 {

	public static void main(String[] args) {
		// TODO Auto-generated method stub
		Scanner input = new Scanner(System.in);
		
		System.out.print("������ �Է��Ͻÿ� : ");
		String line = input.nextLine();
		System.out.println(line);
		
		System.out.print("��ū ������ �Է��Ͻÿ� : ");
		String word = input.next();
		int age = input.nextInt();
		float height = input.nextFloat();
		double weight = input.nextDouble();
		boolean bool = input.nextBoolean();
		
		System.out.println("�̸� : " + word);
		System.out.println("���� : " + age);
		System.out.println("Ű : " + height + " ������ : " + weight);
		System.out.println(bool);
		
		input.close();
	}

}
