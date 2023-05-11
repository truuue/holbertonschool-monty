#include "monty.h"

/**
 * get_ops - returns the function pointer of the corresponding opcode
 * @token: the opcode to search for
 *
 * Return: pointer to the function corresponding to the opcode,
 * or NULL if not found
 */
void (*get_ops(char *token))(monty_stack_t **, unsigned int)
{
	int i = 0;
	instruction_t opcode_func[] = {
	    {"push", push},
	    {"pall", pall},
	    {NULL, NULL}};

	while (opcode_func[i].opcode != NULL)
	{
		if (strcmp(opcode_func[i].opcode, token) == 0)
			return (opcode_func[i].f);
		i++;
	}
	return (NULL);
}
