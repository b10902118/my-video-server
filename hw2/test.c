#include <stdio.h>
#include <stdlib.h>
#include <string.h>
int main(int argc, char **argv) {
    printf("%d", sizeof("1234567"));
    exit(0);
    char s[] = "cdefabab";
    char *p = strtok(s, "ab");
    printf("p: '%s'\n", p);
    p = strtok(NULL, "ab");
    printf("p: '%s'\n", p);

    for (int i = 0; i < sizeof(s); ++i) printf("%c", s[i]);

    return 0;
}