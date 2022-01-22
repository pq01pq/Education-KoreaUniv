package Assignment1127;
import java.util.HashMap;
import java.util.Scanner;

class Gen<K, V> {
	K name;
	V score;
	HashMap<K, V> hash;
	
	public Gen() {
		this.name = null;	this.score = null;
		hash = new HashMap<K, V>();
	}
	
	void setItem(K key, V value) {
		this.name = key;	this.score = value;
		hash.put(this.name, this.score);
	}
	
	V findItem(K key) {
		return hash.get(key);
	}
}

public class Assign {
	static void init(String[] key, int[] value, Gen gen) {
		for(int i = 0; i < key.length; i++) {
			gen.setItem(key[i], Integer.valueOf(value[i]));
		}
	}
	
	public static void main(String[] args)
	{
		// TODO Auto-generated method stub
		Scanner scan = new Scanner(System.in);
		String[] name = {"유재석", "강호동", "이경규"};
		int[] score = {70, 90, 80};
		Gen<String, Integer> gen = new Gen<String, Integer>();
		init(name, score, gen);
		
		String s;
		while(true) {
			System.out.print("이름> ");	s = scan.next();
			if(s.equals("quit"))
				break;
			System.out.println(gen.findItem(s));
			System.out.println();
		}
		scan.close();
	}
}
