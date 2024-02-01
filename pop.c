#include "monty.h"
void pop(stack_t **stk, unsigned int line_number)
{
stack_t *temp;	
    if (!*stk)
    {
        fprintf(stderr, "L%d: can't pop an empty stack\n", line_number);
        exit(EXIT_FAILURE);
    }
    temp = *stk;
    *stk = (*stk)->next;
    if (*stk)
        (*stk)->prev = NULL;
    free(temp);
}

