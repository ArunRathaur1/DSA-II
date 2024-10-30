import java.util.*;

class MapExample {
    public static void main(String[] args) {
        Map<Integer, String> m1 = new HashMap<Integer,String>();
        m1.put(5, "Arun");
        
        for (int i : m1.keySet()) {
            System.out.println(m1.get(i));
        }
    }
}
