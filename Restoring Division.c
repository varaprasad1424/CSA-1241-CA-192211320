#include <stdio.h>
#include <string.h>
#define N 8 
void restoring_division(int dividend[], int divisor[], int quotient[]) {
    int partial_remainder[N+1];
    int borrow = 0;
    int i, j;
    memset(partial_remainder, 0, sizeof(partial_remainder));
    for (i = 0; i < N; i++) {
        for (j = N; j > 0; j--)
            partial_remainder[j] = partial_remainder[j - 1];
        partial_remainder[0] = dividend[i];
        for (j = 0; j < N+1; j++) {
            partial_remainder[j] -= divisor[j];
            if (partial_remainder[j] < 0) {
                partial_remainder[j] += 2;
                partial_remainder[j+1] -= 1;
            }
        }
        quotient[i] = (partial_remainder[0] >= 0) ? 1 : 0;
        if (partial_remainder[0] < 0) {
            for (j = 0; j < N+1; j++) {
                partial_remainder[j] += divisor[j];
            }
        }
    }
}
int main() {
    int dividend[N] = {1, 1, 0, 1, 0, 1, 0, 1}; 
    int divisor[N] = {1, 0, 1, 1, 0, 0, 1, 0};  
    int quotient[N];
    int i;
    restoring_division(dividend, divisor, quotient);
    printf("Quotient: ");
    for (i = 0; i < N; i++) {
        printf("%d", quotient[i]);
    }
    printf("\n");
    return 0;
}

