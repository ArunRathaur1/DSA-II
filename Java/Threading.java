

class counter{
    public synchronized void increemnt(){
        for(int i=0;i<5;i++){
            System.out.println(i);
        }
    }
}
public class Threading  extends Thread{
    counter c;
    Threading(counter c){
        this.c=c;
    }
    public void run(){
        c.increemnt();
    }
    public static void main(String[] args) {
        counter c=new counter();
       for(int i=0;i<4;i++){
        Threading ob=new Threading(c);
        ob.start();
       }
       
    }
}
