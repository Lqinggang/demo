#include <arpa/inet.h>

static int
is_2_nth_power(unsigned int value)
{
    if ((netmask & (netmask - 1)) == 0)
    {
        return (0);
    }
    return (-1);
}


/*
 * check netmask
 * if value is a netmask, return 0, otherwise, return -1.
 */
int
check_netmask(const char *value)
{
    /* check if the value is an IPv4 address */
    struct in_addr ip_addr;
    if (inet_pton(AF_INET, value, &ip_addr) != 1)
    {
        return (-1);
    }

    unsigned int ip[4];
    if (sscanf(value, "%u.%u.%u.%u", &ip[0], &ip[1], &ip[2], &ip[3]) != 4)
    {
        return (-1);
    }

    /* int type must be 32-bits */
    int i;
    unsigned int netmask;
    for (i = 0; i < 4; i++)
    {
        netmask <<= 8;
        netmask |= (ip[i] & 0xFF);
    }
    netmask = ~netmask + 1;
    return (is_2_nth_power(netmask));
}
