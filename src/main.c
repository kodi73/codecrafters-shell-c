#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(int argc, char *argv[]) {
  while (true) {
      setbuf(stdout, NULL);
      printf("$ ");
      
      char command[100];
      fgets(command, sizeof (command), stdin);
      command[strlen(command) - 1] = '\0';
      if (strncmp(command, "type ", 5) == 0) {
        if(strcmp(command + 5, "echo") == 0 || strcmp(command + 5, "exit") == 0 || strcmp(command + 5, "type") == 0) {
          printf("%s is a shell builtin\n", command+5);
        }
        else {
          printf("%s: not found\n", command+5);
        }
      }
      else if (strcmp(command, "exit") == 0) {
        break;
      }
      else if (strncmp(command, "echo ", 5) == 0) {
        printf("%s\n", command + 5);
      }
      else
        printf("%s: command not found\n", command);
  }
  return 0;
}
