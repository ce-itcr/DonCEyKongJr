package main;

import com.fasterxml.jackson.core.JsonProcessingException;
import communication.AddEntities;
import communication.JsonEntities;
import communication.ServerSockets;

public class Main {

//    public static VinesHashMap vinesHashMap = new VinesHashMap();

    public static void main(String args[]) throws JsonProcessingException {
        ServerSockets.jsonEntities1 = new JsonEntities(1);
        Thread t = new Thread(new ServerSockets());
        t.start();
        AddEntities.addEntity();
    }
}
