#include <curl/curl.h>
#include <systemd/sd-bus.h>

#include "ip.h"

int main(int argc, char **argv){
    CURL *curl = curl_easy_init();
    char *prevIp = "";
    char *currentIp = nullptr;
    (void)prevIp;
    (void)currentIp;
    
    curl_easy_cleanup(curl);
    return 0;
}
