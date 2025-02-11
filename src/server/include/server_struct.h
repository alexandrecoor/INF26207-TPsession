#ifndef SERVER_STRUCT_H
#define SERVER_STRUCT_H

typedef struct client {
    struct sockaddr_in addr;
    uuid_t uuid;
    char uuid_str[37];
    struct client *next;
} client_t;

typedef struct server_t {
    client_t *clients;
    int _port;
    int _socket;
} server_s;

#endif // SERVER_STRUCT_H
