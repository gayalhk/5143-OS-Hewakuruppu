#include <stdlib.h> // NULL
#include <stdio.h>  
#include <dirent.h>

int main(int argc, char* argv[]) {
  const char* path = argc <= 1 ? "." : argv[1];

  DIR* d = opendir(path);
  if (d == NULL) return EXIT_FAILURE;

  for(struct dirent *de = NULL; (de = readdir(d)) != NULL; )
    printf("%s/%s\n", path, de->d_name);

  closedir(d);
  return 0;
}
