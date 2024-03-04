#include <windows.h>
#include <stdio.h>
#include <string.h>

typedef struct student {
  char name[20];
  int e;
  int m;
  int c;
  int total;
} STU;

STU s[1010];

void SortByTotal (STU *stu, int n);

void SortByEnglish (STU *stu, int n);

void Output (STU stu[], int n);

char h[5][12] = {"Name", "English", "Math", "C", "Total"};

int main () {
  freopen("student.txt", "r", stdin);

  int num = 0;

  while (scanf("%s %d %d %d", s[num].name, &s[num].e, &s[num].m, &s[num].c) != EOF) {
    s[num].total = s[num].e + s[num].m + s[num].c;
    num++;
  }


  fclose(stdin);

  int i;

  SetConsoleOutputCP(65001);

  Output(s, num);

  SortByTotal(s, num);

  Output(s, num);

  SortByEnglish(s, num);

  Output(s, num);

  return 0;
}

void SortByTotal (STU *stu, int n) {
  int i, j;
  for (i = 0; i < n; i++) {
    for (j = i + 1; j < n; j++) {
      if (stu[j].total > stu[i].total) {
        STU cnt;
        strcpy(cnt.name, s[j].name);
        cnt.total = stu[j].total;
        cnt.e = stu[j].e;
        cnt.m = stu[j].m;
        cnt.c = stu[j].c;
        stu[j] = stu[i];
        stu[i] = cnt;
      }
    }
  }
}

void SortByEnglish (STU *stu, int n) {
  int i, j;
  for (i = 0; i < n; i++) {
    for (j = i + 1; j < n; j++) {
      if (stu[j].e > stu[i].e) {
        STU cnt;
        strcpy(cnt.name, s[j].name);
        cnt.total = stu[j].total;
        cnt.e = stu[j].e;
        cnt.m = stu[j].m;
        cnt.c = stu[j].c;
        stu[j] = stu[i];
        stu[i] = cnt;
      }
    }
  }
}

void Output (STU stu[], int n) {
  int i;
  for (i = 0; i < 5; i++) {
    printf("%-12s", h[i]);
  }
  printf("\n");

  for (i = 0; i < n; i++) {
    int j;
    int zh = 0;
    for (j = 0; j < strlen(stu[i].name); j++) {
      if (!isalpha(stu[i].name[j])) {
        zh += 1;
      }
    }
    zh /= 3;
    printf ("%s", stu[i].name);
    int len = strlen(stu[i].name);
    if (!isalpha(stu[i].name[0])) {
      len /= 3;
    }
    for (j = 0; j < 12 - len - zh; j++) {
      printf(" ");
    }

    printf("%-12d%-12d%-12d%-12d\n", stu[i].e, stu[i].m, stu[i].c, stu[i].total);
  }
}