#include <stdio.h>

int main () {
    int num = 0;
    scanf("%d", &num);

    int sum_posi = 0;
    int sum_nega = 0;
    int num_posi = 0;
    int num_nega = 0;

    for (int i = 0; i < num; i++) {
        int tmp;
        scanf("%d", &tmp);
        if (tmp > 0) {
            sum_posi += tmp;
            num_posi++;
        }
        else if (tmp < 0) {
            sum_nega += (-tmp); // FLIP THE SIGN 
            num_nega++;
        }
    }

    if (num_posi == 0 && num_nega == 0) {
        printf("p\r\n");
    } else if (num_posi == 0) {
        printf("n\r\n");
    } else if (num_nega == 0) {
        printf("p\r\n");
    } else {
        double avg_pos = (double)sum_posi / num_posi;
        double avg_neg = (double)sum_nega / num_nega;
        if (avg_pos >= avg_neg) {
            printf("p\r\n");
        } else {
            printf("n\r\n");
        }
    }
    
    return 0;
}