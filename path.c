#include "shell.h"

/**
 * path - search for the command in the PATH directories
 * @args: array of arguments, with the command as the first element
 * Return: the full path of the command if found, NULL otherwise
 */
char *path(char **args)
{
char *path_var = _getenv("PATH");
char **dirs = tokenize(path_var);
char *full_path = NULL;
char *command = args[0];
int i;

for (i = 0; dirs[i]; i++)
{
full_path = _strcat(dirs[i], "/");
full_path = _strcat(full_path, command);
if (access(full_path, F_OK) == 0)
{
free(path_var);
free(dirs);
return (full_path);
}
free(full_path);
}

free(path_var);
free(dirs);
return (NULL);
}
