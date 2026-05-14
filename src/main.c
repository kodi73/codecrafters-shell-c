#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(int argc, char *argv[]) {
  setbuf(stdout, NULL);
  printf("$ ");
  
  char command[100];
  fgets(command, sizeof (command), stdin);
  command[strlen(command) - 1] = '\0';
  printf("%s: command not found", command);
  return 0;
}
