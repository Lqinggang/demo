/****************************************
  > File Name: main.c
  > Author: lqinggang
  > Email: 1944058861@qq.com
  > Create Time: Thu 17 Jan 2019 06:00:25 PM CST
 ****************************************/

#include "app.h"

extern void daemonize(const char *cmd);
int main(int argc,char *argv[])
{
    /*
     * Become a daemon
     */
    daemonize("appserver"); 
    int sockfd;
    /*
     * To listen.
     */
    dolisten(&sockfd); 
    if(sockfd < 0) {
        syslog(LOG_ERR, "[APP] listen failed");
        return (-1);
    }
    syslog(LOG_INFO, "[APP] listen start");
    for(;;) {
        /*
         * Accept 
         */
        struct sockaddr_in cliaddr;
        socklen_t addrlen;
        int clisockfd;
        if((clisockfd = accept(sockfd, (struct sockaddr *)&cliaddr, &addrlen)) < 0) {
            syslog(LOG_ERR, "[APP] accept error");
        } else {    /* accept success */
            pid_t pid;
            if((pid = fork()) < 0) {
                syslog(LOG_ERR, "[APP] fork error");  
                close(clisockfd);
            } else if(pid == 0) { /* first child */
                close(sockfd);
                if((pid = fork()) < 0) {
                    syslog(LOG_ERR, "[APP] fork error");  
                    close(clisockfd);
                } else if(pid > 0) { /* parent from second fork == first child */
                    close(clisockfd);
                    exit(0);
                } 

                /* second child */
                sleep(2);
                /*
                 * processing request of client.
                 */
                procerequest(clisockfd);
                close(clisockfd);
                exit(0);
            } 
            /* parent from first fork */
            close(clisockfd);
            if(waitpid(pid, NULL, 0) != pid) /* wait for first child */
                syslog(LOG_ERR, "[APP] whaitpid error");
            //exit(0);
        }

    }
}

