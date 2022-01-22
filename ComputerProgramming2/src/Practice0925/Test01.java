package Practice0925;

public class Test01 {

	public static void main(String[] args) {
		// TODO Auto-generated method stub
		short a = (short)0x55ff;	// 0101 0101 1111 1111
		short b = (short)0x00ff;	// 0000 0000 1111 1111
		
		System.out.printf("%04x\n", (short)(~a) );
		
		byte c = 20;	// 0x14 (0001 0100)
		byte d = -8;	// 0xf8 (1111 1000)
		
		// 연산 결과는 int형임, 4자리 출력 시 앞 부분의 0은 생략됨
		System.out.println(c << 2);	// 2비트 왼쪽 시프트
		System.out.println(c >> 2);	// 2비트 오른쪽 시프트, 0 삽입
		System.out.println(d >> 2);	// 2비트 오른쪽 시프트, 1 삽입
		System.out.printf("%x\n", (d >>> 2) );	// 2비트 오른쪽 시프트, 0 삽입
		
		System.out.printf("%04x\n", (a & b) );
		System.out.printf("%04x\n", (a | b) );
		System.out.printf("%04x\n", (a ^ b) );
	}

}
