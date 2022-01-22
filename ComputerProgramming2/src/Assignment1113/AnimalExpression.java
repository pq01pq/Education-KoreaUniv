package Assignment1113;
import java.util.Scanner;

class Dog extends Animal {
	public Dog() {
		 color = "Gold";
		 ability = "��������� ����";
		 sound = "�۸�!";
	}
	@Override
	public void showColor() {
		System.out.println("����: " + this.color);
	}
	@Override
	public void showAbility() {
		System.out.println("Ư��: " + ability);
	}
	@Override
	public void hearSound() {
		System.out.println("�Ҹ�: " + this.sound);
	}
}

class Chicken extends Animal {
	public Chicken() {
		color = "Red";
		ability = "���ƿ����� �θ��� ���";
		sound = "������";
	}
	@Override
	public void showColor() {
		System.out.println("����: " + this.color);
	}
	@Override
	public void showAbility() {
		System.out.println("Ư��: " + this.ability);
	}
	@Override
	public void hearSound() {
		System.out.println("�Ҹ�: " + this.sound);
	}
}

class Cat extends Animal {
	public Cat() {
		color = "Gray";
		ability = "����� ô�ϸ� �� ����";
		sound = "�߿�";
	}
	@Override
	public void showColor() {
		System.out.println("����: " + this.color);
	}
	@Override
	public void showAbility() {
		System.out.println("Ư��: " + this.ability);
	}
	@Override
	public void hearSound() {
		System.out.println("�Ҹ�: " + this.sound);
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
			System.out.print("��ȣ ����(1~3) : ");
			int n = scan.nextInt();
			switch(n) {
			case 1:
				System.out.println("<��>");
				break;
			case 2:
				System.out.println("<��>");
				break;
			case 3:
				System.out.println("<�����>");
				break;
			default :
				t = false;
				System.out.println("�����մϴ�.");
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