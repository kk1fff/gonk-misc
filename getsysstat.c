#include <stdio.h>
#include <sys/types.h>
#include <dirent.h>

int main (void)
{
  DIR *dp;
  struct dirent *ep;
  char filename[100];
  char line[300];
  int pid, l;
  FILE *f;

  dp = opendir ("/proc/");

  if (dp != NULL) {
    while (ep = readdir (dp)) {
      if (sscanf(ep->d_name, "%d", &pid) == 1) {
        sprintf(filename, "/proc/%d/stat", pid);
        f = fopen(filename, "r");
        while (fgets(line, 300, f) != NULL) {
          printf("%s", line);
        }
        fclose(f);
      }
    }

    (void) closedir (dp);
  } else {
    perror ("Couldn't open the directory");
  }

  return 0;
}
