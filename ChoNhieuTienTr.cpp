#include <iostream>
#include <thread>
#include <atomic>
#include <vector>
#include <unistd.h> // For usleep function

using namespace std;

const int N = 3; // S? lý?ng ti?n tr?nh

atomic<bool> Lock(false); // Bi?n ðánh d?u lock
vector<bool> Waiting(N, false); // M?ng ðánh d?u tr?ng thái ch? c?a t?ng ti?n tr?nh

void criticalSection(int id) {
    // Ðo?n m? c?a vùng critical section
    cout << "Process " << id << " is in critical section." << endl;
    usleep(1000000); // Ð?i 1 giây (ðõn v? microseconds) ð? mô ph?ng công vi?c trong critical section
    cout << "Process " << id << " is leaving critical section." << endl;
}

void process(int i) {
    do {
        Waiting[i] = true;
        while (Waiting[i] && Lock.exchange(true)) {
            // Ð?i cho ð?n khi lock ðý?c gi?i phóng
        }
        Waiting[i] = false;

        // Vào vùng critical section
        criticalSection(i);

        // Ki?m tra xem có ti?n tr?nh khác ðang ch? không
        int j = (i + 1) % N;
        while (j != i && !Waiting[j]) {
            j = (j + 1) % N;
        }

        if (j == i) {
            Lock = false; // Không c?n ti?n tr?nh nào ðang ch?, gi?i phóng lock
        } else {
            Waiting[j] = false; // Chuy?n lock cho ti?n tr?nh ti?p theo ðang ch?
        }

        // Rest and repeat
    } while (true);
}

int main() {
    vector<thread> threads;

    // T?o và ch?y các lu?ng (ti?n tr?nh)
    for (int i = 0; i < N; ++i) {
        threads.emplace_back(process, i);
    }

    // Join các lu?ng l?i v?i nhau
    for (auto& thread : threads) {
        thread.join();
    }

    return 0;
}

