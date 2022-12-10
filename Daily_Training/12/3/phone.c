#include <stdio.h>
#include <string.h>

struct per {
  char name[30];
  char phone[20];
}p[101010];

int main () {
  int n, c;
  scanf ("%d %d", &n, &c);
  for (int i = 0; i < n; i++) {
    scanf ("%s %s", &p[i].name, &p[i].phone);
  }
  for (int i = 0; i < n - 1; i++) {
    for (int j = i + 1; j < n; j++) {
      if (strcmp(p[i].name, p[j].name) == 1) {
        char temp[30];
        strcpy(temp, p[i].name);
        strcpy(p[i].name, p[j].name);
        strcpy(p[j].name, temp);
        strcpy(temp, p[i].phone);
        strcpy(p[i].phone, p[j].phone);
        strcpy(p[j].phone, temp);
      }
    }
  }
  int cnt = 0;
  if (c == 1) {
    printf ("%s ", p[0].name);
    for (int i = 1; i < n; i++) {
      if (p[i].name == p[i - 1].name) {
        printf ("%s_%c ", p[i].name, (char) (cnt + 'a'));
        cnt++;
      }
      else {
        printf ("%s ", p[i].name);
        cnt = 0;
      }
    }
  }
  printf ("\n");
  cnt = 0;
  printf ("%s %s\n", p[0].name, p[0].phone);
  for (int i = 1; i < n; i++) {
    if (strcmp(p[i].name, p[i - 1].name) == 0) {
      printf ("%s_%c ", p[i].name, (char ) (cnt + 'a'));
      cnt++;
    }
    else {
      printf ("%s ", p[i].name);
      cnt = 0;
    }
    printf ("%s\n", p[i].phone);
  }
  return 0;
}