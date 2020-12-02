package main.server;

import java.io.EOFException;
import java.io.FileInputStream;
import java.io.FileNotFoundException;
import java.io.IOException;
import java.io.ObjectInputStream;
import java.io.ObjectOutputStream;
import java.net.ServerSocket;
import java.net.Socket;
import java.util.ArrayList;

import main.client.Client;
import main.packets.Packet;
import main.packets.ServerParticipantPacket;

public class Server implements Runnable {
	
	private ArrayList<Client> adminArrayList = new ArrayList<Client>();
	private ArrayList<Client> judgeArrayList = new ArrayList<Client>();
	private ArrayList<Client> participantArrayList = new ArrayList<Client>();
	

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
		loadStateFromDisk();
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
					if (recPack.getTypeofPacket() == 114) {
						ServerParticipantPacket spPacket = (ServerParticipantPacket)recPack;
						
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
					}
					
				}catch (ClassNotFoundException | IOException e) {
					e.printStackTrace();
				}
			}
		};
		loginClients.start();
	}
	
	/**
	 * Load any previous state or data at start of server (Synchronous)
	 */
	void loadStateFromDisk() {
		//loading login credentials
		FileInputStream loginFileInputStream = null;
		try {
			loginFileInputStream = new FileInputStream("./data/loginData.bin");
		} catch (FileNotFoundException e) {
			e.printStackTrace();
		}
		ObjectInputStream loginFileObjInputStream = null;
		try {
			loginFileObjInputStream = new ObjectInputStream(loginFileInputStream);
		} catch (IOException e) {
			e.printStackTrace();
		}
		
		Client c = null;
		while(true) {
			try {
				c = (Client)loginFileObjInputStream.readObject();
			} catch (ClassNotFoundException e) {
				e.printStackTrace();
				break;
			} catch (EOFException e) {
				break;
			} catch (IOException e) {
				e.printStackTrace();
				break;
			}
			if (c.getType() == 1) {			//admin
				adminArrayList.add(c);
			}
			else if (c.getType() == 2) {	//judge
				judgeArrayList.add(c);
			}  
			else if (c.getType() == 3) {	//participants
				participantArrayList.add(c);
			}
		}
	}
}
