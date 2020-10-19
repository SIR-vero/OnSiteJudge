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
import java.awt.event.ActionEvent;

public class Connect extends JFrame {

	private static final long serialVersionUID = 1L;
	private JPanel contentPane;
	private JTextField textipAddress;
	private JTextField textPort;

	public Connect() {
		try {
			UIManager.setLookAndFeel(UIManager.getSystemLookAndFeelClassName());
		} catch (Exception e1) {
			e1.printStackTrace();
		}
		
		setResizable(false);
		setTitle("Connect");
		setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
		setSize(300, 380);
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
		portDescp.setBounds(134, 180, 27, 14);
		contentPane.add(portDescp);
		
		textPort = new JTextField();
		textPort.setColumns(10);
		textPort.setBounds(70, 205, 156, 27);
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
		btnConnect.setBounds(102, 291, 91, 23);
		contentPane.add(btnConnect);
		
		JLabel ipEg = new JLabel("(eg. 192.168.3.1)");
		ipEg.setBounds(102, 95, 91, 14);
		contentPane.add(ipEg);
		
		JLabel lblNewLabel = new JLabel("(eg. 8129)");
		lblNewLabel.setBounds(122, 245, 52, 14);
		contentPane.add(lblNewLabel);
	}
	
	private void connect(String address, int port){
		System.out.println(address + ", " + port);
	}
	
	public static void main(String[] args) {
		EventQueue.invokeLater(new Runnable() {
			public void run() {
				try {
					Connect frame = new Connect();
					frame.setVisible(true);
				} catch (Exception e) {
					e.printStackTrace();
				}
			}
		});
	}
}
