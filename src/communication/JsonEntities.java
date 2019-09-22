package communication;

import entities.Crocodile;
import entities.DonkeyKongJr;
import entities.Fruit;

public class JsonEntities {

    public Crocodile[] crocodiles;
    public Fruit[] fruits;
    public DonkeyKongJr donkeyKongJr;
    public Integer score;
    public Integer gameOn;
    public Integer numOfCrocodiles;
    public Integer numOfFruits;

    public JsonEntities(Crocodile[] crocodiles, Fruit[] fruits, DonkeyKongJr donkeyKongJr, Integer score, Integer gameOn) {
        this.crocodiles = crocodiles;
        this.fruits = fruits;
        this.donkeyKongJr = donkeyKongJr;
        this.score = score;
        this.gameOn = gameOn;
        this.numOfCrocodiles = crocodiles.length;
        this.numOfFruits = fruits.length;
    }

    public JsonEntities(int i){
        this.crocodiles = new Crocodile[0];
        this.fruits = new Fruit[0];
        this.donkeyKongJr = new DonkeyKongJr(1, 1, 0, 552);
        this.score = 0;
        this.gameOn = 1;
        this.numOfCrocodiles = 0;
        this.numOfFruits = 0;
    }
}
