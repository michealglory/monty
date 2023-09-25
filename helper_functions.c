#include "monty.h"
/**
 * set_stack_mode - Set the stack mode to queue (FIFO)
 * @head: Double pointer to the head of the stack (unused)
 * @count: Line number in the bytecode file (unused)
 */
void set_stack_mode(stack_t **head, unsigned int count)
{
	(void)head;
	(void)count;
	bus.lifi = 1;
}

/**
 * rotate_stack_left - Rotate the stack to the left
 * @head: Double pointer to the head of the stack
 * @count: Line number in the bytecode file (unused)
 */
void rotate_stack_left(stack_t **head,
		__attribute__((unused)) unsigned int count)
{
	stack_t *node_tmp = *head, *node_current;

	if (*head == NULL || (*head)->next == NULL)
	{
		return;
	}
	node_current = (*head)->next;
	node_current->prev = NULL;
	while (node_tmp->next != NULL)
	{
		node_tmp = node_tmp->next;
	}
	node_tmp->next = *head;
	(*head)->next = NULL;
	(*head)->prev = node_tmp;
	(*head) = node_current;
}

/**
 * rotate_stack_right - Rotate the stack to the bottom
 * @head: Double pointer to the head of the stack
 * @count: Line number in the bytecode file (unused)
 */
void rotate_stack_right(stack_t **head,
						__attribute__((unused)) unsigned int count)
{
	stack_t *cp;

	cp = *head;
	if (*head == NULL || (*head)->next == NULL)
	{
		return;
	}
	while (cp->next)
	{
		cp = cp->next;
	}
	cp->next = *head;
	cp->prev->next = NULL;
	cp->prev = NULL;
	(*head)->prev = cp;
	(*head) = cp;
}
