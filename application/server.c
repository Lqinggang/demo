#include <stdlib.h>
#include <syslog.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <sys/wait.h>

#include "common.h"
#include "daemonize.h"

int main(int argc,char *argv[])
{
    /* Become a daemon */
    daemonize("server"); 

    /* To listen */
    int sockfd;
    do_listen(&sockfd); 
    if(sockfd < 0) {
        syslog(LOG_ERR, "listen failed");
        return (-1);
    }

    for(;;) {
        /* Accept */
        int clisockfd;
        struct sockaddr_in client_address;
        socklen_t client_address_length;

        if((clisockfd = accept(sockfd, (struct sockaddr *)&client_address, &client_address_length)) < 0) {
            syslog(LOG_ERR, "accept error");
        } else {    /* accept success */

            pid_t pid;
            if((pid = fork()) < 0) {
                syslog(LOG_ERR, "fork error");  
                close(clisockfd);
            } else if(pid == 0) { /* first child */

                close(sockfd);
                if((pid = fork()) < 0) {
                    syslog(LOG_ERR, "fork error");  
                    close(clisockfd);
                } else if(pid > 0) { /* parent from second fork == first child */
                    close(clisockfd);
                    exit(0);
                } 

                /* second child */
                sleep(2);

                /* processing request of client.  */
                handle_request(clisockfd);
                close(clisockfd);
                exit(0);
            } 
            /* parent from first fork */
            close(clisockfd);
            if(waitpid(pid, NULL, 0) != pid) /* wait for first child */
                syslog(LOG_ERR, "whaitpid error");
            //exit(0);
        }

    }
}

