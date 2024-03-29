#include <stdio.h>
#include <string.h>
#include <math.h>
int hexadecimalToDecimal(char hexadecimal[]) {
    int decimal = 0, length = strlen(hexadecimal), base = 1,i;
    for (i = length - 1; i >= 0; i--) {
        if (hexadecimal[i] >= '0' && hexadecimal[i] <= '9') {
            decimal += (hexadecimal[i] - '0') * base;
        } else if (hexadecimal[i] >= 'A' && hexadecimal[i] <= 'F') {
            decimal += (hexadecimal[i] - 'A' + 10) * base;
        }
        base *= 16;
    }
    return decimal;
}
long hexadecimalToBinary(char hexadecimal[]) {
    int decimal = hexadecimalToDecimal(hexadecimal);
    long binary = 0, base = 1;
    while (decimal > 0) {
        binary += (decimal % 2) * base;
        decimal /= 2;
        base *= 10;
    }
    return binary;
}
int hexadecimalToOctal(char hexadecimal[]) {
    int decimal = hexadecimalToDecimal(hexadecimal);
    int octal = 0, base = 1;
    while (decimal > 0) {
        octal += (decimal % 8) * base;
        decimal /= 8;
        base *= 10;
    }
    return octal;
}
int main() {
    char hexadecimal[20];
    printf("Enter a hexadecimal number: ");
    scanf("%s", hexadecimal);
    long binary = hexadecimalToBinary(hexadecimal);
    int octal = hexadecimalToOctal(hexadecimal);
    int decimal = hexadecimalToDecimal(hexadecimal);
    printf("Binary: %ld\n", binary);
    printf("Octal: %d\n", octal);
    printf("Decimal: %d\n", decimal);
    return 0;
}
