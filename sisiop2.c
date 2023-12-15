#include "monty.h"

/**
 * ta_open_file - opens a file
 * @file_name: the file namepath
 * Return: void
 */

void ta_open_file(char *file_name)
{
	FILE *fd = fopen(file_name, "r");

	if (file_name == NULL || fd == NULL)
		err(2, file_name);

	ta_read_file(fd);
	fclose(fd);
}


/**
 * ta_read_file - reads a file
 * @fd: pointer to file descriptor
 * Return: void
 */

void ta_read_file(FILE *fd)
{
	int blanki, tfoo = 0;
	char *buffer = NULL;
	size_t len = 0;

	for (blanki = 1; getline(&buffer, &len, fd) != -1; blanki++)
	{
		tfoo = ta_parse_linee(buffer, blanki, tfoo);
	}
	free(buffer);
}


/**
 * ta_parse_linee - Separates each line into tokens to determine
 * which function to call
 * @buffer: line from the file
 * @blanki: line number
 * @tfoo:  storage tfoo. If 0 Nodes will be entered as a stack.
 * if 1 nodes will be entered as a queue.
 * Return: Returns 0 if the opcode is stack. 1 if queue.
 */

int ta_parse_linee(char *buffer, int blanki, int tfoo)
{
	char *opcode, *value;
	const char *delim = "\n ";

	if (buffer == NULL)
		err(4);

	opcode = strtok(buffer, delim);
	if (opcode == NULL)
		return (tfoo);
	value = strtok(NULL, delim);

	if (strcmp(opcode, "stack") == 0)
		return (0);
	if (strcmp(opcode, "queue") == 0)
		return (1);

	ta_find_function(opcode, value, blanki, tfoo);
	return (tfoo);
}

/**
 * ta_find_function - find the appropriate function for the opcode
 * @opcode: opcode
 * @value: argument of opcode
 * @tfoo:  storage tfoo. If 0 Nodes will be entered as a stack.
 * @ln: line number
 * if 1 nodes will be entered as a queue.
 * Return: void
 */
void ta_find_function(char *opcode, char *value, int ln, int tfoo)
{
	int i;
	int yawili;

	instruction_t func_list[] = {
		{"push", ade_too_stak},
		{"pall", printe_stakee},
		{"pint", printee_topp},
		{"pop", poope_toope},
		{"nop", nooop},
		{"swap", swapee_nodees},
		{"add", addes_noudes},
		{"sub", subi_nodees},
		{"div", diva_nuudes},
		{"mul", moules_noodes},
		{"mod", mood_noodes},
		{"pchar", ta_print_char},
		{"pstr", ta_print_str},
		{"rotl", rotala},
		{"rotr", rotard},
		{NULL, NULL}
	};

	if (opcode[0] == '#')
		return;

	for (yawili = 1, i = 0; func_list[i].opcode != NULL; i++)
	{
		if (strcmp(opcode, func_list[i].opcode) == 0)
		{
			ta_call_me_funny(func_list[i].f, opcode, value, ln, tfoo);
			yawili = 0;
		}
	}
	if (yawili == 1)
		err(3, ln, opcode);
}


/**
 * ta_call_me_funny - Calls the required function.
 * @func: Pointer to the function that is about to be called.
 * @op: string representing the opcode.
 * @val: string representing a numeric value.
 * @ln: line numeber for the instruction.
 * @tfoo: tfoo specifier. If 0 Nodes will be entered as a stack.
 * if 1 nodes will be entered as a queue.
 */
void ta_call_me_funny(op_func func, char *op, char *val, int ln, int tfoo)
{
	stack_t *node;
	int yawili;
	int i;

	yawili = 1;
	if (strcmp(op, "push") == 0)
	{
		if (val != NULL && val[0] == '-')
		{
			val = val + 1;
			yawili = -1;
		}
		if (val == NULL)
			err(5, ln);
		for (i = 0; val[i] != '\0'; i++)
		{
			if (isdigit(val[i]) == 0)
				err(5, ln);
		}
		node = create_node(atoi(val) * yawili);
		if (tfoo == 0)
			func(&node, ln);
		if (tfoo == 1)
			add_to_queue(&node, ln);
	}
	else
		func(&head, ln);
}
