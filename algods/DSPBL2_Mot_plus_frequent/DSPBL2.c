#include <stdio.h>
#include <string.h>

static int word_to_index(const char *w) {
    // w is expected to be a 3-char string with letters A..D
    return (w[0] - 'A') * 16 + (w[1] - 'A') * 4 + (w[2] - 'A');
}

static void index_to_word(int idx, char out[4]) {
    int a = idx / 16;       // most significant base-4 digit
    int b = (idx / 4) % 4;  // middle digit
    int c = idx % 4;        // least significant digit
    out[0] = (char)('A' + a);
    out[1] = (char)('A' + b);
    out[2] = (char)('A' + c);
    out[3] = '\0';
}
//!\ fait par chatgpt en préparation de l'exam
int main(void) {
    char line[2049];

    if (fgets(line, sizeof(line), stdin) == NULL) {
        // No input: per examples, output 0 and end.
        printf("0\r\n");
        return 0;
    }

    // Strip trailing CR and LF
    size_t len = strlen(line);
    while (len > 0 && (line[len - 1] == '\n' || line[len - 1] == '\r')) {
        line[--len] = '\0';
    }

    if (len == 0) {
        // Empty line => no words
        printf("0\r\n");
        return 0;
    }

    int counts[64] = {0};

    // Tokenize by '-'
    char *token = strtok(line, "-");
    while (token != NULL) {
        if (strlen(token) == 3) {
            int idx = word_to_index(token);
            if (idx >= 0 && idx < 64) {
                counts[idx]++;
            }
        }
        token = strtok(NULL, "-");
    }

    // Find maximum frequency
    int maxf = 0;
    for (int i = 0; i < 64; ++i) {
        if (counts[i] > maxf) maxf = counts[i];
    }

    // Output
    printf("%d\r\n", maxf);
    if (maxf > 0) {
        for (int i = 0; i < 64; ++i) {
            if (counts[i] == maxf) {
                char w[4];
                index_to_word(i, w);
                printf("%s\r\n", w);
            }
        }
    }

    return 0;
}