import java.util.concurrent.locks.*;
public class ReaderWriter {
    static ReentrantReadWriteLock ob=new ReentrantReadWriteLock();
    static Lock read=ob.readLock();
    static Lock write=ob.writeLock();
    static int r=5;
    static class Reader extends Thread{
        public void run(){
            read.lock();
            try{
                System.out.println("Reader is Reading the "+r);
            }finally{
                read.unlock();
            }
            try{
                Thread.sleep(500);
            }
            catch(Exception e){

            }
        }
    }
    static class Writer extends Thread{
        public void run(){
            write.lock();
            try{
                System.out.println("Writing the Reousece  "+r+" "+(++r));
            }
            finally{
                write.unlock();
            }
            try{
                Thread.sleep(500);
            }
            catch(Exception e){
                
            }
        }
    }  
    public static void main(String[] args) {
        Reader ob1=new Reader();
        Reader ob2=new Reader();
        Writer ob3=new Writer();
        Writer ob4=new Writer();
        ob3.start();
        ob4.start();
        ob1.start();
        ob2.start();
      
    }  
}
