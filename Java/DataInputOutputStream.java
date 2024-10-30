 import java.io.*;
 class Data{
  public static void main(String[] args) {
    try{
        int k=10;
        FileOutputStream ob1=new FileOutputStream("1.txt");
        DataOutputStream ob2=new DataOutputStream(ob1);
        ob2.writeInt(k);
        FileInputStream ob3=new FileInputStream("1.txt");
        DataInputStream ob4=new DataInputStream(ob3);
        System.err.println(ob4.readInt());
    }
    catch(Exception e){
        System.err.println(e);
    }
  }  
}
