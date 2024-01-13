import java.io.*;
import java.net.*;

class TCPServer {
    public static void main(String argv[]) throws Exception {
        String fromClient;
        String toClient;
        ServerSocket server = new ServerSocket(5000);
        System.out.println("TCPServer waiting for a client on port 5000");

        while (true) {
            Socket connected = server.accept();
            System.out.println("CLIENT connected: " + connected.getInetAddress() + " at port " + connected.getPort());
            BufferedReader inFromUser = new BufferedReader(new InputStreamReader(System.in));
            BufferedReader inFromClient = new BufferedReader(new InputStreamReader(connected.getInputStream()));
            PrintWriter outToClient = new PrintWriter(connected.getOutputStream(), true);

            while (true) {
                System.out.println("SEND (Type Q or q to quit):");
                toClient = inFromUser.readLine();

                if (toClient.equalsIgnoreCase("q")) {
                    outToClient.println(toClient);
                    connected.close();
                    break;
                } else {
                    outToClient.println(toClient);
                }

                fromClient = inFromClient.readLine();

                if (fromClient.equalsIgnoreCase("q")) {
                    connected.close();
                    break;
                } else {
                    System.out.println("RECEIVED: " + fromClient);
                }
            }
        }
    }
}
