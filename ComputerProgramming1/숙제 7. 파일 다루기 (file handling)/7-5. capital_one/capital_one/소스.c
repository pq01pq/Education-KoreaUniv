#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>

void main(void)
{
	char s[100];
	FILE *ifp, *ofp;
	ifp = fopen("test1.txt", "r");
	ofp = fopen("test2.txt", "w");

	fgets(s, sizeof(s), ifp);

	int i = 0;
	int blank = 1;
	while (s[i] != '\0')
	{
		if (s[i] != ' ' && s[i] != '\t') // s[i]�� ����
			if (blank == 0) // ���� �����Ͱ� ����
				i++;
			else            // ���� �����Ͱ� ����     
			{
				if (s[i] >= 'a' && s[i] <= 'z')
					s[i] += 'A' - 'a';

				blank = 0;
				i++;
			}
		else // s[i]�� ����
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