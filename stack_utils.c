#include "monty.h"
/**
 * do_nothing - Do nothing (no operation)
 * @head: Double pointer to the head of the stack (unused)
 * @count: Line number in the bytecode file (unused)
 */
void do_nothing(stack_t **head, unsigned int count)
{
	(void) count;
	(void) head;
}

/**
 * remove_from_stack_top - Remove the top element of the stack
 * @head: Double pointer to the head of the stack
 * @counter: Line number in the bytecode file
 */
void remove_from_stack_top(stack_t **head, unsigned int count)
{
	stack_t *head_temp;

	if (*head == NULL)
	{
		fprintf(stderr, "L%d: can't pop an empty stack\n", count);
		fclose(bus.file);
		free(bus.content);
		free_stack(*head);
		exit(EXIT_FAILURE);
	}
	head_temp = *head;
	*head = head_temp->next;
	free(head_temp);
}

/**
 * push_to_stack - Push an integer onto the stack
 * @head: Double pointer to the head of the stack
 * @count: Line number in the bytecode file
 */
void push_to_stack(stack_t **head, unsigned int count)
{
	int i, k = 0, flag_id = 0;

	if (bus.arg)
	{
		if (bus.arg[0] == '-')
			k++;
		for (; bus.arg[k] != '\0'; k++)
		{
			if (bus.arg[k] > 57 || bus.arg[k] < 48)
				flag_id = 1; }
		if (flag_id == 1)
		{ fprintf(stderr, "L%d: usage: push integer\n", count);
			fclose(bus.file);
			free(bus.content);
			free_stack(*head);
			exit(EXIT_FAILURE); }}
	else
	{ fprintf(stderr, "L%d: usage: push integer\n", count);
		fclose(bus.file);
		free(bus.content);
		free_stack(*head);
		exit(EXIT_FAILURE); }
	i = atoi(bus.arg);
	if (bus.lifi == 0)
	{
		add_node_to_stack_top(head, i);
	}
	else
	{
		add_node_to_stack_end(head, i);
	}
}

/**
 * swap_stack - Swap the top two elements of the stack
 * @head: Double pointer to the head of the stack
 * @counter: Line number in the bytecode file
 */
void swap_stack(stack_t **head, unsigned int counter)
{
	stack_t *current_head;
	int num_nodes = 0, result;

	current_head = *head;
	while (current_head)
	{
		current_head = current_head->next;
		num_nodes++;
	}
	if (num_nodes < 2)
	{
		fprintf(stderr, "L%d: can't swap, stack too short\n", counter);
		fclose(bus.file);
		free(bus.content);
		free_stack(*head);
		exit(EXIT_FAILURE);
	}
	current_head = *head;
	result = current_head->n;
	current_head->n = current_head->next->n;
	current_head->next->n = result;
}

/**
 * print_stack_top - prints the top of the stack
 * @head: stack head
 * @count: line_number
 * Return: no return
*/
void print_stack_top(stack_t **head, unsigned int count)
{
	(void)head;
	(void)count;
	bus.lifi = 0;
}
