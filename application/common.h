#ifndef APPLICATION_COMMON_H
#define APPLICATION_COMMON_H

#include <sys/types.h>

extern void do_listen(int *sockfd);
extern ssize_t recv_retry(int sockfd, void *buf, size_t len);
extern void handle_request(int sockfd);

#endif  /* APPLICATION_COMMON_H */
