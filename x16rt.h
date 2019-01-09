#ifndef X16RT_H
#define X16RT_H

#define TIME_MASK 0xffffff80

#ifdef __cplusplus
extern "C" {
#endif

#include <stdint.h>

void x16rt_hash(const char* input, char* output);
void sha256d(unsigned char *hash, const unsigned char *data, int len); //sha2.c

#ifdef __cplusplus
}
#endif

#endif
