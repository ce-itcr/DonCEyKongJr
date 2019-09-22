package entities;

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
}
