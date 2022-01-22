#include <stdio.h>

void main(int argc, char *argv[])
{
	char s[100];
	FILE *ifp, *ofp;
	ifp = fopen(argv[1], "r");
	ofp = fopen(argv[2], "w");

	fgets(s, sizeof(s), ifp);

	int i = 0;
	int blank = 1;
	while (s[i] != '\0')
	{
		if (s[i] != ' ' && s[i] != '\t') // s[i]가 문자
			if (blank == 0) // 이전 포인터가 문자
				i++;
			else            // 이전 포인터가 공백     
			{
				if (s[i] >= 'a' && s[i] <= 'z')
					s[i] += 'A' - 'a';

				blank = 0;
				i++;
			}
		else // s[i]가 공백
		{
			blank = 1;
			i++;
		}
	}

	fputs(s, ofp);

	fclose(ifp);
	fclose(ofp);

	return;
}