#include "server.h"

int init_server(server_s *Server) {
    Server->clients = NULL;
    return 0;
}

int start_server(server_s *Server) {
    struct sockaddr_in client_addr;
    char buffer[BUFFER_SIZE];
    socklen_t addr_len = sizeof(client_addr);

    while (1) {
        memset(buffer, 0, BUFFER_SIZE);

        int recv_len = recvfrom(Server->_socket, buffer, BUFFER_SIZE, 0,
                                (struct sockaddr*)&client_addr, &addr_len);
        if (recv_len < 0) {
            perror("Erreur de réception");
            continue;
        }

        client_t *client = find_or_add_client(Server, client_addr);
        if (!client) continue;

        printf("📩 Message reçu (%s) : %s\n", client->uuid_str, buffer);

        char response[BUFFER_SIZE];
        snprintf(response, BUFFER_SIZE, "Message reçu, UUID: %s", client->uuid_str);
        sendto(Server->_socket, response, strlen(response), 0,
               (struct sockaddr*)&client_addr, addr_len);
    }

    return 0;
}
