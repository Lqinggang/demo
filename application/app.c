/****************************************
  > File Name: app.c
  > Author: lqinggang
  > Email: 1944058861@qq.com
  > Create Time: Thu 17 Jan 2019 06:01:38 PM CST
 ****************************************/

#include "app.h"

int separate(const char *sepstr, char *srcstr, char *desstr[], int len)
{
    int count=0;
    char *p;
    p = strtok(srcstr,sepstr); 
    while(p!=NULL) { 
        desstr[count] = p;
        p = strtok(NULL,sepstr); 
        count++;
        if(count >= len)
            break;	
    }
    return count;
}

int getconttent(char *desstr)
{
    int len = 0;;
    char *lenstr;
    lenstr=(char*)getenv("CONTENT_LENGTH");
    if(lenstr == NULL) { //null 
        return (-1); 
    } else {
        len=atoi(lenstr);
        fgets(desstr, len + 1, stdin);//save to str
    }
    return len;
}


void dolisten(int *sockfd) 
{
    *sockfd = -1;
    if((*sockfd =  socket(AF_INET,SOCK_STREAM,0)) < 0) { 
        return;
    }

    struct sockaddr_in addr;
    bzero(&addr,sizeof(addr));
    addr.sin_family = AF_INET; //ipv4
    addr.sin_port = htons(PORT); //port 
    addr.sin_addr.s_addr = INADDR_ANY; //addr

    bind(*sockfd, (struct sockaddr *)&addr,sizeof(struct sockaddr)); //bind
    if(listen(*sockfd, MAXCONNECT) < 0) { //listen 
        close(*sockfd);
        *sockfd = -1;
    }
}

int Accept(int sockfd, struct sockaddr *addr, socklen_t *addrlen)
{
    if(accept(sockfd, addr, addrlen) < 0) {
        printf("accept error\n");
        return -1;
    }
    return 0;
}

ssize_t recv_retry(int sockfd, void *buf, size_t len) 
{
    ssize_t recvlen;
    int numsec;
    for(numsec = 1; numsec < MAXSLEEP; numsec <<= 1) {
        if((recvlen = recv(sockfd, buf, len, MSG_DONTWAIT)) > 0) {
            return recvlen;
        }

        if(numsec <= MAXSLEEP) {
            sleep(numsec);
        }
    }
    errno = ETIMEDOUT;
    return (-1);
}



void procerequest(int sockfd)
{
    struct sockaddr_in addr;
    socklen_t addrlen;
    addrlen = sizeof(addr);
    char dst[64];
    if(getpeername(sockfd, (struct sockaddr *)&addr, &addrlen) < 0) {
        syslog(LOG_ERR, "getpeername errors");
    }
        if(inet_ntop(AF_INET, &addr, dst, sizeof(dst)) < 0) {
            syslog(LOG_ERR, "inet_ntop error");
            strcpy(dst, "unknow");
        }

    syslog(LOG_INFO, "accept: %s", dst);
    ssize_t recvlen; 
    char *buff[BUFFSIZE];
    for(;;) {
        /*
         * Receive data from the client. Don't send 
         * data for a long time, it will time out.
         */
        if(recvlen = recv_retry(sockfd, buff, sizeof(buff)) < 0){
            if(errno == EINTR) {
                continue;
            }
            if(errno == ETIMEDOUT) {
                syslog(LOG_ERR, "Time out: %s", dst);
                errno = ETIMEDOUT;
            }
            break;
        }

        /*
         * Data processing.
         */

        /*
         * Clear the buff for the next receive data. 
         */
        memset(buff, 0, sizeof(buff));
    }
}


