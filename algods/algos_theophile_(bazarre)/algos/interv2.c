#include <stdio.h>
#include <stdlib.h>


int main () {
    int numIntervals = 0;


    scanf("%d", &numIntervals);
    int intervals[numIntervals][2];
    int intervals_res[numIntervals][2];
    int interval_res_num = 0;
    for (int i = 0; i < numIntervals; i++) {
        scanf("%d %d", &intervals[i][0], &intervals[i][1]);
    }

    for (int i = 0; i < numIntervals - 1; i++) {
        for (int j = i + 1; j < numIntervals; j++) {
            if (intervals[i][0] > intervals[j][0]) {
                int tempStart = intervals[i][0];
                int tempEnd = intervals[i][1];
                intervals[i][0] = intervals[j][0];
                intervals[i][1] = intervals[j][1];
                intervals[j][0] = tempStart;
                intervals[j][1] = tempEnd;
            }
        }
    }

    for (int i = 0; i < numIntervals; i++) {
            if (interval_res_num != 0 && intervals[i][0] <= intervals_res[interval_res_num - 1][1]) {
                if (intervals[i][1] > intervals_res[interval_res_num - 1][1]) {
                    intervals_res[interval_res_num - 1][1] = intervals[i][1];
                }
            } else {
                intervals_res[interval_res_num][0] = intervals[i][0];
                intervals_res[interval_res_num][1] = intervals[i][1];
                interval_res_num++;
            }
}


    printf("%d\r\n", interval_res_num);
    for (int i = 0; i < interval_res_num; i++) {
        printf("%d %d\r\n", intervals_res[i][0], intervals_res[i][1]);
    }
}
