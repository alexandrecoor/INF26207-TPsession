#include "common.h"
#include "client.h"

void start_client() {
    int client_socket;
    struct sockaddr_in server_addr;
    char buffer[BUFFER_SIZE];

    client_socket = socket(AF_INET, SOCK_DGRAM, 0);
    if (client_socket == -1) {
        perror("Erreur de création du socket");
        exit(EXIT_FAILURE);
    }

    server_addr.sin_family = AF_INET;
    server_addr.sin_port = htons(PORT);
    server_addr.sin_addr.s_addr = inet_addr("127.0.0.1");

    printf("Envoyer un message : ");
    fgets(buffer, BUFFER_SIZE, stdin);
    buffer[strcspn(buffer, "\n")] = 0;

    sendto(client_socket, buffer, strlen(buffer), 0,
           (struct sockaddr*)&server_addr, sizeof(server_addr));

    socklen_t server_len = sizeof(server_addr);
    int recv_len = recvfrom(client_socket, buffer, BUFFER_SIZE, 0,
                            (struct sockaddr*)&server_addr, &server_len);
    if (recv_len > 0) {
        buffer[recv_len] = '\0';
        printf("Réponse du serveur : %s\n", buffer);
    }

    close(client_socket);
}

int main() {
    start_client();
    return 0;
}
