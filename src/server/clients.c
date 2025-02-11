#include "server.h"

client_t *find_or_add_client(server_s *Server, struct sockaddr_in client_addr) {
    client_t *current = Server->clients;

    while (current) {
        if (current->addr.sin_addr.s_addr == client_addr.sin_addr.s_addr &&
            current->addr.sin_port == client_addr.sin_port) {
            return current;
        }
        current = current->next;
    }

    client_t *new_client = malloc(sizeof(client_t));
    if (!new_client) {
        perror("Erreur d'allocation mémoire");
        return NULL;
    }

    new_client->addr = client_addr;
    uuid_generate(new_client->uuid);
    uuid_unparse(new_client->uuid, new_client->uuid_str);
    new_client->next = Server->clients;
    Server->clients = new_client;

    printf("Nouveau client enregistré : %s (IP: %s, Port: %d)\n",
           new_client->uuid_str,
           inet_ntoa(client_addr.sin_addr),
           ntohs(client_addr.sin_port));

    return new_client;
}
