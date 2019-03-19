#ifndef BASE64_H
#define BASE64_H

#include <stddef.h>

extern unsigned char *base64_encode(const unsigned char *source, size_t source_size, unsigned char *dst, size_t dst_size);
extern unsigned char *base64_decode(const unsigned char *source, size_t source_size, unsigned char *dst, size_t *dst_size);

#endif
