#include "monty_monty.h"
/**
* execute - executes the opcode
* @stack: head linked list - stack
* @counter: line_counter
* @file: poiner to monty file
* @content: line content
* Return: no return
*/
int execute(char *content, stack_t **stack, unsigned int counter, FILE *file)
{
	instruction_t opst[] = {
				{"push", mty_push}, {"pall", mty_pall}, {"pint", mty_pint},
				{"pop", mty_pop},
				{"swap", mty_swap},
				{"add", mty_add},
				{"nop", mty_nop},
				{"sub", mty_sub},
				{"div", mty_div},
				{"mul", mty_mul},
				{"mod", mty_mod},
				{"pchar", mty_pchar},
				{"pstr", mty_pstr},
				{"rotl", mty_rotl},
				{"rotr", mty_rotr},
				{"queue", mty_queue},
				{"stack", mty_stack},
				{NULL, NULL}
				};
	unsigned int i = 0;
	char *op;

	op = strtok(content, " \n\t");
	if (op && op[0] == '#')
		return (0);
	bus.arg = strtok(NULL, " \n\t");
	while (opst[i].opcode && op)
	{
		if (strcmp(op, opst[i].opcode) == 0)
		{	opst[i].f(stack, counter);
			return (0);
		}
		i++;
	}
	if (op && opst[i].opcode == NULL)
	{ fprintf(stderr, "L%d: unknown instruction %s\n", counter, op);
		fclose(file);
		free(content);
		free_stack(*stack);
		exit(EXIT_FAILURE); }
	return (1);
}
