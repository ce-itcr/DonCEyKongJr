package communication;

import com.fasterxml.jackson.core.JsonProcessingException;
import com.fasterxml.jackson.databind.ObjectMapper;

import java.util.Arrays;

public class Json {

    public void jsonToEntities(String json) {
        try {
            ObjectMapper mapper = new ObjectMapper();
            JsonClient jsonClient = mapper.readValue(json, JsonClient.class);
            ServerSockets.jsonEntities1.gameOn = jsonClient.gameOn;
            ServerSockets.jsonEntities1.score = jsonClient.score;
            for (int i = 0; i < jsonClient.numOfCrocodiles; i++) {
                ServerSockets.jsonEntities1.crocodiles[i].alive = jsonClient.crocodilesAlive[i];
            }
            for (int i = 0; i < jsonClient.numOfFruits; i++) {
                ServerSockets.jsonEntities1.fruits[i].alive = jsonClient.fruitsAlive[i];
            }
        } catch (Exception e) {
            e.printStackTrace();
        }
    }

    public static String jsonEntitiesToString(JsonEntities jsonEntities) throws JsonProcessingException {
        ObjectMapper mapper = new ObjectMapper();
        String str = mapper.writeValueAsString(jsonEntities);
        return str;
    }
}
