package main.server;

public class ServerCLI {
	
	private int port;
	private Server server;
	
	public ServerCLI(int port) {
		this.setPort(port);
		server = new Server(port);
	}

	public static void main(String[] args) {
		int port;
		if (args.length != 1) {
			System.out.println("Usage: java ServerCLI [port]");
			return;
		}
		port = Integer.parseInt(args[0]);
		new ServerCLI(port);
	}

	public int getPort() {
		return port;
	}

	public void setPort(int port) {
		this.port = port;
	}
}
