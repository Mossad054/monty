#include "monty.h"

void push(stack_t **stk, const char *input, unsigned int line_number)
{
    int num;
    stack_t *node;
    if (sscanf(input, "%d", &num) != 1) {
        fprintf(stderr, "L%d: usage: push integer\n", line_number);
        exit(EXIT_FAILURE);
    }
    node = malloc(sizeof(stack_t));
    if (!node) {
        fprintf(stderr, "Error: malloc failed\n");
        exit(EXIT_FAILURE);
    }
    node->n = num;
    node -> next = *stk;
    *stk = node;
}

void pall(stack_t **stk, unsigned int line_number)
{
stack_t *recent = *stk;
while (recent)
{
printf("%d\n", recent -> n);
recent = recent->next;
}
(void)line_number;
}
