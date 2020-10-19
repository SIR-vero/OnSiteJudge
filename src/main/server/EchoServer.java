package main.server;

import java.net.*;
import java.io.*;

public class EchoServer {

	public static void main(String[] args) throws Exception
	{
		Socket s = null;
		ServerSocket ss2 = null;
		System.out.println("Server listening.....");
		ss2 = new ServerSocket(4446);
		while(true)
		{
			try
			{
				s = ss2.accept();
				System.out.println("Connection Established....");
				ServerThread st = new ServerThread(s);
				st.start();
			}
			catch(Exception e)
			{
				System.out.println("Connection Error....");
			}
		}
	}
}

class ServerThread extends Thread
{
	String line = "";
	DataInputStream is = null;
	DataOutputStream br = null;
	PrintWriter os = null;
	Socket s1 = null;
	public ServerThread(Socket s)
	{
		s1 = s;
	}
	public void run() 
	{
		try
		{
			is = new DataInputStream(s1.getInputStream());
			os = new PrintWriter(s1.getOutputStream());
			line = is.readLine();
			while(line.compareTo("QUIT") != 0)
			{
				os.println(line);
				os.flush();
				System.out.println("Response of Client :- " + line);
				line = is.readLine();
			}
			is.close();
			os.close();
			s1.close();
		}
		catch(Exception e)
		{}
	}
}
