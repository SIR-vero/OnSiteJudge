package test;

import java.io.FileNotFoundException;
import java.io.FileOutputStream;
import java.io.IOException;
import java.io.ObjectOutputStream;
import java.util.Scanner;

import main.client.Client;

public class WriteClientToFile {

	public static void main(String[] args) {
		Scanner sc = new Scanner(System.in);
		int x = sc.nextInt();
		System.out.println(x);
		FileOutputStream fi = null;
		try {
			fi = new FileOutputStream("./data/loginData.bin", true);
		} catch (FileNotFoundException e) {
			e.printStackTrace();
		}
		ObjectOutputStream ob = null;
		try {
			ob = new ObjectOutputStream(fi);
		} catch (IOException e) {
			e.printStackTrace();
		}
		for (int i = 0; i < x; i++) {
			int t = sc.nextInt();
			String s = sc.next();
			String p = sc.next();
			Client c = new Client(t, s, p);
			try {
				ob.writeObject(c);
			} catch (IOException e) {
				e.printStackTrace();
			}
			System.out.println("obj written successfully ");
		}
		try {
			ob.close();
		} catch (IOException e) {
			e.printStackTrace();
		}
		
	}
}
