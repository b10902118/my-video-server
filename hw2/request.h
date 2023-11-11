#pragma once

//#include <string>
#include <cstring>
#include "utils.h"

const int MAXHEADER = 1024;
const int MAXHEADER_LEN = 1024;
const int MAXURI_LEN = 1024;
const int GET = 0;
const int POST = 1;
const int INVALID = 2;

struct Request {
    int type;
    bool closed;
    // string?
    char URI[MAXHEADER_LEN];

} request;
void parse_request(char *request) {
    // Split the request into lines
    char *request_line = strtok(request, "\n"); // containing \r
    char *s;
    for (n_header = 0; (s = strtok(NULL, "\n")) != NULL && *s != '\r';
         ++n_header) {
        strncpy(headers[n_header], s, MAXHEADER_LEN);
        // headers[i][MAXHEADER_LEN] = '\0';
        // headers[strlen(header[i])-1] = '\0'; // \r -> \0
    }

    if (request_line) {
        // Parse the request line
        char *method = strtok(request_line, " ");
        if (strcmp("GET", method) == 0) type = 0;
        else if (strcmp("POST", method) == 0) type = 1;
        char *tmp_uri = strtok(NULL, " ");
        if (tmp_uri == NULL) {
            puts("url is null");
            ERR_EXIT("strtok");
        }
        strncpy(URI, tmp_uri, MAXHEADER_LEN);
        char *http_version = strtok(NULL, " \r");
        if (strcmp(http_version, "HTTP/1.1") != 0) {
            puts("http version incorrect");
        }

        // Print the parsed values
        printf("Method: %s\n", method);
        printf("URI: %s\n", URI);
        printf("HTTP Version: %s\n", http_version);
    }
}
