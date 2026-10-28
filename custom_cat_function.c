#include <stdio.h>
#include <dirent.h>
#include <string.h>
#include <stdlib.h>

int main(int argc, char *argv[]){

  DIR *dir;
  struct dirent *entry;


  if (argc == 1 || argc > 2) {
    printf("list_content [filename with path]\n");
    return 1;
  }
  else {

    for (int i = 0; i < argc; i++) {
      if (i == 1) {
        dir = opendir(".");

        if (dir == NULL) {
          printf("No files in current directory\n");
          return 1;
        }

        while((entry = readdir(dir)) != NULL) {
          if (strcmp(entry->d_name, argv[i]) == 0) {
            FILE *f_ptr;
            char str[1000];
            f_ptr = fopen(argv[i], "r");

            if (f_ptr == NULL) {
              printf("Error in reading file\n");
              return 1;
            }

            if (f_ptr != NULL) {
              while (fgets(str, 1000, f_ptr)) {
                printf("%s", str);
              }
            }

            fclose(f_ptr);
          }
        }

        closedir(dir);

      }
    }
  }

  return 0;
}
