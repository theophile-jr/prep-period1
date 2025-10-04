#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

int minCalories(int n, int c1, int c2, int c3) {
    int dp[n + 1];

    dp[0] = 0;
    dp[1] = c1;
    dp[2] = (c1 + c1 < c2) ? (c1 + c1) : c2;

    for (int i = 3; i <= n; i++) {
        int opt1 = dp[i - 1] + c1;
        int opt2 = dp[i - 2] + c2;
        int opt3 = dp[i - 3] + c3; 

        if (opt1 <= opt2 && opt1 <= opt3) {
            dp[i] = opt1;
            printf("Choosing opt1\n");
        } else if (opt2 < opt1 && opt2 < opt3) {
            dp[i] = opt2;
            printf("Choosing opt2\n");

        } else if (opt3 < opt1 && opt3 < opt2) {
            dp[i] = opt3;
            printf("Choosing opt3\n");

        } 
    }
    return dp[n];
}



// int minCalories(int n, int step1, int step2, int step3) {
// //     int weights[3] = {step1, step2, step3};
// //     // Use a larger DP array to handle overshooting
// //     int dp[n + 10]; // Extra space to handle cases where we overshoot
    
//     // Initialize DP array
//     dp[0] = 0;
//     for (int i = 1; i < n + 10; i++) {
//         dp[i] = INT_MAX;
//     }
    
//     // Fill DP table - allow overshooting up to n+max_step
//     for (int i = 1; i < n + 10; i++) {
//         for (int j = 0; j < 3; j++) {
//             if (weights[j] <= i && dp[i - weights[j]] != INT_MAX) {
//                 int candidate = dp[i - weights[j]] + weights[j];
//                 if (candidate < dp[i]) {
//                     dp[i] = candidate;
//                 }
//             }
//         }
//     }

//     // Find the minimum value from n upwards
//     int min_val = INT_MAX;
//     for (int i = n; i < n + 10; i++) {
//         if (dp[i] < min_val) {
//             min_val = dp[i];
//         }
//     }
    
//     return min_val;
// }



//HISS 
// int minCalories(int n, int step1, int step2, int step3) {
//     int steps[3] = {step1, step2, step3};
    
//     // Si n est 0, on a besoin de 0 calories
//     if (n == 0) return 0;
    
//     // Tableau DP : dp[i] = calories minimum pour atteindre i calories
//     int *dp = (int*)malloc((n + 10) * sizeof(int));
    
//     // Initialisation
//     dp[0] = 0;
//     for (int i = 1; i <= n + 9; i++) {
//         dp[i] = INT_MAX;
//     }
    
//     // Remplissage du tableau DP
//     for (int i = 1; i <= n + 9; i++) {
//         for (int j = 0; j < 3; j++) {
//             if (steps[j] <= i) {
//                 if (dp[i - steps[j]] != INT_MAX) {
//                     int new_val = dp[i - steps[j]] + steps[j];
//                     if (new_val < dp[i]) {
//                         dp[i] = new_val;
//                     }
//                 }
//             }
//         }
//     }
    
//     // Trouver la valeur minimum >= n
//     int result = INT_MAX;
//     for (int i = n; i <= n + 9; i++) {
//         if (dp[i] < result) {
//             result = dp[i];
//         }
//     }
    
//     free(dp);
//     return result;
// }


// int minCalories(int n, int step1, int step2, int step3) {
//     int weights[3] = {step1, step2, step3};
//     int steps[n + 1];
//     for (int i = 0; i <= n; i++) {
//         steps[i] = INT_MAX;
//     }
//     steps[0] = 0;
//     for (int i = 0; )
// }






// int main() {
//     printf("%d\n", minCalories(7, 1, 3, 4)); // Should be 7 (1 + 3 + 3 or other combinations)
//     printf("%d\n", minCalories(7, 1, 1, 4)); // Should be 4 (4 itself)
//     return 0;
// }
// #include <stdio.h>
// #include <stdlib.h>
// #include <limits.h>

// int minCalories(int n, int c1, int c2, int c3) {
//     if (n == 0) return 0;
//     if (n == 1) return c1;
//     if (n == 2) return (c1 + c1 < c2 ? c1 + c1 : c2);

//     int dp0 = 0;
//     int dp1 = c1;
//     int dp2 = (c1 + c1 < c2 ? c1 + c1 : c2);
//     int dpi;

//     for (int i = 3; i <= n; i++) {
//         int option1 = dp2 + c1;
//         int option2 = dp1 + c2;
//         int option3 = dp0 + c3;

//         dpi = option1;
//         if (option2 < dpi) dpi = option2;
//         if (option3 < dpi) dpi = option3;

//         dp0 = dp1;
//         dp1 = dp2;
//         dp2 = dpi;
//     }

//     return dp2;
// }



// -------------------------------------------------- GOOD ANSWER TABARNAK --------------------------------------------
// int minCalories(int n, int c1, int c2, int c3) {
//     int dp[n + 1];

//     dp[0] = 0;
//     dp[1] = c1;
//     dp[2] = (c1 + c1 < c2) ? (c1 + c1) : c2;

//     for (int i = 3; i <= n; i++) {
//         dp[i] = dp[i - 1] + c1;
//         int opt2 = dp[i - 2] + c2;
//         int opt3 = dp[i - 3] + c3; 

//         if (opt2 < dp[i]) dp[i] = opt2;
//         if (opt3 < dp[i]) dp[i] = opt3;
//     }
//     return dp[n];
// }



int main() {
    printf("%d\n", minCalories(7, 1, 3, 4)); // Should be 7
    printf("%d\n", minCalories(7, 1, 1, 4)); // Should be 4
    return 0;
}
