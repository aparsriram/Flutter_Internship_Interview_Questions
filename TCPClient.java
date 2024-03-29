import java.io.*;
import java.net.*;

class TCPClient {
    public static void main(String argv[]) throws Exception {
        String fromServer;
        String toServer;

        Socket clientSocket = new Socket("localhost", 5000);
        BufferedReader inFromUser = new BufferedReader(new InputStreamReader(System.in));
        PrintWriter outToServer = new PrintWriter(clientSocket.getOutputStream(), true);
        BufferedReader inFromServer = new BufferedReader(new InputStreamReader(clientSocket.getInputStream()));

        while (true) {
            fromServer = inFromServer.readLine();

            if (fromServer.equals("q") || fromServer.equals("Q")) {
                clientSocket.close();
                break;
            } else {
                System.out.println("RECEIVED: " + fromServer);
                System.out.println("SEND (Type Q or q to Quit):");
                toServer = inFromUser.readLine();

                if (toServer.equalsIgnoreCase("Q") || toServer.equalsIgnoreCase("q")) {
                    outToServer.println(toServer);
                    clientSocket.close();
                    break;
                } else {
                    outToServer.println(toServer);
                }
            }
        }
    }
}
