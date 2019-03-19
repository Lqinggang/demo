#include "base64.h"

static unsigned char *BASE = "ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz0123456789+/";

unsigned char *
base64_encode(const unsigned char *source, size_t source_size, unsigned char *dst, size_t dst_size)
{
    if (source == NULL || dst == NULL)
    {
        return (NULL);
    }

    int i;
    int index = 0;
    for (i = 0; i < source_size &&  index < dst_size; i += 3)
    {
        unsigned char c0 = source[i];
        unsigned char c1 = (i + 1 >= source_size)? 0 : source[i + 1];
        unsigned char c2 = (i + 2 >= source_size)? 0 : source[i + 2];

        dst[index++] = BASE[ (c0 >> 2) & 0x3F ];
        if (index > dst_size) break;

        dst[index++] = BASE[ ((c0 << 4) & 0x30) | ((c1 >> 4) & 0x0F) ];
        if (index > dst_size) break;

        dst[index++] = BASE[ ((c1 << 2) & 0x3C) | ((c2 >> 6) & 0x03) ];
        if (index > dst_size) break;

        dst[index++] = BASE[ c2  & 0x3F ]; 
    }

    switch (source_size % 3)
    {
        case 1:
            dst[index - 1] = '=';
        case 2:
            dst[index - 2] = '=';
    }

    return (dst);
}

unsigned char *
base64_decode(const unsigned char *source, size_t source_size, unsigned char *dst, size_t *dst_size)
{
    if (source == NULL || dst == NULL)
    {
        return (NULL);
    }

    int i;
    unsigned int to_int[128] = { -1 };
    for (i = 0; i < 64; i++)
    {
        to_int[BASE[i]] = i;
    }

    int index = 0;
    for (i = 0; i < source_size && index < *dst_size; i += 4)
    {
        unsigned char c0 = to_int[ source[i] ];
        unsigned char c1 = to_int[ source[i + 1] ];

        dst[index++] = (((c0 << 2) & 0xFC) | ((c1 >> 4) & 0x03));
        if (index > *dst_size) break;

        unsigned char c2 = to_int[ source[i + 2] ];
        dst[index++] = (((c1 << 4) & 0xF0) | ((c2 >> 2) & 0x0F));
        if (index > *dst_size) break;

        unsigned char c3 = to_int[ source[i + 3] ];
        dst[index++] = (((c2 << 6) & 0xC0) | (c3  & 0x3F));
    }

    if (source[source_size -1] == '=')
    {
        index--;
    }
    if (source[source_size -2] == '=')
    {
        index--;
    }

    *dst_size = index; 
//    dst_size[index] = '\0';
    return (dst);
}
