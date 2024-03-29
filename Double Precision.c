#include<stdio.h>
#include<stdint.h>
void print_double_binary(double num)
{
	int i;
	uint64_t *ptr = (uint64_t *)&num; 
	uint64_t mask = 1ULL << 63; 
	printf("Binary representation of %.15lf: ", num);
    for (i = 0; i < 64; i++) {
        printf("%d", (*ptr & mask) ? 1 : 0);
        if (i == 0 || i == 11) 
            printf(" ");
        mask >>= 1; 
    }
    printf("\n");
}
int main() 
{
    double num = 3.141592653589793238; 
    print_double_binary(num); 
    return 0;
}

