package test;

import java.io.EOFException;
import java.io.FileInputStream;
import java.io.FileNotFoundException;
import java.io.IOException;
import java.io.ObjectInputStream;

import main.client.Client;

public class ReadObjFromFile {

	public static void main(String[] args) {
		FileInputStream fi = null;
		try {
			fi = new FileInputStream("./data/data.bin");
		} catch (FileNotFoundException e) {
			e.printStackTrace();
		}
		ObjectInputStream ob = null;
		try {
			ob = new ObjectInputStream(fi);
		} catch (IOException e) {
			e.printStackTrace();
		}
		
		Client c = null;
		while(true) {
			try {
				c = (Client)ob.readObject();
			} catch (ClassNotFoundException e) {
				// TODO Auto-generated catch block
				e.printStackTrace();
				break;
			} catch (EOFException e) {
				break;
			} catch (IOException e) {
				e.printStackTrace();
				break;
			}
			System.out.println(c.getLoginID() + " " + c.getPassword());
		}
	}
}
