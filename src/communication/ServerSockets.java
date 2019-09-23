package communication;

import java.io.*;
import java.net.ServerSocket;
import java.net.Socket;

public class ServerSockets implements Runnable {

    ServerSocket serverSocket;
    Socket clientSocket;
    public Integer port = 8080;
    public static String jsonData1;
    public static String jsonData2;
    public static JsonEntities jsonEntities1;
    public static JsonEntities jsonEntities2;
    public static JsonClient jsonClient1;
    public static JsonClient jsonClient2;
    BufferedReader in;
    OutputStreamWriter out;

    @Override
    public void run() {
        try {
            serverSocket = new ServerSocket(port);
        } catch (IOException e) {
            e.printStackTrace();
        }
        String inputLine;
        Json json = new Json();
        while (true) {
            try {
                // output
                clientSocket = serverSocket.accept();
                out = new OutputStreamWriter(new BufferedOutputStream(clientSocket.getOutputStream()));
                String jsonData = Json.jsonEntitiesToString(jsonEntities1);
                out.write(jsonData);
                out.flush();
                // input
                clientSocket = serverSocket.accept();
                in = new BufferedReader(new InputStreamReader(clientSocket.getInputStream()));
                inputLine = in.readLine();
                json.jsonToEntities(inputLine);
                clientSocket.close();

            } catch (Exception e) {}
        }
    }
}