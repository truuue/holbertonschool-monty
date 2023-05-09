#include "monty.h"

int (*get_ops(char *token))(monty_stack_t **, unsigned int)
{
	printf("token get_ops = [%s]\n", token);
instruction_t opcode_func[] = {
		{"push", push},
		{"pall", pall},
		{NULL, NULL}
	};
    int i = 0;

		while (opcode_func[i].opcode != NULL)
		{
			if (strcmp(opcode_func[i].opcode, token) == 0)
			{
				return (opcode_func[i].f);
			}
			i++;
		}
	return (NULL);
}
