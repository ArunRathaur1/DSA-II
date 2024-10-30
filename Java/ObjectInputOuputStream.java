import java.io.*;
class test implements Serializable{
    int a;
    char b;
    String c;
    test(int a,char b,String c){
        this.a=a;
        this.b=b;
        this.c=c;
    }
}
class Data102 {
    public static void main(String[] args) {
        try{
            test ob1=new test(1, 'd', "Arun");
            FileOutputStream file=new FileOutputStream("1.txt");
            ObjectOutputStream ob=new ObjectOutputStream(file);
            ob.writeObject(ob1);
            ob.close();
            FileInputStream file1=new FileInputStream("1.txt");
            ObjectInputStream ob2=new ObjectInputStream(file1);
            test output= (test)ob2.readObject();
            ob2.close();
            System.out.println(output.a);
            System.err.println(output.b);
            System.err.println(output.c);

        }
       catch(Exception e){
        System.err.println(e);
       }


    }
}
