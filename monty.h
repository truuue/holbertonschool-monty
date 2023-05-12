#ifndef MONTY_H
#define MONTY_H

#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include <unistd.h>
#include <string.h>

/**
 * struct stack_s - doubly linked list representation of a stack (or queue)
 * @n: integer
 * @prev: points to the previous element of the stack (or queue)
 * @next: points to the next element of the stack (or queue)
 *
 * Description: doubly linked list node structure
 * for stack, queues, LIFO, FIFO
 */
typedef struct stack_s
{
	int n;
	struct stack_s *prev;
	struct stack_s *next;
} monty_stack_t;

/**
 * struct instruction_s - opcode and its function
 * @opcode: the opcode
 * @f: function to handle the opcode
 *
 * Description: opcode and its function
 * for stack, queues, LIFO, FIFO
 */
typedef struct instruction_s
{
	char *opcode;
	void (*f)(monty_stack_t **stack, unsigned int line_number);
} instruction_t;

int global_status;

void copy_and_cut(char *line, unsigned int line_nb, monty_stack_t **stack);
void (*get_ops(char *token))(monty_stack_t **stack, unsigned int number);
void push(monty_stack_t **stack, unsigned int number);
void pall(monty_stack_t **stack, unsigned int number);
void free_stack(monty_stack_t **stack);
int _isdigit(int c);
void close_free(char *line, int fd, FILE *file, monty_stack_t *head);
void print_err(char *msg);
void print_err2(unsigned int line_nb, char *cmd, char *line_cpy);
int check_digit(char *cmd, char *argument, unsigned int line_nb,
char *line_cpy);
void pint(monty_stack_t **stack, unsigned int line_nb);
void pop(monty_stack_t **stack, unsigned int line_nb);
void nop(monty_stack_t **stack, unsigned int line_nb);
void swap(monty_stack_t **stack, unsigned int line_nb);
void add(monty_stack_t **stack, unsigned int line_nb);
void sub(monty_stack_t **stack, unsigned int line_nb);
void _div(monty_stack_t **stack, unsigned int line_nb);

#endif
