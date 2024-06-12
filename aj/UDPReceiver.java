import java.net.*;
import java.util.Arrays;

public class UDPReceiver {
    public static void main(String[] args) {
        try {
            DatagramSocket ds = new DatagramSocket(6666);
            byte buffer[] = new byte[1024];
            DatagramPacket dp = new DatagramPacket(buffer, 1024);
            ds.receive(dp);
            String received = new String(dp.getData(), 0, dp.getLength());
            
            // Convert the received string of numbers into an array of integers
            String[] numberStrings = received.split(",");
            int[] numbers = new int[numberStrings.length];
            for (int i = 0; i < numberStrings.length; i++) {
                numbers[i] = Integer.parseInt(numberStrings[i].trim());
            }
            
            // Sort the array of numbers
            Arrays.sort(numbers);
            
            // Print the sorted numbers
            System.out.print("Sorted numbers: ");
            for (int number : numbers) {
                System.out.print(number + " ");
            }
            System.out.println();
            
            ds.close();
        } catch (Exception ex) {
            ex.printStackTrace();
        }
    }
}
