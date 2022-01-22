#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>

void main(void)
{
	int c;
	FILE *ifp, *ofp;
	ifp = fopen("test1.txt", "r");
	ofp = fopen("test2.txt", "w");

	while ((c = fgetc(ifp)) != EOF)
		fputc(c, ofp);

	fclose(ifp);
	fclose(ofp);

	return;
}