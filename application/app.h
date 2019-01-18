/****************************************
   > File Name: app.h
   > Author: lqinggang
   > Email: 1944058861@qq.com
   > Create Time: Thu 17 Jan 2019 06:01:53 PM CST
****************************************/

#ifndef APP_H
#define APP_H

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <errno.h>
#include <syslog.h>
#include <sys/socket.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <netinet/in.h>
#include <arpa/inet.h>

#define MAXCONNECT       16      /* maximum length to which the queue of pending */
#define BUFFSIZE         4096    /* buff size */
#define MAXSLEEP         512     /* max sleep seconds */
#define PORT             12345   /* port for listen */

//struct keyval_t
//{
//	char kv_key[64];
//	char kv_value[64];
//};
//struct interface_t
//{
//	char in_config[64]; //network, wireless....
//    char in_section[64]; //lan, wan....
//	struct keyval_t in_keyval[32];
//    size_t in_count;
//};
//

//int getconttent(char *desstr);

void dolisten(int *sockfd);
ssize_t recv_retry(int sockfd, void *buf, size_t len);
int separate(const char *sepstr, char *srcstr, char *desstr[], int len);
void procerequest(int sockfd);

#endif
