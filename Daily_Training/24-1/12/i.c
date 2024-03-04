#include <stdio.h>
#include <string.h>

char s[1010][60];

int main () {
  freopen("in.txt", "r", stdin);

  int num = 0;
  while (scanf("%s", s[num]) != EOF) {
    num++;
  }

  int i, j;

  fclose(stdin);

  for (i = 0; i < num; i++) {
    int len = strlen(s[i]);
    int dev = 0;

    char l[60], r[60];
    int has = 0;
    for (j = 1; j < len - 1; j++) {
      if (s[i][j] == '\'') {
        has = 1;
        int k;
        for (k = 0; k < j; k++) {
          l[k] = s[i][k];
        }
        for (k = j + 1; k < len; k++) {
          r[k - j - 1] = s[i][k];
        }
      }
    }
    if (has) {
      strcpy(s[i], l);
      strcpy(s[num], r);
      num++;
    }
  }

  for (i = 0; i < num; i++) {
    char cnt[60] = "";
    int length = 0;
    for (j = 0; j < strlen(s[i]); j++) {
      if (s[i][j] >= 'A' && s[i][j] <= 'Z') {
        s[i][j] += ('a' - 'A');
      }
      if (s[i][j] > 'z' || s[i][j] < 'a') {
        continue;
      }
      cnt[length] = s[i][j];
      length += 1;
    }
    strcpy(s[i], cnt);
  }

  for (i = 0; i < num; i++) {
    for (j = i + 1; j < num; j++) {
      if (strcmp(s[i], s[j]) == 1) {
        char cnt[60] = "";
        strcpy(cnt, s[j]);
        strcpy(s[j], s[i]);
        strcpy(s[i], cnt);
      }
    }
  }

  for (i = 0; i < num; i++) {
    int has = 0;
    for (j = 0; j < i; j++) {
      if (strcmp(s[j], s[i]) == 0) {
        has = 1;
        continue;
      }
    }
    if (has == 0) printf("%s\n", s[i]);
  }

  return 0;
}