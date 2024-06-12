import java.net.*;
import java.util.Scanner;

public class UDPSender {
    public static void main(String[] args) {
        try {
            DatagramSocket ds = new DatagramSocket();
            Scanner scanner = new Scanner(System.in);
            
            // Prompt user to enter numbers
            System.out.println("Enter numbers separated by commas:");
            String input = scanner.nextLine();
            
            InetAddress ip = InetAddress.getByName("localhost");
            DatagramPacket dp = new DatagramPacket(input.getBytes(), input.length(), ip, 6666);
            ds.send(dp);
            
            ds.close();
            scanner.close();
        } catch (Exception ex) {
            ex.printStackTrace();
        }
    }
}
