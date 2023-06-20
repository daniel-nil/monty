#include "monty_monty.h"
/**
* execute - executes the opcode
* @stack: head linked list - stack
* @counter: line_counter
* @file: poiner to monty file
* @content: line content
* Return: no return
*/
int mty_execute(char *content, stack_t **stack, unsigned int counter, FILE *file)
{
	instruction_t opst[] = {
				{"push", mty_f_push}, {"pall", mty_f_pall}, {"pint", mty_f_pint},
				{"pop", mty_f_pop},
				{"swap", mty_f_swap},
				{"add", mty_f_add},
				{"nop", mty_f_nop},
				{"sub", mty_f_sub},
				{"div", mty_f_div},
				{"mul", mty_f_mul},
				{"mod", mty_f_mod},
				{"pchar", mty_f_pchar},
				{"pstr", mty_f_pstr},
				{"rotl", mty_f_rotl},
				{"rotr", mty_f_rotr},
				{"queue", mty_f_queue},
				{"stack", mty_f_stack},
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
		mty_free_stack(*stack);
		exit(EXIT_FAILURE); }
	return (1);
}
