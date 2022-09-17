#include "monty.h"

/**
 * main - main function (entry point)
 * @argc: number of arguments
 * @argv: pointer to list of arguments
 *
 * Return: 0 always
 */
int main(int argc, char *argv[])
{
FILE *fl = NULL;
stack_t *top = NULL;
char *line = NULL, *token = NULL, *push_token = NULL;
unsigned int line_number = 0;
instruction_t instruction;

if (argc != 2)
print_error("usage");
fl = fopen(argv[1], "r");
if (fl == NULL)
print_error("open", argv[1]);
line = malloc(sizeof(char) * 1024);
if (line == NULL)
print_error("malloc");
while (1)
{
if (fgets(line, 1024, fl) == NULL)
break;
line_number++;
token = strtok(line, DELIM);
while (token != NULL)
{
instruction = get_instruction(token, line_number, line, fl, top);
if (strcmp(instruction.opcode, "push") == 0)
{
push_token = strtok(NULL, DELIM);
if (!push_token || is_number(push_token) == -1)
print_error_functions("integer", line_number, line, fl, top);
data = atoi(push_token);
}
instruction.f(&top, line_number);
break;
}
}
free_all(line, fl, top);
return (0);
}

/**
 * is_number - checks if the string is a number
 * @str: str to be compared
 *
 * Return: o if true, 1 otherwise
 */
int is_number(char *str)
{
int i = 0;

while (str[i] != '\0')
{
if ((str[i] >= 48 && str[i] <= 57) || str[i] == 45)
i++;
else
return (-1);
}
return (0);
}
