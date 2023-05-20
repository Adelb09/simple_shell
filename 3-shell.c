#include "shell.h"

int main(int argc, char **argv, char **environ)
{
char *line = NULL;
char **args;
char *full_path;

(void)argc;
(void)argv;

while (1)
{
prompt();
line = read_line();
args = tokenize(line);
full_path = path(args);
execute(args, full_path, environ);

free(line);
free(args);
free(full_path);
}

return (0);
}
