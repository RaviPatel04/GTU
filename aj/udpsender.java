import java.net.DatagramPacket;
import java.net.DatagramSocket;
import java.net.InetAddress;

public class udpsender {
    public static void main(String[] args) {
        try {
            DatagramSocket ds = new DatagramSocket();
            String str = "Message from udp Sender";
            InetAddress ip = InetAddress.getByName("localhost");
            DatagramPacket dp = new DatagramPacket(str.getBytes(),
                    str.length(), ip, 6666);
            ds.send(dp);
            ds.close();
        } catch (Exception ex) {
            ex.printStackTrace();
        }
    }
}
