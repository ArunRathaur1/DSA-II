import java.io.*;
 class FileReaderWrite {
    public static void main(String[] args) {
        try{
            FileWriter ob1=new FileWriter("2.txt");
            BufferedWriter text=new BufferedWriter(ob1);
            String s="hello This is the content to the file";
            text.write(s);
            text.newLine();
            text.write(s);
            text.close();
            FileReader ob2=new FileReader("2.txt");
            BufferedReader text2=new BufferedReader(ob2);
            int tem=text2.read();
            while(tem!=-1){
                System.out.print((char)tem);
                tem=text2.read();
            }
        }
       catch(Exception e){
        System.out.println(e);
       }

    } 
}
