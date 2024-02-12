import java.net.DatagramPacket;
import java.net.DatagramSocket;

public class udpreceiver {
    public static void main(String[] args) {
        try {
            DatagramSocket ds = new DatagramSocket(6666);
            byte buffer[] = new byte[1024];
            DatagramPacket dp = new DatagramPacket(buffer, 1024);
            ds.receive(dp);
            String str = new String(dp.getData(), 0, dp.getLength());
            System.out.println("Receive: " + str);
            System.out.println("successfully!!");
            ds.close();
        } catch (Exception ex) {
            ex.printStackTrace();
        }
    }
}
