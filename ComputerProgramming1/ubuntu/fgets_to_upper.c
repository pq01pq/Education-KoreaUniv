#include <stdio.h>

void main(int argc, char *argv[])
{
	char s[100];
	FILE *ifp, *ofp;
	ifp = fopen(argv[1], "r");
	ofp = fopen(argv[2], "w");

	fgets(s, sizeof(s), ifp);

	int i = 0;
	while (s[i] != '\0')
	{
		if (s[i] >= 'a' && *s <= 'z')
			s[i] += 'A' - 'a';

		i++;
	}

	fputs(s, ofp);

	fclose(ifp);
	fclose(ofp);

	return;
}