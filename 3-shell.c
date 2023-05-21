#include "shell.h"

char *read_line(void)
{
char *line = NULL;
size_t bufsize = 0; /* getline will allocate a buffer for us */
getline(&line, &bufsize, stdin);
return line;
}

char **split_line(char *line)
{
int bufsize = 64, position = 0;
char **tokens = malloc(bufsize * sizeof(char *));
char *token;

if (!tokens) {
fprintf(stderr, "Allocation error\n");
exit(EXIT_FAILURE);
}

token = strtok(line, " \t\r\n\a");
while (token) {
tokens[position] = token;
position++;

if (position >= bufsize) {
bufsize += 64;
tokens = realloc(tokens, bufsize * sizeof(char *));
if (!tokens) {
fprintf(stderr, "Allocation error\n");
exit(EXIT_FAILURE);
}
}

token = strtok(NULL, " \t\r\n\a");
}
tokens[position] = NULL;
return tokens;
}

int execute(char **args)
{
if (args[0] == NULL) {
// Empty command entered
return 1;
}

// Implement the code to handle built-in commands like "cd" and "exit" here

int status;

pid = fork();
if (pid == 0) {
// Child process
if (execvp(args[0], args) == -1) {
perror("shell");
}
exit(EXIT_FAILURE);
} else if (pid < 0) {
// Error forking
perror("shell");
} else {
// Parent process
pid_t pid, wpid;  
do {
wpid = waitpid(pid, &status, WUNTRACED);
} while (!WIFEXITED(status) && !WIFSIGNALED(status));
}

return 1;
}
