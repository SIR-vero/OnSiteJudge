package main.packets;

import java.io.Serializable;

public class ServerParticipantPacket extends Packet implements Serializable {

	private static final long serialVersionUID = 1L;
	private String loginID;			//login ID of participant 
	private String password;		//password of participant (not encrypted)
	private boolean boolResponse;	//a boolean response (dependent on type of packet)
	private String code;			//Submitted code of the participant
	private int verdict;			//Verdicted received from the server
	private int language;			//Language of the code
	
	public ServerParticipantPacket(int typeofPacket) {
		super(typeofPacket);
	}
	
	//Getters
	
	public String getLoginID() {
		return loginID;
	}

	public String getPassword() {
		return password;
	}

	public String getCode() {
		return code;
	}

	public boolean getResponse() {
		return boolResponse;
	}
	
	public int getVerdict() {
		return verdict;
	}
	
	public int getLanguage() {
		return language;
	}
	
	//Setters
	
	public void setLoginID(String loginID) {
		this.loginID = loginID;
	}

	public void setPassword(String password) {
		this.password = password;
	}

	public void setCode(String code) {
		this.code = code;
	}

	public void setResponse(boolean res) {
		this.boolResponse = res;
	}
	
	public void setVerdict(int ver) {
		this.verdict = ver;
	}
	
	public void setLanguage(int lan) {
		this.language = lan;
	}
	
	
}
