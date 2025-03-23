import java.util.concurrent.locks.*;

 class ReaderWriterExample {
     static ReentrantReadWriteLock lock = new ReentrantReadWriteLock();
     static Lock readLock = lock.readLock();
     static Lock writeLock = lock.writeLock();
     static int x = 5; // Shared variable

    // Reader Thread
    static class Reader extends Thread {
        @Override
        public void run() {
            readLock.lock(); // Acquire read lock
            try {
                System.out.println(Thread.currentThread().getName() + " reads: " + x);
            } finally {
                readLock.unlock(); // Release read lock
            }
        }
    }

    // Writer Thread
    static class Writer extends Thread {
        @Override
        public void run() {
            writeLock.lock(); // Acquire write lock
            try {
                x++; // Modify the shared resource
                System.out.println(Thread.currentThread().getName() + " writes: " + x);
            } finally {
                writeLock.unlock(); // Release write lock
            }
        }
    }

    public static void main(String[] args) {
        // Create threads
        Writer writer1 = new Writer();
        Writer writer2 = new Writer();
        Reader reader1 = new Reader();
        Reader reader2 = new Reader();

        // Start threads
        writer1.start();
        reader1.start();
        writer2.start();
        reader2.start();
    }
}
