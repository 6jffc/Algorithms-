#include <iostream>
#include <thread>
#include <cstring>
#include <arpa/inet.h>
#include <unistd.h>

using namespace std;

void handle_client(int client_socket) {
    char buffer[1024];
    int read_size;

    // �?c d? li?u t? client v� tr? l?i l?i
    while ((read_size = read(client_socket, buffer, sizeof(buffer))) > 0) {
        buffer[read_size] = '\0';  // Th�m k? t? k?t th�c chu?i
        cout << "Client: " << buffer << endl;

        // Nh?p tin nh?n �? g?i l?i cho client
        cout << "You: ";
        cin.getline(buffer, sizeof(buffer));
        write(client_socket, buffer, strlen(buffer));
    }

    // ��ng k?t n?i khi client ng?t k?t n?i
    if (read_size == 0) {
        cout << "Client disconnected" << endl;
        close(client_socket);
    } else if (read_size == -1) {
        perror("recv failed");
    }
}

int main() {
    int server_socket, client_socket;
    struct sockaddr_in server_addr, client_addr;
    socklen_t addr_len = sizeof(client_addr);

    // Kh?i t?o socket
    server_socket = socket(AF_INET, SOCK_STREAM, 0);
    if (server_socket == -1) {
        perror("socket creation failed");
        return 1;
    }

    // Thi?t l?p �?a ch? server
    server_addr.sin_family = AF_INET;
    server_addr.sin_addr.s_addr = INADDR_ANY;
    server_addr.sin_port = htons(12345);  // C?ng 12345

    // Bind socket
    if (bind(server_socket, (struct sockaddr *)&server_addr, sizeof(server_addr)) < 0) {
        perror("bind failed");
        return 1;
    }

    // L?ng nghe k?t n?i
    if (listen(server_socket, 5) < 0) {
        perror("listen failed");
        return 1;
    }

    cout << "Server is listening on port 12345..." << endl;

    while (true) {
        // Ch?p nh?n k?t n?i t? client
        client_socket = accept(server_socket, (struct sockaddr *)&client_addr, &addr_len);
        if (client_socket < 0) {
            perror("accept failed");
            return 1;
        }

        // In �?a ch? IP v� c?ng c?a client k?t n?i �?n
        cout << "Accepted connection from " << inet_ntoa(client_addr.sin_addr) << ":" << ntohs(client_addr.sin_port) << endl;

        // T?o lu?ng �? x? l? client m?i
        thread client_thread(handle_client, client_socket);
        client_thread.detach();  // Gi?i ph�ng lu?ng

        // ��ng k?t n?i m?c �?nh �? m?i client ch? c� th? k?t n?i m?t l?n
        // close(client_socket);
    }

    // ��ng socket server
    close(server_socket);

    return 0;
}

