#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(int argc,char **argv)
{
  char *postfix;
  char res;
  postfix = malloc(strlen(argv[1]));
  res = infix2postfix(argv[1],postfix);
  printf("%s\n",postfix);
  return 0;
}
