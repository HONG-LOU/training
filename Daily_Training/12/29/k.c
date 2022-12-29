#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int main() {
    FILE *f, *g;
    char word[50];
    char words[100][50];
    int i, j, k = 0;
    f = fopen("sort.in", "r");
    g = fopen("sort.out", "w");
    while (!feof(f)) {
        fscanf(f, "%s", words[k++]);
    }
    rewind(f);
    for (i = 0; i < k; i++) {
        for (j = i + 1; j < k; j++) {
            if (strcmp(words[i], words[j]) > 0) {
                strcpy(word, words[i]);
                strcpy(words[i], words[j]);
                strcpy(words[j], word);
            }
        }

    }
    for (i = 0; i < k; i++) {
        while (strcmp(words[i], words[i + 1]) == 0) {
            i++;
        }
        if (i == k - 1) {
            fprintf(g, "%s", words[i]);
        }
        else {
            fprintf(g, "%s ", words[i]);
        }
    }
    fclose(f);
    fclose(g);
    return 0;
}
