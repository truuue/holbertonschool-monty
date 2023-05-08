#include "monty.h"

void get_ops()
{
instruction_t opcode_func[] = {
		{"push", push},
		{"pall", pall},
		{NULL, NULL}
	};
    int i = 0;

	while (i < 3)
	{
		if (*opcode_func[i].opcode == *s)
		{
			return (*opcode_func[i].f);
		}
		i++;
	}
	return (NULL);
}
