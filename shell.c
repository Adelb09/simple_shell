#include <stdio.h> 
#include<stdlib.h>

int main(void)
{
char *prompt = "#cisfun$ ";
char *buffer = NULL;
size_t bufsize = 0;
ssize_t characters;

while (1)
{
printf("%s", prompt);
characters = getline(&buffer, &bufsize, stdin);
if (characters == EOF)
{
printf("\n");
break;
}
printf("%s", buffer);
}

free(buffer);
buffer = NULL;

return 0;
}
