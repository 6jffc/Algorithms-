#include <iostream>
#include <thread>
#include <cstring>
#include <arpa/inet.h>
#include <unistd.h>

using namespace std;

void handle_client(int client_socket) {
    char buffer[1024];
    int read_size;

    // Ð?c d? li?u t? client và tr? l?i l?i
    while ((read_size = read(client_socket, buffer, sizeof(buffer))) > 0) {
        buffer[read_size] = '\0';  // Thêm k? t? k?t thúc chu?i
        cout << "Client: " << buffer << endl;

        // Nh?p tin nh?n ð? g?i l?i cho client
        cout << "You: ";
        cin.getline(buffer, sizeof(buffer));
        write(client_socket, buffer, strlen(buffer));
    }

    // Ðóng k?t n?i khi client ng?t k?t n?i
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

    // Thi?t l?p ð?a ch? server
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

        // In ð?a ch? IP và c?ng c?a client k?t n?i ð?n
        cout << "Accepted connection from " << inet_ntoa(client_addr.sin_addr) << ":" << ntohs(client_addr.sin_port) << endl;

        // T?o lu?ng ð? x? l? client m?i
        thread client_thread(handle_client, client_socket);
        client_thread.detach();  // Gi?i phóng lu?ng

        // Ðóng k?t n?i m?c ð?nh ð? m?i client ch? có th? k?t n?i m?t l?n
        // close(client_socket);
    }

    // Ðóng socket server
    close(server_socket);

    return 0;
}

