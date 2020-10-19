package main.client;

import java.io.IOException;
import java.io.InputStream;
import java.io.OutputStream;
import java.net.Socket;

public class Connect {
	final String address;
	final int port;
	private Socket s1 = null;
	
	public Connect(String address, int port) {
		this.address = address;
		this.port = port;
	}
	
	public void openConnection() throws IOException {
		s1 = new Socket(address, port);
	}
	
	public InputStream getIS() throws IOException {
		return s1.getInputStream();
	}
	
	public OutputStream getOS() throws IOException {
		return s1.getOutputStream();
	}
	
	public void close() throws IOException {
		s1.close();
	}
	
}
