#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>

#include <curl/curl.h>
#include <curl/easy.h>
#include <string.h>

#include "ip.h"


static size_t write_to_buffer(char *ptr, size_t size, size_t nmemb, SizedBuffer *userdata){
    if (nmemb > userdata->size - userdata->occupied) {
        return 0;
    }
    strncpy(userdata->buffer + userdata->occupied, ptr, nmemb);
    userdata->occupied += nmemb;
    return nmemb;
}

char *get_current_ip(const char *checkSite, size_t bufferSize, char buffer[bufferSize]){
    if (checkSite == nullptr) {
        checkSite = DEFAULT_IP_CHECK_SITE;
    }

    SizedBuffer sbuffer = {
        .size = bufferSize,
        .occupied = 0,
        .buffer = buffer
    };
    
    auto curl = curl_easy_init();

    curl_easy_setopt(curl, CURLOPT_URL, checkSite);
    curl_easy_setopt(curl, CURLOPT_WRITEFUNCTION, write_to_buffer);
    curl_easy_setopt(curl, CURLOPT_WRITEDATA, &sbuffer);

    CURLcode result = curl_easy_perform(curl);  
    
    if(result !=  CURLE_OK){
        return nullptr;
    }
    
    curl_easy_cleanup(curl); 

    return buffer;
}
