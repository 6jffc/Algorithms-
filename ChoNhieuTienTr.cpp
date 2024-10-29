#include <iostream>
#include <thread>
#include <atomic>
#include <vector>
#include <unistd.h> // For usleep function

using namespace std;

const int N = 3; // S? l�?ng ti?n tr?nh

atomic<bool> Lock(false); // Bi?n ��nh d?u lock
vector<bool> Waiting(N, false); // M?ng ��nh d?u tr?ng th�i ch? c?a t?ng ti?n tr?nh

void criticalSection(int id) {
    // �o?n m? c?a v�ng critical section
    cout << "Process " << id << " is in critical section." << endl;
    usleep(1000000); // �?i 1 gi�y (��n v? microseconds) �? m� ph?ng c�ng vi?c trong critical section
    cout << "Process " << id << " is leaving critical section." << endl;
}

void process(int i) {
    do {
        Waiting[i] = true;
        while (Waiting[i] && Lock.exchange(true)) {
            // �?i cho �?n khi lock ��?c gi?i ph�ng
        }
        Waiting[i] = false;

        // V�o v�ng critical section
        criticalSection(i);

        // Ki?m tra xem c� ti?n tr?nh kh�c �ang ch? kh�ng
        int j = (i + 1) % N;
        while (j != i && !Waiting[j]) {
            j = (j + 1) % N;
        }

        if (j == i) {
            Lock = false; // Kh�ng c?n ti?n tr?nh n�o �ang ch?, gi?i ph�ng lock
        } else {
            Waiting[j] = false; // Chuy?n lock cho ti?n tr?nh ti?p theo �ang ch?
        }

        // Rest and repeat
    } while (true);
}

int main() {
    vector<thread> threads;

    // T?o v� ch?y c�c lu?ng (ti?n tr?nh)
    for (int i = 0; i < N; ++i) {
        threads.emplace_back(process, i);
    }

    // Join c�c lu?ng l?i v?i nhau
    for (auto& thread : threads) {
        thread.join();
    }

    return 0;
}

