package Practice1113;

public class Test06AI_Phone implements Test06AI_Interface, Test06PhoneInterface {
	// PhoneInterface의 모든 메소드 구현
	public void sendCall() {
		System.out.println("삘릴릴렐렐렐레");
	}
	public void receiveCall() {
		System.out.println("띨릴릴릴릴렐레");
	}
	// AI_Interface의 모든 메소드 구현
	public void recognizeSpeech() {
		System.out.println("카카오톡");
	}
	public void synthesizeSpeech() {
		System.out.println("카톡왔숑");
	}
	// 추가적으로 다른 메소드를 작성 가능
	public void touch() {
		System.out.println("뾱");
	}
}
