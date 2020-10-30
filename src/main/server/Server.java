package main.server;

import java.io.IOException;
import java.net.ServerSocket;

public class Server implements Runnable {

	private int port;
	private ServerSocket serverSocket;
	private boolean running = false;
	
	private Thread run;
	
	public Server(int port) {
		this.port = port;
		try {
			serverSocket = new ServerSocket(port);
		} catch (IOException e) {
			e.printStackTrace();
		}
		run = new Thread(this, "Server");
		run.start();
	}

	@Override
	public void run() {
		running = true;
		
	}
	
}
