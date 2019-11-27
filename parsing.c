#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
char ** parse_args( char * line ){
  int i=0;
  char *cur=line;
  char ** answer = malloc(sizeof (char *)*6);
  while (cur !=NULL){
    answer[i]=strsep(&cur," ");
    i++;
  }
  answer[i]=NULL;
  return answer;
}
int main(int argc, char const *argv[]) {
  char command[100] = "ls -a -l";
  char ** ans = parse_args( command );
  printf("Testing ls -a -l Command for Current Directory:\n");
  execvp(ans[0], ans);
  return 0;
}
