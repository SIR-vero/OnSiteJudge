package test;

import java.io.IOException;

import main.client.Connect;
import main.packets.ServerParticipantPacket;

public class TestClient {

	private Connect con;
	private String id, pass;
	
	public TestClient(Connect con, String id, String pass) {
		this.con = con;
		this.id = id;
		this.pass = pass;
		try {
			con.setObjectOutStream();
			con.setObjectInStream();
		} catch (IOException e) {
			e.printStackTrace();
		}
		
		ServerParticipantPacket sp = new ServerParticipantPacket(114);
		sp.setLoginID(id);
		sp.setPassword(pass);
		
			try {
				Thread.sleep(500);
			} catch (InterruptedException e1) {
				e1.printStackTrace();
			}
			try {
				con.send(sp);
			} catch (IOException e) {
				e.printStackTrace();
			}
	}
	
	
}
