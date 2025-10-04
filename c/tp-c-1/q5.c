#include <stdio.h>
#include <limits.h>

#include <stdio.h>
#include <limits.h>

int main() {
    printf("Type                  Taille (octets)  Min                 Max\n");
    printf("---------------------------------------------------------------\n");

    // char
    printf("char                  %zu               %d                  %d\n", sizeof(char), CHAR_MIN, CHAR_MAX);
    printf("unsigned char         %zu               0                  %u\n", sizeof(unsigned char), UCHAR_MAX);

    // short
    printf("short                 %zu               %d                  %d\n", sizeof(short), SHRT_MIN, SHRT_MAX);
    printf("unsigned short        %zu               0                  %u\n", sizeof(unsigned short), USHRT_MAX);

    // int
    printf("int                   %zu               %d                  %d\n", sizeof(int), INT_MIN, INT_MAX);
    printf("unsigned int          %zu               0                  %u\n", sizeof(unsigned int), UINT_MAX);

    // long
    printf("long                  %zu               %ld      %ld\n", sizeof(long), LONG_MIN, LONG_MAX);
    printf("unsigned long         %zu               0      %lu\n", sizeof(unsigned long), ULONG_MAX);

    // long long
    printf("long long             %zu               %lld  %lld\n", sizeof(long long), LLONG_MIN, LLONG_MAX);
    printf("unsigned long long    %zu               0      %llu\n", sizeof(unsigned long long), ULLONG_MAX);

    return 0;
}

