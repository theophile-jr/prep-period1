#include <stdio.h>

int main () {
    int posx = 0;
    int posy = 0;
    int diry = 0;
    int dirx = 1;

    char buffer[101];
    scanf("%100s", buffer);
    for (int i = 0; buffer[i] != '\0'; i++) {
        if (buffer[i] == 'A') {
            posx += dirx;
            posy += diry;
        } else if (buffer[i] == 'D') {
            if (dirx == 1 && diry == 0) {
                diry = 1;
                dirx = 0;
            }
            else if (dirx == 0 && diry == 1) {
                diry = 0;
                dirx = -1;
            }
            else if (dirx == -1 && diry == 0) {
                diry = -1;
                dirx = 0;
            }
            else if (dirx == 0 && diry == -1) {
                diry = 0;
                dirx = 1;
            }
        } else if (buffer[i] == 'G') {
            if (dirx == 1 && diry == 0) {
                diry = -1;
                dirx = 0;
            }
            else if (dirx == 0 && diry == -1) {
                diry = 0;
                dirx = -1;
            }
            else if (dirx == -1 && diry == 0) {
                diry = 1;
                dirx = 0;
            }
            else if (dirx == 0 && diry == 1) {
                diry = 0;
                dirx = 1;
            }
        }
    }
    printf("%d\r\n", posx);
    printf("%d\r\n", posy);
    return 0;
}

/* good 
#include <stdio.h>

int main () {
    int posx = 0;
    int posy = 0;
    int diry = 0;
    int dirx = 1;

    char buffer[101];  // 101 pour inclure le '\0'
    scanf("%100s", buffer);  // pas de & devant buffer
    
    for (int i = 0; buffer[i] != '\0'; i++) {
        if (buffer[i] == 'A') {
            posx += dirx;
            posy += diry;
        } else if (buffer[i] == 'D') {
            if (dirx == 1 && diry == 0) {
                diry = 1;
                dirx = 0;
            }
            else if (dirx == 0 && diry == 1) {
                diry = 0;
                dirx = -1;
            }
            else if (dirx == -1 && diry == 0) {
                diry = -1;
                dirx = 0;
            }
            else if (dirx == 0 && diry == -1) {
                diry = 0;
                dirx = 1;
            }
        } else if (buffer[i] == 'G') {
            if (dirx == 1 && diry == 0) {
                diry = -1;
                dirx = 0;
            }
            else if (dirx == 0 && diry == -1) {
                diry = 0;
                dirx = -1;
            }
            else if (dirx == -1 && diry == 0) {
                diry = 1;
                dirx = 0;
            }
            else if (dirx == 0 && diry == 1) {
                diry = 0;
                dirx = 1;
            }
        }
    }
    printf("%d\n", posx);
    printf("%d\n", posy);
    return 0;
}*/