import java.net.*;

public class pr1udpsender {
    public static void main(String[] args) {

        try {
            DatagramSocket ds = new DatagramSocket();
            String str = "Message from Sender";
            InetAddress ip = InetAddress.getByName("localhost");
            DatagramPacket dp = new DatagramPacket(str.getBytes(), str.length(), ip, 6666);
            ds.send(dp);
            ds.close();
        } catch (Exception ex) {
            ex.printStackTrace();
        }

    }
}
