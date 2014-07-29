import java.io.BufferedReader;
import java.io.DataOutputStream;
import java.io.IOException;
import java.io.InputStream;
import java.io.InputStreamReader;
import java.io.OutputStream;
import java.net.ServerSocket;
import java.net.Socket;
import java.util.Scanner;
import java.util.logging.Level;
import java.util.logging.Logger;

public class TCPServer {
	
	private final static Logger logger = Logger.getLogger(TCPServer.class.getName());
	private final static int SERVER_PORT = 3000;
	//private final static int MAX_CONNECTION = 100;
	//private final static String SERVER_IP = "192.168.0.2";
	
	public static void main(String[] args) {
        try {
        	requestHandle();
		} catch (Exception e) {
			logger.log(Level.SEVERE, "Error : "+e);
		}
	}

	private static void requestHandle() {
		Socket socket = null;
		InputStream is = null;
    	OutputStream os = null;
    	InputStreamReader isr = null; 
    	BufferedReader br = null;
    	DataOutputStream dos = null;
    	Scanner scanner = null;
		try {
        	
        	//설정된 IP bind를 위해 inerAddress를 선언
        	//InetAddress address = InetAddress.getByName(SERVER_IP);
        	
        	// 서버소켓을 생성한다.
			//ServerSocket listenSocket = new ServerSocket(SERVER_PORT, MAX_CONNECTION, address);
        	ServerSocket listenSocket = new ServerSocket(SERVER_PORT);
        	
			logger.log(Level.INFO, "WebServer Socket Created");
			
	        // 클라이언트가 연결될때까지 대기한다.
	        while ((socket = listenSocket.accept()) != null) {
	        	logger.log(Level.INFO, "WebServer Socket Connected "+ socket.getInetAddress());
	        	
	        	is = socket.getInputStream();
	        	os = socket.getOutputStream();
	        	
	        	isr = new InputStreamReader(is); 
	        	br = new BufferedReader(isr);
	        	
	        	dos = new DataOutputStream(os);
	        	dos.writeBytes("Hello Arduino!!");
	        	
	        	StringBuffer sb = new StringBuffer();
	        	String readData;
	        	
	        	boolean isOperation = true;
	        	
	        	System.out.print("\nInput> ");
	        	scanner = new Scanner(System.in);
	        	String inputData;
	        	while (isOperation) {
	        		
	        		
	        		inputData = scanner.nextLine();
	        		
	        		if ( inputData.equalsIgnoreCase("exit"))
	        			isOperation = false;
	        		else
	        			dos.writeBytes(inputData);
	        		
	        		while((readData=br.readLine())!=null){
		        		sb.append(readData);
		        		readData = br.readLine();
		        		
		        		if (readData.equalsIgnoreCase("*****")) {
		        			sb = new StringBuffer();
		        			break;
		        		}
		        	}
		        	
		        	logger.log(Level.INFO, "Receive Data : "+sb.toString());
				}
	        	
	        	scanner.close();
	        }
			
	        if(listenSocket !=null) {
	        	logger.log(Level.INFO, "Socket close");
	        	listenSocket.close();
	        }
		} catch (IOException e) {
			logger.log(Level.SEVERE, "Create WebServer Error : " + e);
		} finally {
			try {
				if(scanner!=null) scanner.close();
				if(dos!=null) dos.close();
				if(br!=null) br.close();
				if(isr!=null) isr.close(); 
				if(os!=null) os.close();
				if(is!=null) is.close();
				if (socket!=null) socket.close();
			} catch (IOException e) {
				e.printStackTrace();
			}
		}
	}
}
