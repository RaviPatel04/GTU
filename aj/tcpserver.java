import java.net.*;
import java.io.*;

public class tcpserver {
    public static void main(String[] args) {
        try {
            ServerSocket ss = new ServerSocket(888);
            Socket s = ss.accept();
            OutputStream obj = s.getOutputStream();
            PrintStream ps = new PrintStream(obj);
            ps.println("Hello from tcp server!!");
            ss.close(); // close ServerSocket
            s.close(); // close Socket
            ps.close(); // close Printstream
        } catch (IOException ex) {
            ex.printStackTrace();
        }
    }
}