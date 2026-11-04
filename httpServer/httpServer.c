#include <stdio.h>
#include <sys/socket.h>

int main(){
    printf("Starting world\n");
    int soc = socket(AF_INET,SOCK_STREAM,0);
    printf("%d\n", soc);
}
