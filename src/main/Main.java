package main;

import com.fasterxml.jackson.core.JsonProcessingException;
import communication.AddEntities;
import communication.Json;
import communication.JsonEntities;
import communication.ServerSockets;
import entities.Crocodile;
import entities.DonkeyKongJr;
import entities.Fruit;

import java.util.HashMap;

public class Main {

//    public static VinesHashMap vinesHashMap = new VinesHashMap();

    public static void main(String args[]) throws JsonProcessingException {
        ServerSockets.jsonEntities1 = new JsonEntities(1);
        Thread t = new Thread(new ServerSockets());
        t.start();
        AddEntities.addEntity();
    }
}
