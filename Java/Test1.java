import java.util.*;
 interface Op {

   int apply(int a, int b); 
}
class myclass{
    public static void main(String[] args) {
        Op add=(a,b)->a+b;
        System.out.println(add.apply(5, 5)); 
    }
}