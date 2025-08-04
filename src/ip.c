#include <curl/curl.h>
#include <curl/easy.h>
#include <stdint.h>

#include "ip.h"



char *get_current_ip(char *checkSite){
    if (checkSite == nullptr) {
        checkSite = DEFAULT_IP_CHECK_SITE;
    }

    auto curl = curl_easy_init(); 

    curl_easy_setopt(curl, CURLOPT_URL, checkSite);
    CURLcode result = curl_easy_perform(curl);
    
    if(result !=  CURLE_OK){
        return nullptr;
    }

    return nullptr;
}
