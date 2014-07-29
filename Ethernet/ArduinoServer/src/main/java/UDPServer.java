import java.net.DatagramPacket;
import java.net.DatagramSocket;
import java.net.InetAddress;
import java.util.Scanner;
import java.util.logging.Level;
import java.util.logging.Logger;


public class UDPServer {
	
	private final static Logger logger = Logger.getLogger(TCPServer.class.getName());
	private final static int SERVER_PORT = 3000;
	
	public static void main(String[] args) {
		try {
			requestHandler();
		} catch (Exception e) {
			logger.log(Level.SEVERE, "Error : "+e);
		}
	}

	private static void requestHandler() {
		
		DatagramSocket serverSocket = null;
		try {
			logger.log(Level.INFO, "WebServer Socket Created");
			serverSocket = new DatagramSocket(SERVER_PORT);

			byte[] receiveData = new byte[1024];
			byte[] sendData = new byte[1024];
			
			boolean isOperation = true;
			
			Scanner scanner = new Scanner(System.in);
			while(isOperation) {
				DatagramPacket receivePacket = new DatagramPacket(receiveData, receiveData.length);
				serverSocket.receive(receivePacket);
				
				String sentence = new String( receivePacket.getData());
				logger.log(Level.INFO, "RECEIVED: " + sentence);
				InetAddress IPAddress = receivePacket.getAddress();
				int port = receivePacket.getPort(); 
				
				String capitalizedSentence = sentence.toUpperCase(); 
				sendData = capitalizedSentence.getBytes();

				if (sendData.equals("exit")) {
					isOperation = false;
				}
				
				DatagramPacket sendPacket = new DatagramPacket(sendData, sendData.length, IPAddress, port);
				
				serverSocket.send(sendPacket);
			}
			
			scanner.close();
		} catch (Exception e) {
			e.printStackTrace();
		} finally {
			serverSocket.close();
		}
	}
}