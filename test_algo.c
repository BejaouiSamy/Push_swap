#include <stdio.h>
#include <stdlib.h>

struct Node {
	int		data;
	struct Node	*next;
};

struct	Node *third_node(struct Node *head)
{
	int	i;
	struct Node *current = head;
	
	i = 1;
	while (i < 4 && current != NULL)
	{	
		i++;
		current = current->next;
	}
	return current;
}	

void	append(struct Node **head, int new_data)
{
	struct Node *new_node = (struct Node*)malloc(sizeof(struct Node));
	struct Node *last = *head;

	new_node->data = new_data;
	new_node->next = NULL;

	if (*head == NULL)
	{
		*head = new_node;
		return;
	}
	while (last->next != NULL)
		last = last->next;
	last->next = new_node;
}
void	display(struct Node *node)
{
	while (node != NULL)
	{
		printf("%d->", node->data);
		node = node->next;
	}
	printf("NULL\n");
}
int	main(void)
{
	struct Node *head = NULL;
	
	append(&head, 10);
	append(&head, 20);
	append(&head, 30);
	append(&head, 40);
	append(&head, 50);

	display(head);
	struct Node *troisiemeNoeud = third_node(head);
	if (troisiemeNoeud != NULL)
	{
		display(troisiemeNoeud);
	}
}
