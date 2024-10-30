import java.io.*;
 class Buffered{
    public static void main(String[] args) {
        try{
            FileOutputStream ob5=new FileOutputStream("1.txt");
            BufferedOutputStream ob=new BufferedOutputStream(ob5);
            String a="hello";
            byte[] b=a.getBytes();
            ob.write(b);
            ob.close();
            FileInputStream ob1=new FileInputStream("1.txt");
            BufferedInputStream ob10=new BufferedInputStream(ob1);
            int ch;
            ch=ob10.read();
            while(ch!=-1){
                System.err.print((char)ch);
                ch=ob10.read();
            }
        }
      catch(Exception e){
        System.err.println(e);
      }

    }
}