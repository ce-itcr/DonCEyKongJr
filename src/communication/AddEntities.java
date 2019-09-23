package communication;

import com.fasterxml.jackson.core.JsonProcessingException;
import entities.Crocodile;
import entities.Fruit;

import java.util.Scanner;

public class AddEntities {

    public static void addEntity() throws JsonProcessingException { // entity: 0=Crocodile 1=Fruit
        Scanner scanner = new Scanner(System.in);
        while (true) {
            System.out.println("Digite el numero del objeto que desea crear: 0 = cocodrilo, 1 = fruta");
            Integer entityNum = scanner.nextInt();
            if (entityNum == 0) {
                Crocodile obj = new Crocodile();
                System.out.println("Digite las coordenadas");
                System.out.println("X: ");
                obj.posX = scanner.nextInt();
                System.out.println("Y: ");
                obj.posY = scanner.nextInt();
                System.out.println("Digite el color del cocodrilo: 0 = azul, 1+ = rojo");
                obj.species = scanner.nextInt();
                obj.alive = 1;
                Crocodile crocodile = new Crocodile();
                crocodile.createCrocodile(1, obj);
                System.out.println(Json.jsonEntitiesToString(ServerSockets.jsonEntities1));
            } else if (entityNum == 1) {
                Fruit obj = new Fruit();
                System.out.println("Digite el puntaje que recibira el jugador al coger la fruta");
                obj.score = scanner.nextInt();
                System.out.println("Digite las coordenadas");
                System.out.println("X: ");
                obj.posX = scanner.nextInt();
                System.out.println("Y: ");
                obj.posY = scanner.nextInt();
                System.out.println("Digite el tipo de fruta: 0 = banana, 1 = naranja, 2+ = fresas");
                obj.species = scanner.nextInt();
                obj.alive = 1;
                Fruit fruit = new Fruit();
                fruit.createFruit(1, obj);
                System.out.println(Json.jsonEntitiesToString(ServerSockets.jsonEntities1));
            } else {
                System.out.println("Numero invalido");
            }
        }
    }
}
