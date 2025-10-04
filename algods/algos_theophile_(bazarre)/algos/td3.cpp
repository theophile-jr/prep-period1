#include <stdio.h>
#include <math.h>

int main()
{
	int A, B;
	scanf("%d", &A);
	scanf("%d", &B);
    int foundone = 0;
    for (int x= 0; x < sqrt(A); x++)  {
        for (int y = 0; y < sqrt(A); y++) {
            if ((pow(x,2) + pow(y,2)) == A && (pow(x,3) + pow(y,3)) == B) {
                printf("%d %d\r\n", x, y);
                foundone = 1;
            }
        }
    }
    if (foundone == 0) {
        printf("-\r\n");
    }
	return 0;
}
