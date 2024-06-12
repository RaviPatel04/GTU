import java.net.*;
import java.io.*;

public class pr1tcpserver {
    public static void main(String[] args) {
        try {
            ServerSocket ss = new ServerSocket(888);
            Socket s = ss.accept();
            OutputStream obj = s.getOutputStream();
            PrintStream ps = new PrintStream(obj);
            ps.println("Message from server");
            ss.close(); 
            s.close(); 
            ps.close(); 
        } catch (IOException ex) {
            ex.printStackTrace();
        }
    }
}
