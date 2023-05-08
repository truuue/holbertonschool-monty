/**
 * print_dlistint - Short description, single line
 * @h: Description of parameter x
 *
 * Return: The total of the nodes
 */
stack_s pall(const monty_stack_t *h)
{
	int i = 0;

	while (h != NULL)
	{
		int k = h->n;

		printf("%d\n", k);
		i++;
		h = h->next;
	}
	return (i);
}

/**
 * add_dnodeint - Short description, single line
 * @n: The number given by the main
 * @head: the struct
 (*
 * Return: The total of the nodes
 */
dlistint_t *add_dnodeint(dlistint_t **head, const int n)
{
	dlistint_t *newnode = malloc(sizeof(dlistint_t));

	if (newnode == NULL)
	{
		return (NULL);
	}

	newnode->n = n;
	newnode->prev = NULL;
	newnode->next = *head;

	if (*head != NULL)
	{
		(*head)->prev = newnode;
	}
	*head = newnode;

	return (*head);
}

/* la fonction de la calculatrice qui utilisait des pointeurs sur fonction :
*/

int (*get_op_func(char *s))(int, int)
{
	op_t ops[] = {
		{"+", op_add},
		{"-", op_sub},
		{"*", op_mul},
		{"/", op_div},
		{"%", op_mod},
		{NULL, NULL}
	};
	int i = 0;

	while (i < 5)
	{
		if (*ops[i].op == *s)
		{
			return (*ops[i].f);
		}
		i++;
	}
	return (NULL);
}
