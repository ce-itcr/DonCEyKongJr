package entities;

import communication.ServerSockets;

import java.util.Arrays;

public class Fruit {

    public Integer species;
    public Integer posX;
    public Integer posY;
    public Integer alive;
    public Integer score;

    public Fruit(Integer species, Integer posX, Integer posY, Integer alive, Integer score) {
        this.species = species;
        this.posX = posX;
        this.posY = posY;
        this.alive = alive;
        this.score = score;
    }
    public Fruit(){}

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
        }
        ServerSockets.jsonEntities1.numOfFruits++;
    }
}
