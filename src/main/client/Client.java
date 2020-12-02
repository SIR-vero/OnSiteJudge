package main.client;

import java.io.Serializable;

public class Client implements Serializable{

	private static final long serialVersionUID = 1L;
	private int type;	//1 -> admin 2 -> judge 3 -> participant
	private String loginID;
	private String password;
	
	public Client(int type, String loginID, String password) {
		this.setType(type);
		this.setLoginID(loginID);
		this.setPassword(password);
	}

	public String getLoginID() {
		return loginID;
	}

	public void setLoginID(String loginID) {
		this.loginID = loginID;
	}

	public int getType() {
		return type;
	}

	public void setType(int type) {
		this.type = type;
	}

	public String getPassword() {
		return password;
	}

	public void setPassword(String password) {
		this.password = password;
	}
}
