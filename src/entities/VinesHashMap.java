package entities;

import java.util.HashMap;

public class VinesHashMap {

    public HashMap<Integer, Integer[]> vinesCoords;
    private Integer[][] coordsList = {
            {34, 150},
            {105, 150},
            {177, 295},
            {297, 150},
            {393, 150},
            {465, 175},
            {537, 175},
            {609, 105},
            {681, 105},
            {297, 52}
    };

    public HashMap<Integer, Integer[]> createHashMap(){
        HashMap<Integer, Integer[]> m1 = new HashMap<>();
        for (int i = 0; i < coordsList.length; i++)
            m1.put(i, coordsList[i]);
        return m1;
    }

    public VinesHashMap() {
        this.vinesCoords = createHashMap();
    }
}
