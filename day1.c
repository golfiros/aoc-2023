#include <stdio.h>

static const char *d[] = {
    "zero", "one", "two",   "three", "four",
    "five", "six", "seven", "eight", "nine",
};

int main(int argc, char **argv) {
  int m = 0, n = 0;
  char str[256];
  while (fgets(str, sizeof(str), stdin)) {
    char *l;
    for (l = str; *l < '0' || *l > '9'; l++)
      ;
    char *r;
    for (r = l; *r != '\n'; r++)
      ;
    for (; *r < '0' || *r > '9'; r--)
      ;
    int a = *l - '0', b = *r - '0';
    m += 10 * a + b;
    for (; l >= str; l--)
      for (int i = 0; i < sizeof(d) / sizeof(*d); i++) {
        int c = 1;
        for (int j = 0; c && d[i][j]; j++)
          c = l[j] == d[i][j];
        if (c)
          a = i;
      }
    for (; *r != '\n'; r++)
      for (int i = 0; i < sizeof(d) / sizeof(*d); i++) {
        int c = 1;
        for (int j = 0; c && d[i][j]; j++)
          c = r[j] == d[i][j];
        if (c)
          b = i;
      }
    n += 10 * a + b;
  }
  printf("old values: %d\n", m);
  printf("new values: %d\n", n);
}
