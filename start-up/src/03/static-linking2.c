// static-linking.c
#include <stdio.h>

char* add(char*, char*);
int main() {
  printf("2+3=%s\n", add("foo","bar"));
  return 0;
}
