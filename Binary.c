#include <stdio.h>
#include <math.h>
int binaryToDecimal(long long binary) {
    int decimal = 0, i = 0, remainder;
    while (binary != 0) {
        remainder = binary % 10;
        binary /= 10;
        decimal += remainder * pow(2, i);
        ++i;
    }
    return decimal;
}
int main() {
    long long binary;
    printf("Enter a binary number: ");
    scanf("%lld", &binary);
    int choice;
    printf("Choose conversion: \n");
    printf("1. Decimal\n");
    printf("2. Octal\n");
    printf("3. Hexadecimal\n");
    printf("Enter your choice: ");
    scanf("%d", &choice);
    switch (choice) {
        case 1:
            printf("Decimal: %d\n", binaryToDecimal(binary));
            break;
        case 2: {
            int decimal = binaryToDecimal(binary);
            long long octal = 0;
            int i = 1;
            while (decimal != 0) {
                octal += (decimal % 8) * i;
                decimal /= 8;
                i *= 10;
            }
            printf("Octal: %lld\n", octal);
            break;
        }
        case 3: {
            int decimal = binaryToDecimal(binary);
            char hexadecimal[20];
            int i = 0,j;
            while (decimal != 0) {
                int remainder = decimal % 16;
                if (remainder < 10)
                    hexadecimal[i++] = remainder + 48;
                else
                    hexadecimal[i++] = remainder + 55;
                decimal /= 16;
            }
            printf("Hexadecimal: ");
            for (j = i - 1; j >= 0; j--)
                printf("%c", hexadecimal[j]);
            printf("\n");
            break;
        }
        default:
            printf("Invalid choice.\n");
    }

    return 0;
}
