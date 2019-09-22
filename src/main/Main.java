package main;

import com.fasterxml.jackson.core.JsonProcessingException;
import communication.AddEntities;
import communication.Json;
import communication.JsonEntities;
import communication.ServerSockets;
import entities.Crocodile;
import entities.DonkeyKongJr;
import entities.Fruit;

public class Main {

    public static void main(String args[]) throws JsonProcessingException {
        ServerSockets.jsonEntities1 = new JsonEntities();
        Thread t = new Thread(new ServerSockets());
        t.start();
        AddEntities.addEntity();
//        Crocodile[] crocodiles = {crocodile1, crocodile2};
//        Fruit[] fruits = {fruit1, fruit2};
//        DonkeyKongJr donkeyKongJr = new DonkeyKongJr(10, true, 100, 200);
//        JsonEntities jsonEntities = new JsonEntities(crocodiles, fruits, donkeyKongJr, 10, 1);
//        System.out.print(Json.jsonEntitiesToString(jsonEntities));
    }
}
