#ifndef SERVER_FUNCTIONS_H
#define SERVER_FUNCTIONS_H

// server.c
int init_server(server_s *Server);
int start_server(server_s *Server);

// sockets.c
int create_socket(int port);

//clients.c
client_t *find_or_add_client(server_s *Server, struct sockaddr_in client_addr);

#endif // SERVER_FUNCTIONS_H
