#include <stdio.h>
#include <string.h>
#include <stdbool.h>
#include <stdlib.h>

typedef struct word_s {
    int freq;
    char *str;
} word;

int main () {
    char buffer[2048 + 1];
    int i, k, precise_count;  // Declare loop variables here for C89
    scanf("%s", buffer);

    int words_count_large = 0;
    for (i = 0; buffer[i] != '\0'; i++)
        if (buffer[i] == '-') words_count_large++; 

    word words[words_count_large];

    char *ptr = buffer;
    precise_count = 0;
    while (*ptr != '\0') {
        if (*ptr == '-') {
            ptr++;
        }
        char tmp[4];
        tmp[0] = ptr[0];
        tmp[1] = ptr[1];
        tmp[2] = ptr[2];
        tmp[3] = '\0';

        bool cut = false;
        for (k = 0; k < precise_count; k++) {
            if (strcmp(words[k].str,tmp) == 0) {
                words[k].freq++;
                cut = true;
            }
        }
        if (cut) {
            ptr += 3;
            continue;
        }

        words[precise_count].freq = 1;
        words[precise_count].str = strdup(tmp);
        ptr += 3;
        precise_count++;
    }

    int maxfreq = 0;
    for (i = 0 ; i < precise_count; i++) {
        if (words[i].freq > maxfreq)
            maxfreq = words[i].freq;
    }

    /* Selection sort, proper C89 style */
    int min_idx;
    word tmp_word;
    for (i = 0; i < precise_count - 1; i++) {
        min_idx = i;
        for (k = i + 1; k < precise_count; k++) {
            if (strcmp(words[k].str, words[min_idx].str) < 0)
                min_idx = k;
        }
        if (min_idx != i) {
            tmp_word = words[i];
            words[i] = words[min_idx];
            words[min_idx] = tmp_word;
        }
    }
    printf("%d\r\n", maxfreq);
    for (i = 0; i < precise_count; i++) {
        if (words[i].freq == maxfreq) {
            printf("%s\r\n", words[i].str);
        }
    }

    /* Free allocated memory */
    for (i = 0; i < precise_count; i++) free(words[i].str);


    return 0;
}
