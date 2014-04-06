#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>

int main(int argc, char** argv) {
  void *m;
  int len = 6291456; // 6MB
  if (argc > 1) {
    len = atoi(argv[1]);
  }
  printf("Take %d byte of memory\n", len);
  m = malloc(len * sizeof(char));

  while(1) {
    void* p = m;
    while (p < m + len) {
      *((char*)p) = 1;
      p += 4096;
    }
    sleep(1);
  }
  return 0;
}
