package entities;

import communication.ServerSockets;

import java.util.Arrays;

public class Fruits {

    public void createFruit(Integer listNum, Fruit fruit) {
        if (listNum == 1) {
            Fruit[] fruitsListTmp;
            try {
                fruitsListTmp = new Fruit[ServerSockets.jsonEntities1.fruits.length + 1];
            } catch (Exception e) {
                ServerSockets.jsonEntities1.fruits = new Fruit[0];
                fruitsListTmp = new Fruit[1];
                e.printStackTrace();
            }
            for (Integer i = 0; i < ServerSockets.jsonEntities1.fruits.length; i++)
                fruitsListTmp[i] = ServerSockets.jsonEntities1.fruits[i];
            fruitsListTmp[ServerSockets.jsonEntities1.fruits.length] = fruit;
            ServerSockets.jsonEntities1.fruits = fruitsListTmp;
            System.out.println("jsonEntities1.fruits.length: ");
            System.out.println(Arrays.toString(ServerSockets.jsonEntities1.fruits));
            System.out.println(ServerSockets.jsonEntities1.fruits.length);
        }
        ServerSockets.jsonEntities1.numOfFruits++;
    }

}
