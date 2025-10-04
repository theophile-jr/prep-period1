#include <stdio.h>
int main() {
int average;
int grades[10];
grades[0] = 85;
grades[1] = 85;
grades[2] = 85;
average = (grades[0] + grades[1] + grades[2]) / 3;
printf("The average of the 3 grades is: %d", average);
return 0;
}
