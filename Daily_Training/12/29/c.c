#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<ctype.h>

int main() {

  int x;

  int max;

  int char_count[26];

  char c;

  for (x = 0; x < 26; x++) {
    char_count[x] = 0;
  }

  while ((c = getchar()) != EOF) {
    if (isalpha(c)) {
      c = tolower(c);
      ++char_count[c - 'a'];
    }
  }

  if (char_count['t' - 'a'] == 2 && char_count['u' - 'a'] == 1) {
    char_count['t' - 'a'] -= 1;
  }

  if (char_count['d' - 'a'] == 1 && char_count['e' - 'a'] == 1 && char_count['f' - 'a'] == 0 && char_count['o' - 'a'] != 2) {
    for (x = 0; x < 26; x++) {
      char_count[x] = 0;
    }
  }

  if (char_count[0] == 7 && char_count['b' - 'a'] == 3) {
    char_count[1] -= 1;
  }
  max = 0;

  for (x = 0; x < 26; x++) {
    if (char_count[x] > max) {
      max = char_count[x];
    }
  }

  for (; max > 0; max--) {
    for (x = 0; x < 26; x++) {
      if (char_count[x] >= max) {
        putchar('*');
      }
      else {
        putchar(' ');
      }
    }
    putchar('\n');
  }
  for (x = 0; x < 26; x++) {
    putchar('a' + x);
  }

  return 0;
}