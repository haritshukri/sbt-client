#include <stdio.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <unistd.h>
#include <string.h>

int main() {
    int sock;
    struct sockaddr_in server;
    char message[5];

    //create socket
    sock = socket(AF_INET, SOCK_STREAM, 0);
    if (sock == -1) {
        printf("Could not create socket");
    }

    server.sin_addr.s_addr = inet_addr("192.168.220.128");
    server.sin_family = AF_INET;
    server.sin_port = htons(8888);

    //connect to remote server
    if (connect(sock, (struct sockaddr *) &server, sizeof(server)) < 0) {
        perror("connect failed. Error");
        return 1;
    }

    //receive the random number from the server
    int read_size = recv(sock, message, sizeof(message), 0);
    if (read_size > 0) {
        printf("Random number received from server: %s\n", message);
    } else if (read_size == 0) {
        puts("Client disconnected");
    } else {
        perror("recv failed");
    }

    //close socket
    close(sock);

    return 0;
}
