#include <stdio.h>
#include <stdlib.h>
#include <winsock2.h>

int main()
{
    printf("Windows Programming - Sockets\n");
    WSADATA ws;
    WSAStartup(MAKEWORD(2,2), &ws);

    SOCKET s; // socket descriptor.
    s = socket(AF_INET, SOCK_STREAM, 0);

    SOCKADDR_IN sa;
    memset(&sa, 0, sizeof(sa));
    sa.sin_family = AF_INET;
    sa.sin_port   = htons(1234);

    // Server - Client; user decide
    char c;
    printf("s server \nk - client\n");
    scanf("%c", c);
    if(c=='c'){
        sa.sin_addr.S_un.S_addr = inet_addr("127.0.0.1");
        connect(s, &sa, sizeof(sa));

        int mas [] = {1,2,3,4,5};
        send(s, mas, sizeof(mas), 0);
    }

    if(c == 's'){
        bind(s, &sa, sizeof(sa));
        listen(s, 100);
        int buf[5];
        memset(buf, 0, sizeof(buf));
        SOCKET client_socket;
        SOCKADDR_IN client_address;
        int client_addr_size = sizeof(client_address);

        while(client_socket = accept(s, &client_address, &client_addr_size)){
            printf("connected\n");
            while( recv(client_socket, buf, sizeof(buf), 0) > 0 ){
                for(int i = 0; i<5; i++){
                    printf("%d\n", buf[i]);
                }
            }
        }
    }

    closesocket(s);

    return 0;
}
