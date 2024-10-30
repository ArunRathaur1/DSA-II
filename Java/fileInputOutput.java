import java.io.*;
public class fileInputOutput{
    public static void main(String[] args) {
        try{
            FileOutputStream ob=new FileOutputStream("1.txt");
            String a="hello";
            byte[] b=a.getBytes();
            ob.write(b);
            ob.close();
            FileInputStream ob1=new FileInputStream("1.txt");
            int ch;
            ch=ob1.read();
            while(ch!=-1){
                System.err.print((char)ch);
                ch=ob1.read();
            }
        }
      catch(Exception e){
        System.err.println(e);
      }

    }
}