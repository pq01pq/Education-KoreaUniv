package P;

import Q.Test02Child;

class Test02 {

	public static void main(String[] args) {
		// TODO Auto-generated method stub
		Test02Parent P = new Test02Parent();
		//int a = P.a;
		int b = P.b;
		int c = P.c;
		int d = P.d;
		
		Test02Child C = new Test02Child(1,2,3,4);
		//int e = C.a;
		int f = C.b;
		//int g = C.c;
		int h = C.d;
	}

}
