#include <stdio.h>
typedef struct {
    int opcode;
    int operand1;
    int operand2;
} Instruction;
typedef struct {
    Instruction instruction;
    int result;
} PipelineRegister;
void fetch_stage(int *instruction_count, Instruction *current_instruction) {
    (*instruction_count)++;
    current_instruction->opcode = (*instruction_count) % 3;
    current_instruction->operand1 = (*instruction_count) * 2;
    current_instruction->operand2 = (*instruction_count) * 2 + 1;
}
void decode_stage(Instruction *current_instruction, PipelineRegister *decode_reg) {
    decode_reg->instruction = *current_instruction;
}
void execute_stage(PipelineRegister *decode_reg, PipelineRegister *execute_reg) {
    switch (decode_reg->instruction.opcode) {
        case 0:
            execute_reg->result = decode_reg->instruction.operand1 + decode_reg->instruction.operand2;
            break;
        case 1:
            execute_reg->result = decode_reg->instruction.operand1 - decode_reg->instruction.operand2;
            break;
        case 2:
            execute_reg->result = decode_reg->instruction.operand1 * decode_reg->instruction.operand2;
            break;
        default:
            printf("Invalid opcode\n");
            break;
    }
}
void writeback_stage(PipelineRegister *execute_reg) {
    printf("Result: %d\n", execute_reg->result);
}
int main() {
    int instruction_count = 0;
    Instruction current_instruction;
    PipelineRegister decode_reg, execute_reg;
    int i;
    for (i = 0; i < 5; i++) { 
        fetch_stage(&instruction_count, &current_instruction);
        decode_stage(&current_instruction, &decode_reg);
        execute_stage(&decode_reg, &execute_reg);
        writeback_stage(&execute_reg);
        printf("Cycle %d: Instruction Opcode = %d, Operand1 = %d, Operand2 = %d\n",
               i + 1, current_instruction.opcode, current_instruction.operand1, current_instruction.operand2);
    }
    return 0;
}
