#include <stdio.h>
#include <string.h>

static const char *c[] = {"red", "green", "blue"};
static const int t[] = {12, 13, 14};

int main(int argc, char **argv) {
  int m = 0, n = 0;
  char str[256];
  while (fgets(str, sizeof(str), stdin)) {
    int i, p, b = 1;
    printf("%s", str);
    sscanf(str, "Game %d:%n", &i, &p);
    int k = 0;
    char *r[16] = {};
    for (char *s = strtok(str + p, ";"); s; s = strtok(NULL, ";"))
      r[k++] = s;

    int a[] = {0, 0, 0};

    for (int i = 0; i < k; i++)
      for (char *s = strtok(r[i], ","); s; s = strtok(NULL, ",")) {
        int x;
        char q[8];
        sscanf(s, " %d %s", &x, q);
        for (int j = 0; j < 3; j++)
          if (!strcmp(q, c[j]) && x > a[j])
            a[j] = x;
      }

    p = 1;
    for (int i = 0; i < 3; i++) {
      p *= a[i];
      if (a[i] > t[i])
        b = 0;
    }

    m += b * i;
    n += p;
  }
  printf("total possible: %d\n", m);
  printf("minimum power: %d\n", n);
}
