package Practice1113;

public class Test05Television implements Test05RemoteControl {
	boolean onOff = false;
	public void turnOn() {
		onOff = true;
	}
	public void turnOff() {
		onOff = false;
	}
}
