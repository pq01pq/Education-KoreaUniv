package Assignment1113;

class Animal implements AnimalTrait {
	String color;
	String ability;
	String sound;
	
	public Animal() {
		color = "Transparent";
		ability = "�ƹ��͵� ����";
		sound = "�ƹ� �Ҹ��� �ȳ�";
	}
	
	public void showColor() {
		System.out.println("����: " + color);
	}
	
	public void showAbility() {
		System.out.println("Ư��: " + ability);
	}
	
	public void hearSound() {
		System.out.println("�Ҹ�: " + sound);
	}
}
