#ifndef IP_CHECK_H
#define IP_CHECK_H
#include <curl/curl.h>

#define DEFAULT_IP_CHECK_SITE "https://icanhazip.com/"

char *get_current_ip(char *checkSite);

#endif
