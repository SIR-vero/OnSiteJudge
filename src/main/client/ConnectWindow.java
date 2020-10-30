package main.client;

import java.awt.EventQueue;


import javax.swing.JFrame;
import javax.swing.JPanel;
import javax.swing.border.EmptyBorder;
import javax.swing.JTextField;
import javax.swing.UIManager;
import javax.swing.JLabel;
import javax.swing.JButton;
import java.awt.event.ActionListener;
import java.io.IOException;
import java.net.Socket;
import java.awt.event.ActionEvent;


public class ConnectWindow extends JFrame {

	private static final long serialVersionUID = 1L;
	private JPanel contentPane;
	private JTextField textipAddress;
	private JTextField textPort;
	private Socket s1;
	private JTextField password;
	private JTextField loginID;

	public ConnectWindow() {
		try {
			UIManager.setLookAndFeel(UIManager.getSystemLookAndFeelClassName());
		} catch (Exception e1) {
			e1.printStackTrace();
		}
		
		setResizable(false);
		setTitle("ParticipantLogin");
		setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
		setSize(500, 500);
		setLocationRelativeTo(null);
		contentPane = new JPanel();
		contentPane.setBorder(new EmptyBorder(5, 5, 5, 5));
		setContentPane(contentPane);
		contentPane.setLayout(null);
		
		textipAddress = new JTextField();
		textipAddress.setBounds(70, 57, 156, 27);
		contentPane.add(textipAddress);
		textipAddress.setColumns(10);
		
		JLabel ipAddressDescp = new JLabel("Server IP address");
		ipAddressDescp.setBounds(97, 32, 101, 14);
		contentPane.add(ipAddressDescp);
		
		JLabel portDescp = new JLabel("Port");
		portDescp.setBounds(338, 32, 27, 14);
		contentPane.add(portDescp);
		
		textPort = new JTextField();
		textPort.setColumns(10);
		textPort.setBounds(280, 57, 156, 27);
		contentPane.add(textPort);
		
		JButton btnConnect = new JButton("Connect");
		btnConnect.addActionListener(new ActionListener() {
			public void actionPerformed(ActionEvent e) {
				/**
				 * action to be performed when Connect is pressed.
				 * Validate IP and port then Attempt to connect.
				 */
				
				connect(textipAddress.getText(), Integer.parseInt(textPort.getText()));
			}
		});
		btnConnect.setBounds(208, 404, 91, 23);
		contentPane.add(btnConnect);
		
		JLabel ipEg = new JLabel("(eg. 192.168.3.1)");
		ipEg.setBounds(102, 95, 91, 14);
		contentPane.add(ipEg);
		
		JLabel lblNewLabel = new JLabel("(eg. 8129)");
		lblNewLabel.setBounds(323, 95, 52, 14);
		contentPane.add(lblNewLabel);
		
		JLabel lblPassword = new JLabel("Password");
		lblPassword.setBounds(338, 249, 59, 14);
		contentPane.add(lblPassword);
		
		password = new JTextField();
		password.setColumns(10);
		password.setBounds(280, 274, 156, 27);
		contentPane.add(password);
		
		JLabel lblLginid = new JLabel("LginID");
		lblLginid.setBounds(125, 249, 38, 14);
		contentPane.add(lblLginid);
		
		loginID = new JTextField();
		loginID.setColumns(10);
		loginID.setBounds(70, 274, 156, 27);
		contentPane.add(loginID);
	}
	
	private void connect(String address, int port){
		System.out.println(address + ", " + port);
		
		Connect con = new Connect(address, port);
		try {
			con.openConnection();
		} catch (IOException e) {
			e.printStackTrace();
			/**
			 * could not connect. Not handled yet.
			 */
		}
		dispose();
		new EchoClient(con);
	}
	
	public static void main(String[] args) {
		EventQueue.invokeLater(new Runnable() {
			public void run() {
				try {
					ConnectWindow frame = new ConnectWindow();
					frame.setVisible(true);
				} catch (Exception e) {
					e.printStackTrace();
				}
			}
		});
	}
}
