#include "shell.h"

int main(void)
{
char *line;
char **args;
int status;

do {
printf(":) ");
line = read_line();      /* Implement this function to read a line from stdin */
args = split_line(line);     // Implement this function to split the line into arguments
status = execute(args);     // Implement this function to execute the command

free(line);
free(args);
} while (status);

return EXIT_SUCCESS;
}
