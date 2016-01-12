#include "csendclient.h"
/*
 * ip -> send to
 * file -> send file path
 * port -> recv port
 */
csendClient::csendClient(const char *ip, const char *file, int port){

    strcpy(this->file, file);
    strcpy(this->ip, ip);
    this->port = port;
    DEBUG = true;

}
/*
 * Send File
 */
bool csendClient::startRun(){


#ifndef BUFFER_SIZE
#define BUFFER_SIZE 2048
#endif

    int fr = open(file, O_RDONLY);
    int client_socket = socket(AF_INET, SOCK_STREAM, 0);

    struct sockaddr_in addr;
    bzero((void*)&addr, sizeof(addr));
    addr.sin_family = AF_INET;
    addr.sin_port = htons(port);
    inet_aton(ip, (struct in_addr*)&addr.sin_addr);

    if(connect(client_socket, (struct sockaddr*)&addr, sizeof(addr))< 0){
        if(DEBUG)
            printf("Connect error! [%d %s %d]\n", client_socket, ip, port);
        exit(-1);
    }

    if(DEBUG)
        printf("Connect successful!\n");


    char buffer[BUFFER_SIZE];
    while(1){

        int write_len, read_len = read(fr, buffer, BUFFER_SIZE);
        char *pr = buffer;
        int L = read_len;

        if(read_len <= 0)
            break;

        while((write_len = write(client_socket, pr, L)) > 0){
            if(write_len == L)
                break;
            pr += write_len;
            L  -= write_len;
        }
    }

    close(fr);
    if(DEBUG)
        printf("Send well.\n");

    return true;
}

