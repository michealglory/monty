#include "monty.h"
/**
 * stack_add - Add the top two elements of the stack
 * @head: Double pointer to the head of the stack
 * @count: Line number in the bytecode file
 */
void stack_add(stack_t **head, unsigned int count)
{
	stack_t *current_head;
	int num_node = 0, result;

	current_head = *head;
	while (current_head)
	{
		current_head = current_head->next;
		num_node++;
	}
	if (num_node < 2)
	{
		fprintf(stderr, "L%d: can't add, stack too short\n", count);
		fclose(bus.file);
		free(bus.content);
		free_stack(*head);
		exit(EXIT_FAILURE);
	}
	current_head = *head;
	result = current_head->n + current_head->next->n;
	current_head->next->n = result;
	*head = current_head->next;
	free(current_head);
}

/**
 * stack_divide - Divide the second element of the stack by the top element
 * @head: Double pointer to the head of the stack
 * @count: Line number in the bytecode file
 */
void stack_divide(stack_t **head, unsigned int count)
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
		fprintf(stderr, "L%d: can't div, stack too short\n", count);
		fclose(bus.file);
		free(bus.content);
		free_stack(*head);
		exit(EXIT_FAILURE);
	}
	current_head = *head;
	if (current_head->n == 0)
	{
		fprintf(stderr, "L%d: division by zero\n", count);
		fclose(bus.file);
		free(bus.content);
		free_stack(*head);
		exit(EXIT_FAILURE);
	}
	result = current_head->next->n / current_head->n;
	current_head->next->n = result;
	*head = current_head->next;
	free(current_head);
}

/**
 * stack_modulus - Calculate the modulus of the second element by
 * the top element
 * @head: Double pointer to the head of the stack
 * @count: Line number in the bytecode file
 */
void stack_modulus(stack_t **head, unsigned int count)
{
	int num_nodes = 0, result;
	stack_t *current_head;

	current_head = *head;
	while (current_head)
	{
		current_head = current_head->next;
		num_nodes++;
	}
	if (num_nodes < 2)
	{
		fprintf(stderr, "L%d: can't mod, stack too short\n", count);
		fclose(bus.file);
		free(bus.content);
		free_stack(*head);
		exit(EXIT_FAILURE);
	}
	current_head = *head;
	if (current_head->n == 0)
	{
		fprintf(stderr, "L%d: division by zero\n", count);
		fclose(bus.file);
		free(bus.content);
		free_stack(*head);
		exit(EXIT_FAILURE);
	}
	result = current_head->next->n % current_head->n;
	current_head->next->n = result;
	*head = current_head->next;
	free(current_head);
}

/**
 * stack_multiply - Multiply the second element by the top element
 * @head: Double pointer to the head of the stack
 * @count: Line number in the bytecode file
 */
void stack_multiply(stack_t **head, unsigned int count)
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
		fprintf(stderr, "L%d: can't mul, stack too short\n", count);
		fclose(bus.file);
		free(bus.content);
		free_stack(*head);
		exit(EXIT_FAILURE);
	}
	current_head = *head;
	result = current_head->next->n * current_head->n;
	current_head->next->n = result;
	*head = current_head->next;
	free(current_head);
}

/**
 * stack_substract - Subtract the top element from the second element
 * @head: Double pointer to the head of the stack
 * @count: Line number in the bytecode file
 */
void stack_substract(stack_t **head, unsigned int count)
{
	stack_t *node_temp;
	int result, i;

	node_temp = *head;
	for (i = 0; node_temp != NULL; i++)
	{
		node_temp = node_temp->next;
	}
	if (i < 2)
	{
		fprintf(stderr, "L%d: can't sub, stack too short\n", count);
		fclose(bus.file);
		free(bus.content);
		free_stack(*head);
		exit(EXIT_FAILURE);
	}
	node_temp = *head;
	result = node_temp->next->n - node_temp->n;
	node_temp->next->n = result;
	*head = node_temp->next;
	free(node_temp);
}
