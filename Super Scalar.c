#include <stdio.h>
int add(int a, int b) {
    return a + b;
}
int subtract(int a, int b) {
    return a - b;
}
int main() {
    int a = 5;
    int b = 10;
    int c, d;
    c = add(a, b);
    d = subtract(a, b);
    printf("Result of addition: %d\n", c);
    printf("Result of subtraction: %d\n", d);
    return 0;
}

