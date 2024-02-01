#include "monty.h"
#include <string.h>
FILE *file;
stack_t *global_stack = NULL;
int main(int argc, char *argv[]) {
char opcode[100]; 
char arg_str[20]; 
unsigned int line_number = 0;

    if (argc != 2) {
        fprintf(stderr, "USAGE: monty file\n");
        exit(EXIT_FAILURE);
    }

    file = fopen(argv[1], "r");
    if (!file) {
        fprintf(stderr, "Error: Can't open file %s\n", argv[1]);
        exit(EXIT_FAILURE);
    }

    

    while (fscanf(file, "%s %s", opcode, arg_str) != EOF) {
        line_number++;
        
        if (strcmp(opcode, "push") == 0) {
            push(&global_stack, arg_str, line_number);
        } else if (strcmp(opcode, "pall") == 0) {
            pall(&global_stack, line_number);
        } else if (strcmp(opcode, "pint") == 0) {
            pint(&global_stack, line_number);
        } else if (strcmp(opcode, "pop") == 0) {
            pop(&global_stack, line_number);
        } else if (strcmp(opcode, "swap") == 0) {
            swap(&global_stack, line_number);
        } else {
            fprintf(stderr, "L%d: unknown instruction: %s\n", line_number, opcode);
            exit(EXIT_FAILURE);
        }
    }

    
    fclose(file);

    return EXIT_SUCCESS;
}
