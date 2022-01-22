#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>

void main(void)
{
	char s[100];
	FILE *ifp, *ofp;
	ifp = fopen("test1.txt", "r");
	ofp = fopen("test2.txt", "w");

	fgets(s, sizeof(s), ifp);
	fputs(s, ofp);

	fclose(ifp);
	fclose(ofp);

	return;
}