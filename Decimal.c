#include <stdio.h>
long decimalToBinary(int decimal) {
    long binary = 0, base = 1;
    while (decimal > 0) {
        binary += (decimal % 2) * base;
        decimal /= 2;
        base *= 10;
    }
    return binary;
}
int decimalToOctal(int decimal) {
    int octal = 0, base = 1;
    while (decimal > 0) {
        octal += (decimal % 8) * base;
        decimal /= 8;
        base *= 10;
    }
    return octal;
}
void decimalToHexadecimal(int decimal) {
    char hexadecimal[20];
    int i = 0,j;
    while (decimal != 0) {
        int remainder = decimal % 16;
        if (remainder < 10) {
            hexadecimal[i] = remainder + '0';
        } else {
            hexadecimal[i] = remainder + 'A' - 10;
        }
        i++;
        decimal /= 16;
    }
    printf("Hexadecimal: ");
    for (j = i - 1; j >= 0; j--) {
        printf("%c", hexadecimal[j]);
    }
    printf("\n");
}

int main() {
    int decimal;
    printf("Enter a decimal number: ");
    scanf("%d", &decimal);

    long binary = decimalToBinary(decimal);
    int octal = decimalToOctal(decimal);

    printf("Binary: %ld\n", binary);
    printf("Octal: %d\n", octal);
    decimalToHexadecimal(decimal);

    return 0;
}
