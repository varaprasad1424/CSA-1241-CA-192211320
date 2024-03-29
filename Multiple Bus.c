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
typedef struct {
    Bus *bus;
} IO_Device;
int memory_read(Memory *mem, int address) {
    return mem->data[address];
}
void memory_write(Memory *mem, int address, int data) {
    mem->data[address] = data;
}
int cpu_operation(CPU *cpu, Memory *mem, int address) {
    return memory_read(mem, address);
}
void io_device_operation(IO_Device *device, Memory *mem, int address, int data) {
    memory_write(mem, address, data);
}
int main() {
    Bus data_bus;
    Bus io_bus;
    CPU cpu;
    Memory memory;
    IO_Device io_device;
    cpu.bus = &data_bus;
    memory.bus = &data_bus;
    io_device.bus = &io_bus;
    memory_write(&memory, 0, 10); 
    int data_read = cpu_operation(&cpu, &memory, 0);
    printf("Data read by CPU: %d\n", data_read);
    io_device_operation(&io_device, &memory, 1, 20);
    data_read = cpu_operation(&cpu, &memory, 1);
    printf("Data read by CPU after I/O operation: %d\n", data_read);
    return 0;
}
