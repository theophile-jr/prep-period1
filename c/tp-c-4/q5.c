#include <stdio.h>


int main (int ac, char **argv) {
    FILE *ptr = fopen(argv[1], "r");

    FILE *ptr2 = fopen(argv[2], "w");
    while (!feof(ptr)) {
        char c = fgetc(ptr);
        if (c == EOF) break;
        // printf("%c", c);
        // fputc(c, stdout);

        fputc(c, ptr2);
    }
    return 0;
}
