#ifndef MONTY_H
#define MONTY_H

#define _GNU_SOURCE
#include <stdio.h>
#include <unistd.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>
#include <stdarg.h>

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
} stack_t;

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
        void (*f)(stack_t **stack, unsigned int line_number);
} instruction_t;

extern stack_t *head;
typedef void (*op_func)(stack_t **, unsigned int);

/*file operations*/
void ta_open_file(char *file_name);
int ta_parse_linee(char *buffer, int line_number, int format);
void ta_read_file(FILE *);
int len_chars(FILE *);
void ta_find_function(char *, char *, int, int);

/*Stack operations*/
stack_t *create_node(int n);
void ta_free_nodes(void);
void printe_stakee(stack_t **, unsigned int);
void ade_too_stak(stack_t **, unsigned int);
void ta_add_to_queu(stack_t **, unsigned int);

void ta_call_me_funny(op_func, char *, char *, int, int);

void printee_topp(stack_t **, unsigned int);
void poope_toope(stack_t **, unsigned int);
void nooop(stack_t **, unsigned int);
void swapee_nodees(stack_t **, unsigned int);

/*Math operations with nodes*/
void addes_noudes(stack_t **, unsigned int);
void subi_nodees(stack_t **, unsigned int);
void diva_nuudes(stack_t **, unsigned int);
void moules_noodes(stack_t **, unsigned int);
void mood_noodes(stack_t **, unsigned int);

/*String operations*/
void ta_print_char(stack_t **, unsigned int);
void ta_print_str(stack_t **, unsigned int);
void rotala(stack_t **, unsigned int);

/*Error hanlding*/
void erroor(int error_code, ...);
void more_erroor(int error_code, ...);
void stringe_erroor(int error_code, ...);
void rotard(stack_t **, unsigned int);

#endif
