#include "shell.h"
#include <stdio.h>
#include <string.h>

/* Other function prototypes */

int main(void)
{
char *line;
size_t bufsize = 0;
/* Other variable declarations */
    
while (1)
{
printf("$ ");  /* Print shell prompt */
        
/* Read input from user */
getline(&line, &bufsize, stdin);
        
/* Tokenize input and handle other commands */
        
/* Check if the command is "exit" */
if (strcmp(line, "exit\n") == 0)
{
exit_shell();  /* Call exit built-in function */
}
        
/* Other command handling */
}
    
/* Free allocated memory and close open files/directories */
free(line);
/* Other cleanup */
    
return 0;
}
