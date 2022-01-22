package Assignment1113;
import java.util.Scanner;

class Dog extends Animal {
	public Dog() {
		 color = "Gold";
		 ability = "으르렁대며 물기";
		 sound = "멍멍!";
	}
	@Override
	public void showColor() {
		System.out.println("색상: " + this.color);
	}
	@Override
	public void showAbility() {
		System.out.println("특기: " + ability);
	}
	@Override
	public void hearSound() {
		System.out.println("소리: " + this.sound);
	}
}

class Chicken extends Animal {
	public Chicken() {
		color = "Red";
		ability = "날아오르며 부리로 찍기";
		sound = "꼬끼오";
	}
	@Override
	public void showColor() {
		System.out.println("색상: " + this.color);
	}
	@Override
	public void showAbility() {
		System.out.println("특기: " + this.ability);
	}
	@Override
	public void hearSound() {
		System.out.println("소리: " + this.sound);
	}
}

class Cat extends Animal {
	public Cat() {
		color = "Gray";
		ability = "우아한 척하며 털 고르기";
		sound = "야옹";
	}
	@Override
	public void showColor() {
		System.out.println("색상: " + this.color);
	}
	@Override
	public void showAbility() {
		System.out.println("특기: " + this.ability);
	}
	@Override
	public void hearSound() {
		System.out.println("소리: " + this.sound);
	}
}

public class AnimalExpression {

	public static void main(String[] args) {
		// TODO Auto-generated method stub
		Scanner scan = new Scanner(System.in);
		Animal[] a = new Animal[3];
		a[0] = new Dog();
		a[1] = new Chicken();
		a[2] = new Cat();
		
		boolean t = true;
		while (t) {
			System.out.print("번호 선택(1~3) : ");
			int n = scan.nextInt();
			switch(n) {
			case 1:
				System.out.println("<개>");
				break;
			case 2:
				System.out.println("<닭>");
				break;
			case 3:
				System.out.println("<고양이>");
				break;
			default :
				t = false;
				System.out.println("종료합니다.");
				break;
			}
			if(t) {
				a[n - 1].showColor();
				a[n - 1].showAbility();
				a[n - 1].hearSound();
				System.out.println();
			}
		}
		scan.close();
	}
}