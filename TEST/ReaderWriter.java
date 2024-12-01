package TEST;
import java.util.concurrent.locks.*;

public class ReaderWriter {
    static ReentrantReadWriteLock ob = new ReentrantReadWriteLock();
    static Lock read = ob.readLock();
    static Lock write = ob.writeLock();
    static String s = "This is sample";

    static class Read extends Thread {
        public void run() {
            try {
                // Random delay for each thread
                Double x=Math.random();
                int y=(int)Math.floor(x*1000);
                Thread.sleep(y);
            } catch (Exception e) {
                e.printStackTrace();
            }
            read.lock();
            try {
                System.out.println("Reader is Reading -> " + s);
            } finally {
                read.unlock();
            }
        }
    }

    static class Write extends Thread {
        public void run() {
            try {
                // Random delay for each thread
                Double x=Math.random();
                int y=(int)Math.floor(x*1000);
                Thread.sleep(y);
            } catch (Exception e) {
                e.printStackTrace();
            }
            write.lock();
            try {
                s = s + " appended ";
                System.out.println("Writer updating the String -> " + s);
            } finally {
                write.unlock();
            }
        }
    }

    public static void main(String[] args) {
        // Create a mix of Read and Write threads
        for (int i = 0; i < 10; i++) {
            Double x=Math.random();
                int y=(int)Math.floor(x*1000);
            if (y<500) {
                new Write().start();
            } else {
                new Read().start();
            }
        }
    }
}
