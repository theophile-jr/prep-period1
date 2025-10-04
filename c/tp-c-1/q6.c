#include <stdio.h>
#include <float.h>

int main() {
    printf("Type           Taille (octets)  Min                      Max\n");
    printf("--------------------------------------------------------------\n");

    // float
    printf("float          %zu               %e       %e\n", sizeof(float), FLT_MIN, FLT_MAX);

    // double
    printf("double         %zu               %e       %e\n", sizeof(double), DBL_MIN, DBL_MAX);

    // long double
    printf("long double    %zu               %Le      %Le\n", sizeof(long double), LDBL_MIN, LDBL_MAX);

    return 0;
}

