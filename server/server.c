#include "common.h"
#include "server.h"

void start_server() {
    int server_socket;
    struct sockaddr_in server_addr, client_addr;
    char buffer[BUFFER_SIZE];
    socklen_t addr_len = sizeof(client_addr);

    server_socket = socket(AF_INET, SOCK_DGRAM, 0);
    if (server_socket == -1) {
        perror("Erreur de création du socket");
        exit(EXIT_FAILURE);
    }

    server_addr.sin_family = AF_INET;
    server_addr.sin_port = htons(PORT);
    server_addr.sin_addr.s_addr = INADDR_ANY;

    if (bind(server_socket, (struct sockaddr*)&server_addr, sizeof(server_addr)) < 0) {
        perror("Erreur lors du bind");
        close(server_socket);
        exit(EXIT_FAILURE);
    }

    printf("Serveur en attente de connexions sur le port %d...\n", PORT);

    while (1) {
        int recv_len = recvfrom(server_socket, buffer, BUFFER_SIZE, 0,
                                (struct sockaddr*)&client_addr, &addr_len);
        if (recv_len < 0) {
            perror("Erreur de réception");
            break;
        }

        buffer[recv_len] = '\0';
        printf("Message reçu : %s\n", buffer);

        sendto(server_socket, "ACK", 3, 0, (struct sockaddr*)&client_addr, addr_len);
    }

    close(server_socket);
}

int main() {
    start_server();
    return 0;
}
