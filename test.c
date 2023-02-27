#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>

char* read_line(int fd) {
   char* line = NULL;
   char buffer[1];
   size_t line_size = 0;
   ssize_t bytes_read;

   while (1) {
      bytes_read = read(fd, buffer, 1);
      if (bytes_read == -1) {
         perror("read");
         exit(EXIT_FAILURE);
      } else if (bytes_read == 0) {
         break;
      } else {
         if (buffer[0] == '\n') {
            break;
         }

         line_size++;
         char* tmp = realloc(line, line_size);
         if (tmp == NULL) {
            perror("realloc");
            exit(EXIT_FAILURE);
         }
         line = tmp;
         line[line_size - 1] = buffer[0];
      }
   }

   if (line_size == 0 && line == NULL) {
      return NULL;
   }

   line_size++;
   char* tmp = realloc(line, line_size);
   if (tmp == NULL) {
      perror("realloc");
      exit(EXIT_FAILURE);
   }
   line = tmp;
   line[line_size - 1] = '\0';

   return line;
}

int main() {
   int fd;
   char* line;

   fd = open("monfichier.txt", O_RDONLY);
   if (fd == -1) {
      perror("open");
      exit(EXIT_FAILURE);
   }

   while ((line = read_line(fd)) != NULL) {
      printf("%s\n", line);
      free(line);
   }

   close(fd);
   exit(EXIT_SUCCESS);
}