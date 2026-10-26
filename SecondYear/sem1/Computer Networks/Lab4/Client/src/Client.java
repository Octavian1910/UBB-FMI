
import java.net.*;
import java.io.*;
import java.nio.charset.StandardCharsets;

public class Client {
    public static void main(String args[]) throws Exception {
        Socket c = new Socket("127.0.0.1", 1234);

        BufferedReader reader =
                new BufferedReader(new InputStreamReader(System.in));

        DataInputStream socketIn =
                new DataInputStream(c.getInputStream());

        DataOutputStream socketOut =
                new DataOutputStream(c.getOutputStream());

        System.out.print("sir = ");
        String sir = reader.readLine();

        byte[] date = sir.getBytes(StandardCharsets.US_ASCII);

        System.out.print("i = ");
        int i = Integer.parseInt(reader.readLine());

        System.out.print("l = ");
        int l = Integer.parseInt(reader.readLine());

        if (i < 0 || l < 0 || i > date.length || l > date.length - i) {
            System.out.println("Subsir invalid.");
            c.close();
            return;
        }

        // Trimitem sirul si terminatorul '\0'
        socketOut.write(date);
        socketOut.writeByte(0);

        // Trimitem i si l pe cate 2 octeti
        socketOut.writeShort(i);
        socketOut.writeShort(l);
        socketOut.flush();

        // Citim exact l octeti
        byte[] subsir = new byte[l];
        socketIn.readFully(subsir);

        System.out.println("Subsirul este: " +
                new String(subsir, StandardCharsets.US_ASCII));

        reader.close();
        c.close();
    }
}
