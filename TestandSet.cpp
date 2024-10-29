#include <iostream>
#include <thread>
#include <atomic>
#include <unistd.h> // For usleep function

using namespace std;

atomic<bool> lock(false); // Bi?n ðánh d?u khóa, ban ð?u không khóa

void criticalSection(int id) {
    // Ðo?n m? c?a vùng critical section
    cout << "Thread " << id << " is entering critical section." << endl;
    usleep(1000000); // Ð?i 1 giây (ðõn v? microseconds) ð? mô ph?ng công vi?c trong critical section
    cout << "Thread " << id << " is leaving critical section." << endl;
}

void testAndSet(int id) {
    bool expected = false;
    bool desired = true;
    
    while (lock.exchange(desired) == true) {
        // Ch? cho ð?n khi lock ðý?c gi?i phóng
    }
    
    // Bây gi? lock ð? ðý?c gi? b?i ti?n tr?nh hi?n t?i
    criticalSection(id);
    
    // Gi?i phóng lock
    lock = false;
}

int main() {
    const int numThreads = 3;
    thread threads[numThreads];

    // T?o và ch?y các lu?ng
    for (int i = 0; i < numThreads; ++i) {
        threads[i] = thread(testAndSet, i);
    }

    // Join các lu?ng l?i v?i nhau
    for (int i = 0; i < numThreads; ++i) {
        threads[i].join();
    }

    return 0;
}

