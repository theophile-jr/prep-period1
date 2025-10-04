#include <stdio.h>
#include <string.h>
#include <stdbool.h>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <stdbool.h>
#include <stdlib.h>

typedef struct file_s {
    int content[100];
    int front;
    int rear;
} file_t;

bool queue(file_t *file, int val) {
    if ((file->rear + 1) % 100 == file->front)    //  if (file->count == 100) retfakse
        return false;
    file->content[file->rear] = val;
    file->rear = (file->rear + 1) % 100; //if 100 then to zero (modulo reste truc)
    return true;
}

int dequeue(file_t *file) {
    if (file->front == file->rear) {  // if count == 0 en soit ;) 
        return -1;
    }
    int res = file->content[file->front];
    file->front = (file->front + 1) % 100;
    return res;
}

int main() {
    file_t file;
    file.front = 0;
    file.rear = 0;
    
    char buffer[1000];
    do {
        scanf("%s", buffer);
        int val;
        if (strcmp(buffer, "queue") == 0) {
            scanf("%d", &val);
            queue(&file, val);
        } else if (strcmp(buffer, "dequeue") == 0) {
            val = dequeue(&file);
            if (val != -1) {
                printf("%d\r\n", val);
            }
        }
    } while (strcmp(buffer, "bye") != 0);
        
    return 0;
}

/*
#include <stdio.h>
#include <string.h>
#include <stdbool.h>

typedef struct file_s {
    int content[100];
    int front;
    int rear;
    int count;
} file_t;

bool queue(file_t *file, int val) {
    if (file->count == 100) 
        return false;
    file->content[file->rear] = val;
    file->rear++;
    if (file->rear == 100) file->rear = 0;
    file->count++;
    return true;
}

int dequeue(file_t *file) {
    if (file->count == 0) return -1;
    int res = file->content[file->front];
    file->front++;
    if (file->front == 100) file->front = 0;
    file->count--;
    return res;
}

int main() {
    file_t file = { .front = 0, .rear = 0, .count = 0 };
    char buffer[1000];
    int val;

    while (scanf("%s", buffer) == 1) {
        if (strcmp(buffer, "queue") == 0) {
            scanf("%d", &val);
            queue(&file, val);
        } else if (strcmp(buffer, "dequeue") == 0) {
            val = dequeue(&file);
            if (val != -1) printf("%d\n", val);
        } else if (strcmp(buffer, "bye") == 0) {
            break;
        }
    }

    return 0;
}
*/