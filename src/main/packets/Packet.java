package main.packets;

import java.io.Serializable;

public class Packet implements Serializable {

	private static final long serialVersionUID = 1L;
	/**
	 * ~~~~~~~~~~~~~~~~~~~~~typeofSender and typeofReceiver~~~~~~~~~~~~~~~~~~~~~~~~~~
	 * 	1 -> Server
	 * 	2 -> Admin Panel
	 * 	3 -> Judge Panel
	 * 	4 -> Participant
	 * 
	 * ~~~~~~~~~~~~~~~~~~~~~typeofPacket~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
	 * 								type|receiver|sender
	 * 	Participant to server:-
	 * 		114 ->	Login Request
	 * 		214 ->	Submit Code
	 * 	Server to Participant :-
	 * 		141 ->	Login Approve
	 * 		241 ->	
	 */
	
	private int typeofPacket;
	
	public Packet(int typeofPacket){
		this.setTypeofPacket(typeofPacket);
	}

	public int getTypeofPacket() {
		return typeofPacket;
	}

	public void setTypeofPacket(int typeofPacket) {
		this.typeofPacket = typeofPacket;
	}
	
}
