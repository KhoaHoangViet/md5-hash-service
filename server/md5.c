#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <openssl/md5.h>

int main()
{
  char string[10000];
  FILE *from, *to;
  int i;
  unsigned char result[MD5_DIGEST_LENGTH];
  from = fopen("receive.txt", "rt");
  if (from == NULL)
  {
    perror("receive.txt doesn't exist.");
    exit(1);
  }

  to = fopen("output.txt", "wt");
  if (to == NULL)
    {
      perror("output.txt doesn't exist.");
      exit(1);
    }
  fgets(string, 10000, from);

  //remove last newline character
  size_t ln = strlen(string) - 1;
  if (*string && string[ln] == '\n')
      string[ln] = '\0';

  MD5(string, strlen(string), result);

  // output
  for(i = 0; i < MD5_DIGEST_LENGTH; i++)
    fprintf(to,"%02x", result[i]);
  fclose(to);
  fclose(from);
  return EXIT_SUCCESS;
}
