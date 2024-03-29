#include <stdio.h>
int octalToDecimal(int octal) {
    int decimal = 0, base = 1, rem;
    while (octal > 0) {
        rem = octal % 10;
        decimal += rem * base;
        octal /= 10;
        base *= 8;
    }
    return decimal;
}

long decimalToBinary(int decimal) {
    long binary = 0, base = 1;
    while (decimal > 0) {
        binary += (decimal % 2) * base;
        decimal /= 2;
        base *= 10;
    }
    return binary;
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
    int octal;
    printf("Enter an octal number: ");
    scanf("%d", &octal);

    int decimal = octalToDecimal(octal);
    long binary = decimalToBinary(decimal);

    printf("Decimal: %d\n", decimal);
    printf("Binary: %ld\n", binary);
    decimalToHexadecimal(decimal);

    return 0;
}
