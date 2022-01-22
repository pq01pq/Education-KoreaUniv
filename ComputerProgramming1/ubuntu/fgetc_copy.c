#include <stdio.h>

void main(int argc, char *argv[])
{	
	int c;
	FILE *ifp, *ofp;
	ifp = fopen(argv[1] , "r");
	ofp = fopen(argv[2] , "w");
	
	while ((c = fgetc(ifp)) != EOF)
		fputc(c, ofp);

	fclose(ifp);
	fclose(ofp);

	return;
}