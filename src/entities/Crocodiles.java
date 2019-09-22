package entities;

import communication.ServerSockets;

import java.util.Arrays;

public class Crocodiles {

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
            System.out.println("jsonEntities1.crocodiles.length: ");
            System.out.println(Arrays.toString(ServerSockets.jsonEntities1.crocodiles));
            System.out.println(ServerSockets.jsonEntities1.crocodiles.length);
        }
        ServerSockets.jsonEntities1.numOfCrocodiles++;
    }

}
