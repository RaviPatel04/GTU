import java.net.*;

public class pr1udpreceiver {
    public static void main(String[] args) {

        try {
            DatagramSocket ds = new DatagramSocket(6666);
            byte buffer[] = new byte[1024];
            DatagramPacket dp = new DatagramPacket(buffer, 1024);
            ds.receive(dp);
            String str = new String(dp.getData(), 0, dp.getLength());
            System.out.println("Receive: " + str);
            ds.close();
        } catch (Exception ex) {
            ex.printStackTrace();
        }
    }

}
