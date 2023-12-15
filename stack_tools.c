#include "monty.h"

/**
 * open_file - opens a file containing the stack
 * @fn: the file namepath of the stack
 * Return: void
 */

void open_file(char *fn)
{
	FILE *fd = fopen(fn, "r");

	if (fn == NULL || fd == NULL)
		stack_error(2, fn);

	read_file(fd);
	fclose(fd);
}


/**
 * read_file - reads a file
 * @fd: pointer to file descriptor of the opened file
 * Return: void
 */

void read_file(FILE *fd)
{
	int line_number, format = 0;
	char *buffer = NULL;
	size_t len = 0;

	for (line_number = 1; getline(&buffer, &len, fd) != -1; line_number++)
	{
		format = parse_line(buffer, line_number, format);
	}
	free(buffer);
}


/**
 * parse_line - Separates each line into tokens to determine
 * which function to call
 * @line_flag: line from the file
 * @line_number: line number
 * @format:  storage format. If 0 Nodes will be entered as a stack.
 * if 1 nodes will be entered as a queue.
 * Return: Returns 0 if the opcode is stack. 1 if queue. on success.
 */

int parse_line(char *line_flag, int line_number, int format)
{
	char *opcode, *value;
	const char *delim = "\n ";

	if (line_flag == NULL)
		stack_error(4);

	opcode = strtok(line_flag, delim);
	if (opcode == NULL)
		return (format);
	value = strtok(NULL, delim);

	if (strcmp(opcode, "stack") == 0)
		return (0);
	if (strcmp(opcode, "queue") == 0)
		return (1);

	find_func(opcode, value, line_number, format);
	return (format);
}

/**
 * find_func - find the appropriate function for the opcode
 * @opcode: opcode
 * @value: argument of opcode
 * @format:  storage format. If 0 Nodes will be entered as a stack.
 * @ln: line number
 * if 1 nodes will be entered as a queue.
 * Return: void
 */
void find_func(char *opcode, char *value, int ln, int format)
{
	int j;
	int flag;

	instruction_t func_list[] = {
		{"push", stack_addnode},
		{"pall", print_stack},
		{"pint", stack_top},
		{"pop", stack_pop_top},
		{"nop", stack_nop},
		{"swap", stack_swap},
		{"add", stack_add},
		{"sub", stack_sub},
		{"div", stack_div},
		{"mul", stack_mul},
		{"mod", stack_mod},
		{"pchar", prt_char},
		{"pstr", prt_str},
		{"rotl", stack_rotl},
		{"rotr", stack_rotr},
		{NULL, NULL}
	};

	if (opcode[0] == '#')
		return;

	for (flag = 1, j = 0; func_list[j].opcode != NULL; j++)
	{
		if (strcmp(opcode, func_list[j].opcode) == 0)
		{
			func_call(func_list[j].f, opcode, value, ln, format);
			flag = 0;
		}
	}
	if (flag == 1)
		stack_error(3, ln, opcode);
}


/**
 * func_call - Calls the required function.
 * @func: Pointer to the function that is about to be called.
 * @op: string representing the opcode.
 * @val: string representing a numeric value.
 * @ln: line numeber for the instruction.
 * @format: Format specifier. If 0 Nodes will be entered as a stack.
 * if 1 nodes will be entered as a queue.
 */
void func_call(op_func func, char *op, char *val, int ln, int format)
{
	stack_t *node;
	int flag;
	int k;

	flag = 1;
	if (strcmp(op, "push") == 0)
	{
		if (val != NULL && val[0] == '-')
		{
			val = val + 1;
			flag = -1;
		}
		if (val == NULL)
			stack_error(5, ln);
		for (k = 0; val[k] != '\0'; k++)
		{
			if (isdigit(val[k]) == 0)
				stack_error(5, ln);
		}
		node = create_node(atoi(val) * flag);
		if (format == 0)
			func(&node, ln);
		if (format == 1)
			queue_addnode(&node, ln);
	}
	else
		func(&head, ln);
}
