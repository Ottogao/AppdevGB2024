#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <curl/curl.h>
#include "appdev.h"

int main(void){
    CURL* curl;
    CURLcode res;
    char poststring[200];
    combo c = minmax();     // generate a combo of min/max values
    sprintf(poststring, "min=%d&max=%d", c.min, c.max); // make post string
    curl = curl_easy_init();    // perform curl communication (HTTP post)
    if (curl) {
        curl_easy_setopt(curl, CURLOPT_URL, "http://www.cc.puv.fi/~gc/echo.php");
        curl_easy_setopt(curl, CURLOPT_POSTFIELDS, poststring);
        res = curl_easy_perform(curl);
        if (res != CURLE_OK)
            fprintf(stderr, "curl_easy_perform() failed: %s\n",
                curl_easy_strerror(res));

        curl_easy_cleanup(curl);
    }
    return 0;
}