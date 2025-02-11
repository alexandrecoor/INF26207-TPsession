#ifndef CLIENT_STRUCT_H
#define CLIENT_STRUCT_H

typedef struct client_t {
    int _port;
    int _socket;
    int _logged;
} client_s;

#endif // CLIENT_STRUCT_H
