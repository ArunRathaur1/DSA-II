import java.beans.Transient;
import java.io.*;

import javax.swing.JLabel;
class saveDAta implements Serializable{
   transient int a;
    int b;
    int c;
}
public class filemanulpluation {
  public static void main(String[] args) {
    try{
      FileInputStream ob1=new FileInputStream("hello2.txt");
      BufferedInputStream ob2=new BufferedInputStream(ob1);
      DataInputStream ob3=new DataInputStream(ob1);
      ObjectInput ob4=new ObjectInputStream(ob1);
      saveDAta ob5=(saveDAta)ob4.readObject();
      System.out.println(ob5);
    }
    catch(Exception e){
        
    }
}}  

