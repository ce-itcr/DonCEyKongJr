package entities;

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
}
