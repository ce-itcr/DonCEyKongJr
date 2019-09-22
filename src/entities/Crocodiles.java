package entities;

import communication.ServerSockets;

public class Crocodiles {
    
    public void createCrocodile(Integer listNum, Crocodile crocodile){
        if (listNum == 1){
            Crocodile[] crocodilesListTmp;
            try {
                crocodilesListTmp = new Crocodile[ServerSockets.jsonEntities1.crocodiles.length + 1];
            } catch (Exception e){
                ServerSockets.jsonEntities1.crocodiles = new Crocodile[0];
                crocodilesListTmp = new Crocodile[1];
            }
                for (Integer i = 0; i < ServerSockets.jsonEntities1.crocodiles.length; i++)
                    crocodilesListTmp[i] = ServerSockets.jsonEntities1.crocodiles[i];
                crocodilesListTmp[ServerSockets.jsonEntities1.crocodiles.length] = crocodile;
                ServerSockets.jsonEntities1.crocodiles = crocodilesListTmp;

        }
        ServerSockets.jsonEntities1.numOfCrocodiles++;
//        else if (listNum == 2) {
//            Crocodile[] crocodileslistTmp = new Crocodile[crocodilesList2.length+1];
//            for (Integer i = 0; i < crocodilesList2.length; i++)
//                crocodileslistTmp[i] = crocodilesList2[i];
//            crocodileslistTmp[crocodilesList2.length] = crocodile;
//        }
    }

}
