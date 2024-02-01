#include "monty.h"
void swap(stack_t **stk, unsigned int line_number) {
   int temp; 
    stack_t *top;
    stack_t *second;
   if (!*stk || !(*stk)->next) {
        fprintf(stderr, "L%d: can't swap, stack too short\n", line_number);
        exit(EXIT_FAILURE);
    }

    /* Find the top two elements of the stack */
    top = *stk;
    second = top->next;

    /* Swap the values of the top two elements */
    temp = top->n;
    top->n = second->n;
    second->n = temp;
}
