#include <stdio.h>

typedef struct {
    int x;
    int y;
    int o;
} robot;

int main(void) {

    robot r;
    r.x = 0;
    r.y = 0;
    r.o = 1;

    char cmd[101];
    scanf("%s", cmd);
    int i = 0;
    while (cmd[i] != '\0') {
        //printf("%d %d %d\n", r.x, r.y, r.o);
        switch (cmd[i++]) {
            case 'A':
                switch (r.o) {
                    case 0:
                        r.y--;
                        break;
                    case 1:
                        r.x++;
                        break;
                    case 2:
                        r.y++;
                        break;
                    case 3:
                        r.x--;
                        break;
                }
                break;
            case 'D':
                r.o = (r.o + 1) % 4;
                break;
            case 'G':
                r.o = (r.o + 3) % 4;
                break;
        }
    }

    printf("%d\r\n", r.x);
    printf("%d\r\n", r.y);
    return 0;
}