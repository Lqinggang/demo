#include "common.h"
#include <stdio.h>
#include <string.h>
#include <syslog.h>
#include <errno.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <sys/wait.h>

#define MAXCONNECT       16      /* maximum length to which the queue of pending */
#define BUFFSIZE         4096    /* buff size */
#define MAXSLEEP         512     /* max sleep seconds */
#define PORT             12345   /* port for listen */

void do_listen(int *sockfd) 
{
    *sockfd = -1;
    if((*sockfd =  socket(AF_INET,SOCK_STREAM,0)) < 0) { 
        return;
    }

    struct sockaddr_in addr;
    memset(&addr, 0, sizeof(addr));
    addr.sin_family = AF_INET; //ipv4
    addr.sin_port = htons(PORT); //port 
    addr.sin_addr.s_addr = INADDR_ANY; //addr

    bind(*sockfd, (struct sockaddr *)&addr,sizeof(struct sockaddr)); //bind
    if(listen(*sockfd, MAXCONNECT) < 0) { //listen 
        close(*sockfd);
        *sockfd = -1;
    }
}

ssize_t recv_retry(int sockfd, void *buf, size_t len) 
{
    ssize_t receive_length;
    int numsec;
    for(numsec = 1; numsec < MAXSLEEP; numsec <<= 1) {
        if((receive_length = recv(sockfd, buf, len, MSG_DONTWAIT)) > 0) {
            return receive_length;
        }

        if(numsec <= MAXSLEEP) {
            sleep(numsec);
        }
    }
    errno = ETIMEDOUT;
    return (-1);
}

void handle_request(int sockfd)
{
    struct sockaddr_in addr;
    socklen_t addrlen;
    addrlen = sizeof(addr);
    char dst[64];
    if (getpeername(sockfd, (struct sockaddr *)&addr, &addrlen) < 0) 
    {
        syslog(LOG_ERR, "getpeername errors");
    }
    if(inet_ntop(AF_INET, &addr, dst, sizeof(dst)) < 0) {
        syslog(LOG_ERR, "inet_ntop error");
        strcpy(dst, "unknow");
    }

    syslog(LOG_INFO, "accept: %s", dst);
    ssize_t receive_length; 
    char *buff[BUFFSIZE];
    for(;;) {
        /*
         * Receive data from the client. Don't send 
         * data for a long time, it will time out.
         */
        if(receive_length = recv_retry(sockfd, buff, sizeof(buff)) < 0){
            if(errno == EINTR) {
                continue;
            }
            if(errno == ETIMEDOUT) {
                syslog(LOG_ERR, "time out: %s", dst);
                errno = ETIMEDOUT;
            }
            break;
        }

        /* Data processing.  */
        // TODO

        /* Clear the buff for the next receive data  */
        memset(buff, 0, sizeof(buff));
    }
}
