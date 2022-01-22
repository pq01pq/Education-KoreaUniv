#include <stdio.h>

void main(int argc, char *argv[])
{
	char s[100];
	FILE *ifp, *ofp;
	ifp = fopen(argv[1], "r");
	ofp = fopen(argv[2], "w");

	fgets(s, sizeof(s), ifp);
	fputs(s, ofp);

	fclose(ifp);
	fclose(ofp);

	return;
}