#include "monty.h"
stack_t *head = NULL;

/**
 * main - entry point of the code
 * @argc: arguments count
 * @argv: list of arguments
 * Return: always 0 if success
 */

int main(int argc, char *argv[])
{
	if (argc != 2)
	{
		fprintf(stderr, "USAGE: monty file\n");
		exit(EXIT_FAILURE);
	}
	open_file(argv[1]);
	free_nodes();
	return (0);
}

/**
 * create_node - Creates anew  node.
 * @n: Number to go inside the node.
 * Return: Upon sucess a pointer to the node. Otherwise NULL.
 */
stack_t *create_node(int n)
{
	stack_t *node;

	node = malloc(sizeof(stack_t));
	if (node == NULL)
		stack_error(4);
	node->next = NULL;
	node->prev = NULL;
	node->n = n;
	return (node);
}

/**
 * free_nodes - Frees nodes in the stack.
 * Return: Nothing
 */
void free_nodes(void)
{
	stack_t *copy;

	if (head == NULL)
		return;

	while (head != NULL)
	{
		copy = head;
		head = head->next;
		free(copy);
	}
}


/**
 * queue_addnode - Adds a node to the queue.
 * @new_node: Pointer to the new node of the queue
 * @ln: line number of the opcode.
 * Return: Nothing
 */
void queue_addnode(stack_t **new_node, __attribute__((unused))unsigned int ln)
{
	stack_t *copy;

	if (new_node == NULL || *new_node == NULL)
		exit(EXIT_FAILURE);
	if (head == NULL)
	{
		head = *new_node;
		return;
	}
	copy = head;
	while (copy->next != NULL)
		copy = copy->next;

	copy->next = *new_node;
	(*new_node)->prev = copy;

}
