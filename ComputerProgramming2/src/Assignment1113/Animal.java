package Assignment1113;

class Animal implements AnimalTrait {
	String color;
	String ability;
	String sound;
	
	public Animal() {
		color = "Transparent";
		ability = "아무것도 안함";
		sound = "아무 소리도 안냄";
	}
	
	public void showColor() {
		System.out.println("색상: " + color);
	}
	
	public void showAbility() {
		System.out.println("특기: " + ability);
	}
	
	public void hearSound() {
		System.out.println("소리: " + sound);
	}
}
