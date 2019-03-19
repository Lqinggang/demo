#include <stdio.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <fcntl.h>
#include <unistd.h>
#include <string.h>

#include "base64.h"

#define MODE   (S_IWUSR | S_IRUSR | S_IWGRP | S_IRGRP) 

#define BEFORE_ENCODE_FILE  "before_encode.file"
#define BEFORE_DECODE_FILE  "before_decode.file"
#define AFTER_ENCODE_FILE   "after_encode.file"
#define AFTER_DECODE_FILE   "after_decode.file"

static int
read_data_from_file(const char *file_path, unsigned char *data, size_t *data_size)
{
   /*read the data from  before_encode.file for encode */
    int fd;
    if ((fd = open(file_path, O_RDONLY)) == -1)
    {
        printf("can't open file: %s\n", file_path);
        return (-1);
    }

    /* get the file size */
    struct stat st;
    fstat(fd, &st);

    if (st.st_size >= *data_size)
    {
        printf("not enough space for read\n");
        return (-2);
    }

    /* read the data */
    int nread = 0;
    int read_index = 0;
    while ((nread = read(fd, data + read_index, st.st_size - read_index) != 0)
        && nread != -1 )
    {
        read_index += nread;
    }
    *data_size = st.st_size;

    close(fd);
    return (0);
}

static int 
write_to_file(const char *file_path, const unsigned char *data, size_t data_size)
{
    int fd;
    if ((fd = open(file_path, O_WRONLY | O_CREAT | O_TRUNC, MODE)) == -1)
    {
        printf("can't open file: %s\n", file_path);
        return (-1);
    } 

    int nwrite = 0;
    int write_index = 0;
    while ((nwrite = write(fd, data + write_index, data_size - write_index)) != 0 
        && nwrite != -1)
    {
        write_index += nwrite;
    }

    close(fd);
    return (0);
}

static void
to_encode(void)
{
    /* get the file data */
    char data_buff[128] = { '\0' };
    size_t data_length = sizeof(data_buff);
    if (read_data_from_file(BEFORE_ENCODE_FILE, data_buff, &data_length) < 0)
    {
        printf("read the data from file error: %s\n", BEFORE_ENCODE_FILE);
        return ;
    }

    /* encode */
    char encode[128] = { '\0' };
    size_t encode_length = sizeof(encode);
    base64_encode(data_buff, data_length, encode, encode_length);

    /* write to file */
    if (write_to_file(AFTER_ENCODE_FILE, encode, strlen(encode)) != 0)
    {
        printf("write to file error\n");
    }

}

static void
to_decode(void)
{
    /* get the file data */
    char data_buff[128] = { '\0' };
    size_t data_length = sizeof(data_buff);
    if (read_data_from_file(BEFORE_DECODE_FILE, data_buff, &data_length) < 0)
    {
        printf("read the data from file error: %s\n", BEFORE_DECODE_FILE);
        return ;
    }

    /* decode */
    char decode[128] = { '\0' };
    size_t decode_length = sizeof(decode);
    base64_decode(data_buff, data_length, decode, &decode_length);

    /* write to file */
    if (write_to_file(AFTER_DECODE_FILE, decode, decode_length) != 0)
    {
        printf("write to file error\n");
    }

}

int main(void)
{

    to_encode();
    to_decode();

    return (0);
}
