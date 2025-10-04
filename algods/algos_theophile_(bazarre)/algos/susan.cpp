#include <stdio.h>

int main () {
    int R,E,D,S,U,A,N;

    for (int R = 1; R <= 9; R++) {
        for (int E = 0; E <= 9; E++) {
            for (int D = 1; D <= 9; D++) {
                for (int S = 1; S <= 9; S++) {
                    for (int U = 0; U <= 9; U++) {
                        for (int A = 0; A <= 9; A++) {
                            for (int N = 0; N <= 9; N++) {
                                if (R != E && R != D && R != S && R != U && R != A && R != N &&
                                    E != D && E != S && E != U && E != A && E != N &&
                                    D != S && D != U && D != A && D != N &&
                                    S != U && S != A && S != N &&
                                    U != A && U != N && A != N) {
                                    if ((R * 100 + E * 10 + D) + (D * 1000 + E * 100 + E*10 + R) == (S * 10000 + U * 1000 + S * 100 + A * 10 + N)) {
                                        printf("%d%d%d%d%d\r\n", S, U, S, A, N);
                                    }
                                }
                            }
                        }
                    }
                }
            }
        }
    }
}   