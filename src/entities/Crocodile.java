package entities;

import communication.ServerSockets;

import java.util.Arrays;

public class Crocodile {

    public Integer species;
    public Integer posX;
    public Integer posY;
    public Integer alive;

    public Crocodile(Integer species, Integer posX, Integer posY, Integer alive) {
        this.species = species;
        this.posX = posX;
        this.posY = posY;
        this.alive = alive;
    }
    public Crocodile(){}

    public void createCrocodile(Integer listNum, Crocodile crocodile) {
        if (listNum == 1) {
            Crocodile[] crocodilesListTmp;
            try {
                crocodilesListTmp = new Crocodile[ServerSockets.jsonEntities1.crocodiles.length + 1];
            } catch (Exception e) {
                ServerSockets.jsonEntities1.crocodiles = new Crocodile[0];
                crocodilesListTmp = new Crocodile[1];
                e.printStackTrace();
            }
            for (Integer i = 0; i < ServerSockets.jsonEntities1.crocodiles.length; i++)
                crocodilesListTmp[i] = ServerSockets.jsonEntities1.crocodiles[i];
            crocodilesListTmp[ServerSockets.jsonEntities1.crocodiles.length] = crocodile;
            ServerSockets.jsonEntities1.crocodiles = crocodilesListTmp;
        }
        ServerSockets.jsonEntities1.numOfCrocodiles++;
    }
}
