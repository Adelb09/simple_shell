#include "shell.h"

/* Function to display the shell prompt */
void prompt(void)
{
printf("$ ");
}

/* Main function */
int main(void)
{
pid_t pid = fork();  
char *line = NULL;
size_t len = 0;
ssize_t nread;
char *args[4];

while (1)
{
prompt();

/* Read the command line */
nread = getline(&line, &len, stdin);
if (nread == -1)
{
if (feof(stdin))
{
printf("\n");
break;
}
perror("getline");
exit(EXIT_FAILURE);
}

/* Remove the newline character from the command line */
if (line[nread - 1] == '\n')
line[nread - 1] = '\0';

/* Prepare the arguments for execve */
args[0] = line;
args[1] = NULL;

/* Fork a child process */
if (pid == -1)
{
perror("fork");
exit(EXIT_FAILURE);
}
else if (pid == 0)
{
/* Child process */
if (execve(args[0], args, NULL) == -1)
{
perror("execve");
exit(EXIT_FAILURE);
}
}
else
{
/* Parent process */
wait(NULL);
}
}

/* Free allocated memory */
free(line);

return EXIT_SUCCESS;
}
