#include <stdio.h>
typedef struct {
    int opcode;
    int operand1;
    int operand2;
} Instruction;
void fetch_stage(int *instruction_count, Instruction *instruction_buffer) {
    (*instruction_count)++;
    instruction_buffer->opcode = (*instruction_count) % 3;
    instruction_buffer->operand1 = (*instruction_count) * 2;
    instruction_buffer->operand2 = (*instruction_count) * 2 + 1;
}
void execute_stage(Instruction *instruction_buffer, int *result) {
    switch (instruction_buffer->opcode) {
        case 0:
            *result = instruction_buffer->operand1 + instruction_buffer->operand2;
            break;
        case 1:
            *result = instruction_buffer->operand1 - instruction_buffer->operand2;
            break;
        case 2:
            *result = instruction_buffer->operand1 * instruction_buffer->operand2;
            break;
        default:
            printf("Invalid opcode\n");
            break;
    }
}
int main() {
    int instruction_count = 0;
    Instruction current_instruction;
    int execution_result;
    int i;
    for (i = 0; i < 5; i++) { 
        fetch_stage(&instruction_count, &current_instruction);
        execute_stage(&current_instruction, &execution_result);
        printf("Cycle %d: Result = %d\n", i + 1, execution_result);
    }
    return 0;
}
