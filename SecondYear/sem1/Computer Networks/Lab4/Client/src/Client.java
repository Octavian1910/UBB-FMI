import java.net.*;
import java.io.*;
import java.nio.charset.StandardCharsets;

// java Client 127.0.0.1 1234
public class Client {
    public static void main(String args[]) throws Exception {
        if (args.length < 2) {
            System.out.println("Utilizare: java Client <adresa_IP> <port>");
            return;
        }

        String ip = args[0];
        int port = Integer.parseInt(args[1]);

        //conectare la server
        Socket c = new Socket(ip, port); //creeaza un socket TCP si se si conecteaza la el

        BufferedReader reader = new BufferedReader(new InputStreamReader(System.in));
        DataInputStream socketIn = new DataInputStream(c.getInputStream());
        DataOutputStream socketOut = new DataOutputStream(c.getOutputStream());

        System.out.print("Dati sirul: ");
        String sir = reader.readLine();

        System.out.print("Dati i: ");
        int i = Integer.parseInt(reader.readLine());

        System.out.print("Dati l: ");
        int l = Integer.parseInt(reader.readLine());

        byte[] date = sir.getBytes(StandardCharsets.US_ASCII); //transformar sirul in octeti , reteaua trimite octeti nu obiecte string
        socketOut.write(date);
        socketOut.writeByte(0); //null terminator

        socketOut.writeShort(i);
        socketOut.writeShort(l);
        socketOut.flush(); //trimite datele

        ByteArrayOutputStream bufferRaspuns = new ByteArrayOutputStream();
        byte ch;
        while ((ch = socketIn.readByte()) != 0) {
            bufferRaspuns.write(ch);
        }

        String subsir = bufferRaspuns.toString(StandardCharsets.US_ASCII); // convertim din ASCII intr un obiect String
        System.out.println("Subsirul este: " + subsir);


        reader.close();
        socketIn.close();
        socketOut.close();
        c.close();
    }
}