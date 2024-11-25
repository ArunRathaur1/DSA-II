#include <iostream>
#include <thread>

void printNumbers(const std::string& threadName) {
    for (int i = 1; i <= 10; ++i) {
        std::cout << threadName << ": " << i << std::endl;
    }
}

int main() {
    // Create two threads, each running the printNumbers function
    std::thread t1(printNumbers, "Thread 1");
    std::thread t2(printNumbers, "Thread 2");

    // Wait for both threads to finish
    t1.join();
    t2.join();

    std::cout << "Both threads have finished execution." << std::endl;
    return 0;
}
