#include "monty.h"

/**
 * free_dlistint - frees memory from a list
 * @head: pointer to the first node
 *
 * Return: void
 */
void free_dlistint(stack_t *head)
{
stack_t *next, *current;

current = head;
while (current)
{
next = current->next;
free(current);
current = next;
}
}

/**
 * free_all - frees all the memory created at the end of main function
 * @line: buff created to store line readed
 * @fl: file opened
 * @top: pointer to top of stack
 *
 * Return: void
 */
void free_all(char *line, FILE *fl, stack_t *top)
{
free(line);
fclose(fl);
free_dlistint(top);
}


/**
 * print_error - prints all the different errors according to its type
 * @error_type: pointer to string indicating type
 *
 * Return:  void - exit with EXIT_FAILURE
 */
void print_error(char  *error_type, ...)
{
va_list replacers;

va_start(replacers, error_type);
if (strcmp(error_type, "usage") == 0)
{
fprintf(stderr, "USAGE: monty file\n");
}
if (strcmp(error_type, "open") == 0)
{
fprintf(stderr, "Error: Can't open file %s\n", va_arg(replacers, char *));
}
if (strcmp(error_type, "malloc") == 0)
{
fprintf(stderr, "Error: malloc failed\n");
}
exit(EXIT_FAILURE);
}

/**
 * print_error_functions - prints all the different errors according to type
 * @error_type: pointer to string indicating type
 *
 * Return:  void - exit with EXIT_FAILURE
 */
void print_error_functions(char  *error_type, ...)
{
va_list replacers;

va_start(replacers, error_type);
if (strcmp(error_type, "integer") == 0)
{
fprintf(stderr, "L%d: usage: push integer\n",
va_arg(replacers, int));
}

free(va_arg(replacers, char *));
fclose(va_arg(replacers, FILE *));
free_dlistint(va_arg(replacers, stack_t *));
exit(EXIT_FAILURE);
}

/**
 * get_instruction - returns the instruction according to the opcode found
 * @opcode: token gotten from file
 * @line_number: number of the line were instructions was provided
 * @line: line readed from file. Use to free in case of error
 * @fl: file opened. Use to fclose in case of error
 * @top: top of stack. Use to free list memory
 *
 * Return: pointer to struct instruction requested
 */
instruction_t get_instruction(char *opcode, int line_number,
char *line, FILE *fl, stack_t *top)
{
instruction_t instructions[] = {{"push", push}, {"pall", pall},
{"pint", pint}, {"pop", pop}, {"swap", swap}, {"add", add}, {"nop", nop}};
int length = 0, i = 0;

length = (sizeof(instructions) / sizeof(instruction_t));
while (i < length)
{
if (strcmp(opcode, instructions[i].opcode) == 0)
return (instructions[i]);
i++;
}
fprintf(stderr, "L%d: unknown instruction %s\n", line_number, opcode);
free(line);
free_dlistint(top);
fclose(fl);
exit(EXIT_FAILURE);
}
