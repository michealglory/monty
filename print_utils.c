#include "monty.h"
/**
 * prints_all - Print all elements in the stack
 * @head: Double pointer to the head of the stack
 * @count: Line number in the bytecode file (unused)
 */
void prints_all(stack_t **head, unsigned int count)
{
	stack_t *temp_head;
	(void)count;

	temp_head = *head;
	if (temp_head == NULL)
		return;
	while (temp_head)
	{
		printf("%d\n", temp_head->n);
		temp_head = temp_head->next;
	}
}

/**
 * print_char - Print the character at the top of the stack
 * @head: Double pointer to the head of the stack
 * @count: Line number in the bytecode file
 */
void print_char(stack_t **head, unsigned int count)
{
	stack_t *temp_head;

	temp_head = *head;
	if (!temp_head)
	{
		fprintf(stderr, "L%d: can't pchar, stack empty\n", count);
		fclose(bus.file);
		free(bus.content);
		free_stack(*head);
		exit(EXIT_FAILURE);
	}
	if (temp_head->n > 127 || temp_head->n < 0)
	{
		fprintf(stderr, "L%d: can't pchar, value out of range\n", count);
		fclose(bus.file);
		free(bus.content);
		free_stack(*head);
		exit(EXIT_FAILURE);
	}
	printf("%c\n", temp_head->n);
}

/**
 * print_int - Print the top element of the stack
 * @head: Double pointer to the head of the stack
 * @count: Line number in the bytecode file
 */
void print_int(stack_t **head, unsigned int count)
{
	if (*head == NULL)
	{
		fprintf(stderr, "L%u: can't pint, stack empty\n", count);
		fclose(bus.file);
		free(bus.content);
		free_stack(*head);
		exit(EXIT_FAILURE);
	}
	printf("%d\n", (*head)->n);
}


/**
 * print_str - Print the string represented by the stack
 * @head: Double pointer to the head of the stack
 * @count: Line number in the bytecode file (unused)
 */
void print_str(stack_t **head, unsigned int count)
{
	stack_t *head_temp;
	(void)count;

	head_temp = *head;
	while (head_temp)
	{
		if (head_temp->n > 127 || head_temp->n <= 0)
		{
			break;
		}
		printf("%c", head_temp->n);
		head_temp = head_temp->next;
	}
	printf("\n");
}
