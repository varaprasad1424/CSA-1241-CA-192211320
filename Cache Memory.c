#include <stdio.h>
#include <stdlib.h>

#define CACHE_SIZE 256 
#define MAIN_MEMORY_SIZE 1024 
typedef struct {
    int valid; 
    int tag;  
    int data;  
} CacheBlock;
void accessCache(int address, CacheBlock *cache) {
    int cacheIndex = address % CACHE_SIZE;
    int tag = address / CACHE_SIZE;       
    if (cache[cacheIndex].valid && cache[cacheIndex].tag == tag) {
        printf("Cache hit! Data found at address %d\n", address);
    } else {
        printf("Cache miss! Data not found at address %d\n", address);
        cache[cacheIndex].valid = 1;
        cache[cacheIndex].tag = tag;
        cache[cacheIndex].data = address; 
    }
}
int main() {
    CacheBlock cache[CACHE_SIZE]; 
    int memory[MAIN_MEMORY_SIZE];
	int i;
    for (i = 0; i < CACHE_SIZE; i++) {
        cache[i].valid = 0;
        cache[i].tag = 0;
        cache[i].data = 0;
    }
    for (i = 0; i < MAIN_MEMORY_SIZE; i++) {
        memory[i] = i; 
    }

    int address;
    printf("Enter the memory address to access (0 - %d): ", MAIN_MEMORY_SIZE - 1);
    scanf("%d", &address);
    accessCache(address, cache);

    return 0; 
}

