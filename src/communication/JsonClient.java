package communication;

public class JsonClient {
    public Integer gameOn;
    public Integer score;
    public Integer hp;
    public Integer numOfCrocodiles;
    public Integer numOfFruits;
    public Integer[] crocodilesAlive;
    public Integer[] fruitsAlive;

    public JsonClient(Integer gameOn, Integer score, Integer hp, Integer numOfCrocodiles, Integer numOfFruits, Integer[] crocodilesAlive, Integer[] fruitsAlive) {
        this.gameOn = gameOn;
        this.score = score;
        this.hp = hp;
        this.numOfCrocodiles = numOfCrocodiles;
        this.numOfFruits = numOfFruits;
        this.crocodilesAlive = crocodilesAlive;
        this.fruitsAlive = fruitsAlive;
    }

    public JsonClient() {
        super();
    }
}
