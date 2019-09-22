package communication;

import com.fasterxml.jackson.core.JsonProcessingException;
import com.fasterxml.jackson.databind.ObjectMapper;

public class Json {

    public JsonEntities jsonToEntities(String json) throws JsonProcessingException {
        ObjectMapper mapper= new ObjectMapper();
        JsonClient jsonClient = mapper.readValue(json, JsonClient.class);
        JsonEntities jsonEntities = new JsonEntities();
        jsonEntities.numOfCrocodiles = jsonClient.numOfCrocodiles;
        jsonEntities.numOfFruits = jsonClient.numOfFruits;
        jsonEntities.gameOn = jsonClient.gameOn;
        jsonEntities.score = jsonClient.score;
        jsonEntities = updateAliveArrays(jsonEntities, jsonClient);
        return jsonEntities;
    }

    private JsonEntities updateAliveArrays(JsonEntities jsonEntities, JsonClient jsonClient){
        for (int i = 0; i < jsonClient.numOfCrocodiles; i++)
            jsonEntities.crocodiles[i].alive = jsonClient.crocodilesAlive[i];
        for (int i = 0; i < jsonClient.numOfFruits; i++)
            jsonEntities.fruits[i].alive = jsonClient.fruitsAlive[i];
        return jsonEntities;
    }


    public static String jsonEntitiesToString(JsonEntities jsonEntities) throws JsonProcessingException {
        ObjectMapper mapper = new ObjectMapper();
        String str = mapper.writeValueAsString(jsonEntities);
        return str;
    }
}
