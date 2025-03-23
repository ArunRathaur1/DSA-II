

public class producerconsuer  {
    static int size=5;
    static int buffer[]=new int[size];
    static int count=0;
    static int in=0,out=0;
    public class produce extends Thread{
        public void run(){

            int value=0;
            while (true) {
                synchronized(buffer){
                    while(count==size){
                        try{
                            buffer.wait();
                        }
                        catch(Exception e){
        
                        }
                    }
                    in=(in+1)%size;
                    System.out.println("Value Produced "+value);
                    buffer[in]=value;
                    count++;
                    buffer.notifyAll();
                    value++;
            }
           }
        }
    };
    public class consume extends Thread{
        public void run(){
            while (true) {
                synchronized(buffer){
                    while(count==0){
                        try{
                            buffer.wait();
                        }
                        catch(Exception e){
    
                        }
                    }
                    System.out.println("Value consumed "+buffer[out]);
                    out=(out+1)%size;
                    count--;
                    buffer.notifyAll();
            }
            
            }
        }
    };
    public static void main(String[] args) {
        producerconsuer obj=new producerconsuer();
        produce ob=obj.new produce();
        consume ob1=obj.new consume();
        ob.start();
        ob1.start();
    }
}
