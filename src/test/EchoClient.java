package test;

import java.io.*;
import java.net.Socket;

import main.client.Connect;

public class EchoClient {
	private String line = null;
	private DataInputStream br = null;
	private DataInputStream is = null;
	private PrintWriter os = null;
	
	public EchoClient(Connect con) {
		
		br = new DataInputStream(System.in);
		try {
			is = new DataInputStream(con.getIS());
			os = new PrintWriter(con.getOS());
		} catch (IOException e) {
			e.printStackTrace();
		}
		System.out.println("Enter data ....");
		String response = "";
		try
		{
			line = br.readLine();
			while(line.compareTo("QUIT") != 0)
			{
				os.println(line);
				os.flush();
				response = is.readLine();
				System.out.println("Server response :- " + response);
				line = br.readLine();
			}
			is.close();
			os.close();
			br.close();
			con.close();
			System.out.println("Connection Closed ....");
		}
		catch(Exception e)
		{System.out.println("Error......");}
	}
}
