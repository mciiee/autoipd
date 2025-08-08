#ifndef IP_CHECK_H
#define IP_CHECK_H
#include <curl/curl.h>

typedef struct SizedBuffer {
    size_t size;
    size_t occupied;
    char *buffer;
} SizedBuffer;

constexpr char DEFAULT_IP_CHECK_SITE[] = "https://icanhazip.com/";


[[maybe_unused]]
char *get_current_ip(const char *checkSite, size_t bufferSize, char buffer[bufferSize]);
#endif
