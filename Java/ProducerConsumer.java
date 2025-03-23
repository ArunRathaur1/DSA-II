class procuderconsumer {
    static int [] buffer =new int[5];
    static int buffersize=5;
    static int count=0;
    static int in=0;
    static int out=0;
    static class producer extends Thread{
        public void run(){
            int value=0;
            int x=0;
            while(x<5){
                synchronized(buffer){
                    while(count==buffersize){
                        try{
                            buffer.wait();
                        }
                        catch(Exception e){

                        }
                    }
                    System.out.println("Producer produced item "+ value);
                    in=(in+1)%buffersize;
                    buffer[in]=value;
                    value++;
                    count++;
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
    static class consumer extends Thread{
        public void run(){
            int x=0;
            while(x<5){
                synchronized(buffer){
                    while(count==0){
                        try {
                            buffer.wait();
                        } catch (Exception e) {
                           
                        }
                    }
                    System.out.println("Consumer consumed "+buffer[out]);
                    out=(out+1)%buffersize;
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
    public static void main(String args[]){
        producer ob=new producer();
        consumer ob1=new consumer();
        ob.start();
        ob1.start();
    }
}
