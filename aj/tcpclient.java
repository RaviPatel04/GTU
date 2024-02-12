import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStream;
import java.io.InputStreamReader;
import java.net.Socket;

public class tcpclient {
    public static void main(String[] args) {
        try {
            Socket s = new Socket("localhost", 888);
            InputStream inStr = s.getInputStream();
            BufferedReader br = new BufferedReader(new InputStreamReader(inStr));
            String receivedMessage = br.readLine();
            System.out.println("Message: " + receivedMessage);
            System.out.println("Successfully!!");
            br.close(); // close BufferReader
            s.close(); // close Socket
        } catch (IOException ex) {
            ex.printStackTrace();
        }
    }
}