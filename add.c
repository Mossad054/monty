#include "monty.h"
void add(stack_t **stk, unsigned int line_number) {
int result;
    if (!*stk || !(*stk)->next) {
        fprintf(stderr, "L%d: can't add, stack too short\n", line_number);
        exit(EXIT_FAILURE);
    }

    
    result = (*stk)->n + (*stk)->next->n;

  
    (*stk)->next->n = result;

      pop(stk, line_number);
}

