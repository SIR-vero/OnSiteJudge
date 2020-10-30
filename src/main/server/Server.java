package main.server;

import java.io.IOException;
import java.io.ObjectInputStream;
import java.io.ObjectOutputStream;
import java.net.ServerSocket;
import java.net.Socket;

import main.packets.Packet;
import main.packets.ServerParticipantPacket;

public class Server implements Runnable {

	private int port;
	private ServerSocket serverSocket;
	private boolean running = false;
	
	private Thread run, loginClients, connectClients;
	
	public Server(int port) {
		this.port = port;
		try {
			serverSocket = new ServerSocket(port);
		} catch (IOException e) {
			e.printStackTrace();
			return;
		}
		run = new Thread(this, "Server");
		run.start();
	}

	@Override
	public void run() {
		running = true;
		System.out.println("Server started at port " + port);
		acceptConnections();
	}
	
	private void acceptConnections() {
		connectClients = new Thread("SocketAccept") {
			public void run() {
				Socket s;
				while(running) {
					try {
						s = serverSocket.accept();
						//send a message for login credentials
						authorizeConnect(s);
					} catch (IOException e) {
						e.printStackTrace();
					}
				}
			}
		};
		connectClients.start();
	}
	
	private void authorizeConnect(Socket s) {
		/**
		 * Kill the loginClients thread if no credential is sent from the Client Socket.(say kill after 5 min.)
		 */
		
		loginClients = new Thread("AuthorizeClient") {
			public void run() {
				ObjectInputStream inStream;
				ObjectOutputStream outStream;
				Packet recPack;
				try {
					outStream = new ObjectOutputStream(s.getOutputStream());
					inStream = new ObjectInputStream(s.getInputStream());
					recPack = (Packet)inStream.readObject();
					System.out.println("received packet. " + recPack.getTypeofPacket());
					if (recPack.getTypeofPacket() == 114) {
						ServerParticipantPacket spPacket = (ServerParticipantPacket)recPack;
						System.out.println("in if " + spPacket.getLoginID() + " " + spPacket.getPassword());
						
						//Authorize Client using recPack. Check for existence of the ID and password in the DB or files
						//Demo Code
						
							if (spPacket.getLoginID().equals("vero") && spPacket.getPassword().equals("vero")){
								System.out.println(spPacket.getLoginID() + " Connected from " + s.getInetAddress().toString());
							}
							else {
								System.out.println("Credentials Wrong ! ");
							}
					}
					else {
						System.out.println("in else " + recPack.getTypeofPacket());
					}
					
				}catch (ClassNotFoundException | IOException e) {
					e.printStackTrace();
				}
			}
		};
		loginClients.start();
	}
	
}
