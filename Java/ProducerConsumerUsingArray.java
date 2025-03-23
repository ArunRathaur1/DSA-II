public class ProducerConsumerUsingArray {

    private static final int BUFFER_SIZE = 5; // Size of the buffer (array)
    private final int[] buffer = new int[BUFFER_SIZE]; // Shared buffer (array)
    private int count = 0; // Number of items in the buffer
    private int in = 0; // Index for the producer to insert
    private int out = 0; // Index for the consumer to remove

    // Producer Thread
    class Producer extends Thread {
        @Override
        public void run() {
            int value = 0;
            while (true) {
                synchronized (buffer) {
                    while (count == BUFFER_SIZE) {
                        try {
                            buffer.wait(); // Wait if the buffer is full
                        } catch (InterruptedException e) {
                            e.printStackTrace();
                        }
                    }
                    // Produce an item and add it to the buffer
                    buffer[in] = value;
                    System.out.println("Produced: " + value);
                    in = (in + 1) % BUFFER_SIZE; // Circular buffer index
                    count++;
                    value++; // Increment value for the next production
                    buffer.notifyAll(); // Notify the consumer that there's an item to consume
                }
            }
        }
    }

    // Consumer Thread
    class Consumer extends Thread {
        @Override
        public void run() {
            while (true) {
                synchronized (buffer) {
                    while (count == 0) {
                        try {
                            buffer.wait();
                        } catch (Exception e) {
                            
                        }
                    }
                    // Consume an item from the buffer
                    int value = buffer[out];
                    System.out.println("Consumed: " + value);
                    out = (out + 1) % BUFFER_SIZE; // Circular buffer index
                    count--;
                    buffer.notifyAll(); // Notify the producer that space is available
                }
            }
        }
    }

    public static void main(String[] args) {
        ProducerConsumerUsingArray pc = new ProducerConsumerUsingArray();

        // Create and start the producer and consumer threads
        Producer producer = pc.new Producer();
        Consumer consumer = pc.new Consumer();

        producer.start();
        consumer.start();
    }
}
