package Practice1113;

public class Test06AI_Phone implements Test06AI_Interface, Test06PhoneInterface {
	// PhoneInterface�� ��� �޼ҵ� ����
	public void sendCall() {
		System.out.println("�⸱����������");
	}
	public void receiveCall() {
		System.out.println("�����������");
	}
	// AI_Interface�� ��� �޼ҵ� ����
	public void recognizeSpeech() {
		System.out.println("īī����");
	}
	public void synthesizeSpeech() {
		System.out.println("ī��Լ�");
	}
	// �߰������� �ٸ� �޼ҵ带 �ۼ� ����
	public void touch() {
		System.out.println("�s");
	}
}
