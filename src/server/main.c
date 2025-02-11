#include "server.h"

int main(void) {
    int socket;
    server_s Server = {NULL, PORT, -1};

    int init_status = init_server(&Server);
    if (init_status == EXIT_FAILURE) {
        return EXIT_FAILURE;
    }

    Server._socket = create_socket(Server._port);
    printf("Serveur UDP en écoute sur le port %d...\n", Server._port);

    start_server(&Server);
    close(socket);
    return EXIT_SUCCESS;
}
