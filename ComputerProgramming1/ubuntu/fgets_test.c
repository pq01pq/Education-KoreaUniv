#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void main(void)
{
	char str[100];
	char clone[100]
	
	char *p;
	
	while (fgets(str, 100, stdin) != NULL)
	{
		strcpy(clone, str);
		
		p = strdup (str);
		
		printf("%s", clone);
	}
	
	free(p);
	//str[strlen(str) - 1] = 0;

	
}