#include <iostream>
#include <thread>
#include <atomic>
#include <unistd.h> // For usleep function

using namespace std;

atomic<bool> lock(false); // Bi?n ��nh d?u kh�a, ban �?u kh�ng kh�a

void criticalSection(int id) {
    // �o?n m? c?a v�ng critical section
    cout << "Thread " << id << " is entering critical section." << endl;
    usleep(1000000); // �?i 1 gi�y (��n v? microseconds) �? m� ph?ng c�ng vi?c trong critical section
    cout << "Thread " << id << " is leaving critical section." << endl;
}

void testAndSet(int id) {
    bool expected = false;
    bool desired = true;
    
    while (lock.exchange(desired) == true) {
        // Ch? cho �?n khi lock ��?c gi?i ph�ng
    }
    
    // B�y gi? lock �? ��?c gi? b?i ti?n tr?nh hi?n t?i
    criticalSection(id);
    
    // Gi?i ph�ng lock
    lock = false;
}

int main() {
    const int numThreads = 3;
    thread threads[numThreads];

    // T?o v� ch?y c�c lu?ng
    for (int i = 0; i < numThreads; ++i) {
        threads[i] = thread(testAndSet, i);
    }

    // Join c�c lu?ng l?i v?i nhau
    for (int i = 0; i < numThreads; ++i) {
        threads[i].join();
    }

    return 0;
}

