#include "monty.h"
void add(stack_t **stk, unsigned int line_number) {
int result;
    if (!*stk || !(*stk)->next) {
        fprintf(stderr, "L%d: can't add, stack too short\n", line_number);
        exit(EXIT_FAILURE);
    }

    /* Calculate the sum of the top two elements */
    result = (*stk)->n + (*stk)->next->n;

    /* Update the value of the second top element with the result */
    (*stk)->next->n = result;

    /* Remove the top element from the stack */
    pop(stk, line_number);
}

