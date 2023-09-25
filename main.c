#include "monty.h"
bus_t bus = {NULL, NULL, NULL, 0};

/**
 * main - Entry point for the Monty Bytecode Interpreter
 * @argc: The number of command-line arguments
 * @argv: An array of command-line argument strings
 *
 * Return: 0 on success, EXIT_FAILURE on failure
 */
int main(int argc, char *argv[])
{
	size_t size = 0;
	char *file_content;
	FILE *file_ptr;
	ssize_t num_bytes_read = 1;
	stack_t *stack = NULL;
	unsigned int count = 0;

	if (argc != 2)
	{
		fprintf(stderr, "USAGE: monty file\n");
		exit(EXIT_FAILURE);
	}
	file_ptr = fopen(argv[1], "r");
	bus.file = file_ptr;
	if (!file_ptr)
	{
		fprintf(stderr, "Error: Can't open file %s\n", argv[1]);
		exit(EXIT_FAILURE);
	}
	while (num_bytes_read > 0)
	{
		file_content = NULL;
		num_bytes_read = getline(&file_content, &size, file_ptr);
		bus.content = file_content;
		count++;
		if (num_bytes_read > 0)
		{
			execute_cmd(file_content, &stack, count, file_ptr);
		}
		free(file_content);
	}
	free_stack(stack);
	fclose(file_ptr);
	return (0);
}

/**
 * execute_cmd - Execute a Monty bytecode command
 * @file_content: The bytecode command as a string
 * @stack: Double pointer to the stack data structure
 * @count: Line number in the bytecode file
 * @file_ptr: Pointer to the bytecode file
 *
 * Return: 0 on success, 1 on failure
 */
int execute_cmd(char *file_content, stack_t **stack, unsigned int count,
				FILE *file_ptr)
{
	instruction_t operations[] = {
		{"push", push_to_stack}, {"pall", prints_all}, {"pint", print_int},
		{"pop", remove_from_stack_top}, {"swap", swap_stack}, {"add", stack_add},
		{"nop", do_nothing}, {"sub", stack_substract}, {"div", stack_divide},
		{"mul", stack_multiply}, {"mod", stack_modulus}, {"pchar", print_char},
		{"pstr", print_str}, {"rotl", rotate_stack_left}, {"rotr", rotate_stack_right},
		{"queue", set_stack_mode}, {"stack", print_stack_top}, {NULL, NULL}
	};
	unsigned int j = 0;
	char *token;

	token = strtok(file_content, " \n\t"); /* Tokenize the bytecode line */
	if (token && token[0] == '#')
	{
		return (0);
	}
	bus.arg = strtok(NULL, " \n\t");
	while (operations[j].opcode && token)
	{
		if (strcmp(token, operations[j].opcode) == 0)
		{	operations[j].f(stack, count);
			return (0);
		}
		j++;
	}
	if (token && operations[j].opcode == NULL)
	{ fprintf(stderr, "L%d: unknown instruction %s\n", count, token);
		fclose(file_ptr);
		free(file_content);
		free_stack(*stack);
		exit(EXIT_FAILURE); }
	return (1);
}

/**
 * free_stack - Free all nodes in a stack
 * @head: Pointer to the head of the stack
 */
void free_stack(stack_t *head)
{
	stack_t *temp_node;

	temp_node = head;
	while (head)
	{
		temp_node = head->next;
		free(head);
		head = temp_node;
	}
}

/**
 * add_node_to_stack_top - Add a new node to the top of a stack
 * @head: Double pointer to the head of the stack
 * @n: Value to be stored in the new node
 */
void add_node_to_stack_top(stack_t **head, int n)
{

	stack_t *node_new, *temp_node;

	temp_node = *head;
	node_new = malloc(sizeof(stack_t));

	if (node_new == NULL)
	{ 
		printf("Error\n");
		exit(0); 
	}
	if (temp_node)
	{
		temp_node->prev = node_new;
	}
	node_new->n = n;
	node_new->next = *head;
	node_new->prev = NULL;
	*head = node_new;
}

/**
 * add_node_to_stack_end - Add a new node to the end of a stack
 * @head: Double pointer to the head of the stack
 * @n: Value to be stored in the new node
 */
void add_node_to_stack_end(stack_t **head, int n)
{
	stack_t *node_new, *temp_node;

	temp_node = *head;
	node_new = malloc(sizeof(stack_t));
	if (node_new == NULL)
	{
		printf("Error\n");
	}
	node_new->n = n;
	node_new->next = NULL;
	if (temp_node)
	{
		while (temp_node->next)
		{
			temp_node = temp_node->next;
		}
	}
	if (!temp_node)
	{
		*head = node_new;
		node_new->prev = NULL;
	}
	else
	{
		temp_node->next = node_new;
		node_new->prev = temp_node;
	}
}
