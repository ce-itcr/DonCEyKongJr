package communication;

import com.fasterxml.jackson.core.JsonProcessingException;
import com.fasterxml.jackson.databind.ObjectMapper;

import java.util.Arrays;

public class Json {

    public JsonEntities jsonToEntities(String json) {
        try {
            ObjectMapper mapper = new ObjectMapper();
            JsonClient jsonClient = null;
            jsonClient = mapper.readValue(json, JsonClient.class);
            System.out.println("GameOn");
            System.out.println(jsonClient.gameOn);
            ServerSockets.jsonEntities1.numOfCrocodiles = jsonClient.numOfCrocodiles;
            ServerSockets.jsonEntities1.numOfFruits = jsonClient.numOfFruits;
            ServerSockets.jsonEntities1.gameOn = jsonClient.gameOn;
            ServerSockets.jsonEntities1.score = jsonClient.score;
            System.out.println("CA length:");
            System.out.println(jsonClient.crocodilesAlive.length);
            for (int i = 0; i < jsonClient.crocodilesAlive.length; i++) {
                System.out.println("iC: ");
                System.out.println(i);
                System.out.println(ServerSockets.jsonEntities1.crocodiles.length);
                System.out.println(jsonClient.crocodilesAlive.length);
                ServerSockets.jsonEntities1.crocodiles[i].alive = jsonClient.crocodilesAlive[i];
            }
            System.out.println("FA length:");
            System.out.println(jsonClient.fruitsAlive.length);
            for (int i = 0; i < jsonClient.fruitsAlive.length; i++) {
                System.out.println("i: ");
                System.out.println(i);
                System.out.println(ServerSockets.jsonEntities1.fruits[i].alive);
                System.out.println(jsonClient.fruitsAlive[i]);
                ServerSockets.jsonEntities1.fruits[i].alive = jsonClient.fruitsAlive[i];
                System.out.println(ServerSockets.jsonEntities1.fruits[i].alive);
                System.out.println(jsonClient.fruitsAlive[i]);
            }
            return ServerSockets.jsonEntities1;
        } catch (Exception e) {
            e.printStackTrace();
        }
        return new JsonEntities();
    }

    public static String jsonEntitiesToString(JsonEntities jsonEntities) throws JsonProcessingException {
        ObjectMapper mapper = new ObjectMapper();
        String str = mapper.writeValueAsString(jsonEntities);
        return str;
    }
}
