import java.util.*;
class SetInferface{
    public static void main(String[] args) {
        SortedSet<Integer> ob=new TreeSet<Integer>();
        
        ob.add(15);
        ob.add(5);
        ob.add(10);
        for(Integer i: ob){
            System.out.println(i);
        }
    }
}