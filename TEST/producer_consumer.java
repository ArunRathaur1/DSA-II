package TEST;

public class producer_consumer {
    static int maxbuffer=5;
    static int buffer[]=new int[5];
    static int count=0;
    static int in=0;
    static int out=0;
    static class produce extends Thread{
        public void run(){
            int x=0;
            int value=0;
            while(x<5){
                synchronized(buffer){
                    while(maxbuffer==count){
                        try{
                            buffer.wait();
                        }
                        catch(Exception e){

                        }
                    }
                     
                    System.out.println("value "+value+ " at index  "+in);
                    in=(in+1)%maxbuffer;
                    buffer[in]=value;
                    count++;
                    value++;
                    
                    buffer.notifyAll();
                    try{
                        Thread.sleep(500);
                    }catch(Exception e){

                    }
                }
                x++;
                   
                
            }
        }
    }
   static class consumer extends Thread{
        public void run(){
            int x=0;
            while(x<5){
                synchronized(buffer){
                    while(count==0){
                        try{
                            buffer.wait();
                        }
                        catch(Exception e){

                        }
                    }
                        System.out.println("Consumer "+buffer[out]);
                        out=(out+1)%maxbuffer;
                        count--;
                       
                        buffer.notifyAll();
                        try{
                            Thread.sleep(500);
                        }
                        catch(Exception e){

                        }
                    }
                    x++;
                       
                    
                }
            }
        }
    public static void main(String[] args) {
        produce ob1=new produce();
        consumer ob2=new consumer();
        ob1.start();
        ob2.start();
    }
}
