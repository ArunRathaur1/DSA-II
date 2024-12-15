public class ProducerConsumer {
    static int size = 5;
    static int buffer[] = new int[size];
    static int count = 0;
    static int in = 0, out = 0;

    // Synchronization lock
    static final Object lock = new Object();

    // Producer thread
    public class Producer extends Thread {
        public void run() {
            int value = 0;
            while (true) {
                synchronized (lock) {
                    // Wait if the buffer is full
                    while (count == size) {
                        try {
                            lock.wait();
                        } catch (InterruptedException e) {
                            e.printStackTrace();
                        }
                    }
                    // Produce an item
                    buffer[in] = value;
                    System.out.println("Value Produced: " + value);
                    value++;
                    in = (in + 1) % size;
                    count++;
                    lock.notifyAll(); // Notify waiting threads
                }
            }
        }
    }

    // Consumer thread
    public class Consumer extends Thread {
        public void run() {
            while (true) {
                synchronized (lock) {
                    // Wait if the buffer is empty
                    while (count == 0) {
                        try {
                            lock.wait();
                        } catch (InterruptedException e) {
                            e.printStackTrace();
                        }
                    }
                    // Consume an item
                    int consumedValue = buffer[out];
                    System.out.println("Value Consumed: " + consumedValue);
                    out = (out + 1) % size;
                    count--;
                    lock.notifyAll(); // Notify waiting threads
                }
            }
        }
    }

    public static void main(String[] args) {
        ProducerConsumer obj = new ProducerConsumer();
        Producer producer = obj.new Producer();
        Consumer consumer = obj.new Consumer();

        producer.start();
        consumer.start();
    }
}
