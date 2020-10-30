package main.client;

import java.io.IOException;
import java.io.InputStream;
import java.io.ObjectInputStream;
import java.io.ObjectOutputStream;
import java.io.OutputStream;
import java.net.Socket;

import main.packets.Packet;

public class Connect {
	final String address;
	final int port;
	private Socket s1 = null;
	private ObjectInputStream inStream;
	private ObjectOutputStream outStream;
	private Thread sendingThread;
	
	
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
	
	public void setObjectInStream() throws IOException {
		inStream = new ObjectInputStream(getIS());
	}
	
	public void setObjectOutStream() throws IOException {
		outStream = new ObjectOutputStream(getOS());
	}
	
	public void close() throws IOException {
		s1.close();
	}
	
	public Packet receive() throws ClassNotFoundException, IOException {
		Packet recPack = (Packet)inStream.readObject();
		return recPack;
	}
	
	public void send(Packet packet) throws IOException {
		sendingThread = new Thread("SendingThread") {
			public void run() {
				try {
					outStream.writeObject(packet);
				} catch (IOException e) {
					e.printStackTrace();
				}
			};
		};
		sendingThread.start();
	}
}
