package communication;

public class JsonClient {
    Integer score;
    Integer gameOn;
    Integer Hp;
    Integer[] fruitsAlive;
    Integer[] crocodilesAlive;
    Integer numOfCrocodiles;
    Integer numOfFruits;

    public JsonClient(Integer score, Integer gameOn, Integer hp, Integer[] fruitsAlive, Integer[] crocodilesAlive, Integer numOfCrocodiles, Integer numOfFruits) {
        this.score = score;
        this.gameOn = gameOn;
        Hp = hp;
        this.fruitsAlive = fruitsAlive;
        this.crocodilesAlive = crocodilesAlive;
        this.numOfCrocodiles = numOfCrocodiles;
        this.numOfFruits = numOfFruits;
    }

    public JsonClient(String json) {

    }
}
