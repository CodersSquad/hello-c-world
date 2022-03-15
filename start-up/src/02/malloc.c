#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main() {
    char *q = NULL;

    printf("Requesting space for \"Goodbye\"\n");
    q = (char *)malloc(strlen("Goodbye")+1);
    printf("About to copy \"Goodbye\" to q at address %p\n", q);
    strcpy(q, "Goodbye");
    printf("String copied\n");
    printf("%s\n", q);

    return 0;

}
