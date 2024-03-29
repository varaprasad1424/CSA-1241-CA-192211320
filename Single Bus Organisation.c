#include <stdio.h>
typedef struct {
    int data;
    int address;
} Bus;
typedef struct {
     Bus *bus;
} CPU;
typedef struct {
    Bus *bus;
    int data[100]; 
} Memory;
int memory_read(Memory *mem, int address) {
    return mem->data[address];
}
void memory_write(Memory *mem, int address, int data) {
    mem->data[address] = data;
}
int cpu_operation(CPU *cpu, int address) {
    return memory_read(cpu->bus, address);
}
int main() {
    Bus system_bus;
    CPU cpu;
    Memory memory;
    cpu.bus = &system_bus;
    memory.bus = &system_bus;
    memory_write(&memory, 0, 10); 
    int data_read = cpu_operation(&cpu, 0);
    printf("Data read by CPU: %d\n", data_read);
    return 0;
}
