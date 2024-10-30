import java.io.*;
public class FileReaderWriter {
    public static void main(String[] args) {
        try{
            FileWriter ob1=new FileWriter("2.txt");
            String s="hello This is the content to the file";
            ob1.write(s);
            ob1.close();
            FileReader ob2=new FileReader("2.txt");
            int tem=ob2.read();
            while(tem!=-1){
                System.out.println((char)tem);
                tem=ob2.read();
            }
        }
       catch(Exception e){
        System.out.println(e);
       }

    } 
}
