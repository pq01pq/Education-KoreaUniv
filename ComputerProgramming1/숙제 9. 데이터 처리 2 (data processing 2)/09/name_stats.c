#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_YEAR_DURATION	10	// 기간

// 학생 구조체 선언
typedef struct {
	char	name[20]; // 이름
	char	sex; // 성별 M or F
	int		freq[MAX_YEAR_DURATION]; // 이름의 연도별 빈도
} NAME;

// 연도별 빈도 중 하나라도 N을 넘는 이름만 출력
void show_morethanN( NAME *names, int num, int N);

// 연도별 빈도의 합을 기준으로 상위 N명의 이름을 출력
void show_topN_name( NAME *names, int num, char sex, int topN);

// 연도별 빈도가 지속적으로 증가하는 이름만 출력
void show_increasing_name( NAME *names, int num);

// 연도별 빈도가 지속적으로 감소하는 이름만 출력
void show_decreasing_name( NAME *names, int num);

// 특정 하나의 연도에만 빈도가 나타나는 이름만 출력 (나머지 연도의 빈도는 0)
void show_onlyonce_name( NAME *names, int num);

// 접두사(prefix)로 시작하는 이름만 출력
void show_prefix_name( NAME *names, int num, char *prefix);

////////////////////////////////////////////////////////////////////////////////
// 파일로부터 이름 구조체를 저장한다. 
// 구조체를 위한 메모리를 할당하고 그 주소를 반환한다.
// 구조체에 저장된 이름의 수는 num에 저장
// 실패시 NULL을 반환
NAME *loadnames( char *filename, int *num)
{
	FILE *fp = fopen( filename, "r");
	if (fp == NULL) return 0;
	
	fseek( fp, 0, SEEK_END);
	long size = ftell( fp);
	
	NAME *names = (NAME *)malloc( size);
	
	fseek( fp, 0, SEEK_SET);
	
	*num = (int) (size / sizeof( NAME));
	
	fread( names, sizeof( NAME), *num, fp);
	
	fclose(fp);

	return names;
}

////////////////////////////////////////////////////////////////////////////////
// 구조체 배열을 화면에 출력
void printnames( NAME *names, int num)
{
	int i;
	
	for (i = 0; i < num; i++)
	{
		printf("%s\t%c", names[i].name, names[i].sex); // name, sex
		
		for (int j = 0; j < MAX_YEAR_DURATION; j++)
		{
			printf("\t%d", names[i].freq[j]);
		}
		printf("\n");
	}
}

////////////////////////////////////////////////////////////////////////////////
int select_menu(void)
{
	char str[2];
	char menu;
	
	while(1)
	{
		printf( "	-------------------------------------\n");
		printf( "	Q) quit\n"); 
		printf( "	M) show names more than N times.\n");
		printf( "	D) show only decreasing names.\n");
		printf( "	I) show only increasing names.\n");
		printf( "	T) show top N names.\n");
		printf( "	O) show names occurring only once.\n");
		printf( "	P) show names starting with a string.\n");
		printf( "	-------------------------------------\n");
		printf( "Select menu: ");
		
		if (EOF == fscanf( stdin, "%s", str)) return 0;
	
		menu = toupper(str[0]);
		
		if (menu == 'Q') return 0;
		if (menu == 'M' || menu == 'D' || menu == 'I' || menu == 'T' || menu == 'O' || menu == 'P') 
			return menu;
	}
}
////////////////////////////////////////////////////////////////////////////////
int main(int argc, char **argv)
{
	NAME *names;
	int num = 0;
	FILE *fp;
	
	if (argc == 1) 
	{
		printf( "Usage: %s FILE\n", argv[0]);
		return 0;
	}
	
	names = loadnames( argv[1], &num);
	if (names == NULL)
	{
		printf( "Error: cannot open file %s\n", argv[1]);
		return 0;
	}
	
	int menu;
	
	while( menu = select_menu())
	{
		switch (menu)
		{
			int N;
			case 'M':
				printf( "Enter a number: ");
				scanf( "%d", &N);
				//show_morethanN( names, num, N);
				break;
			
			case 'D':
				//show_decreasing_name( names, num);
				break;
			
			case 'I':
				//show_increasing_name( names, num);
				break;
			
			case 'T':
				printf( "Enter a number: ");
				scanf( "%d", &N);
				printf( "M)ale? F)emale? or *)Both: ");
				char sex[2];
				char s;
				while(1)
				{
					scanf( "%s", sex);
					s = toupper(sex[0]);
					if (s == 'M' || s == 'F' || s == '*') break;
				}	
				//show_topN_name( names, num, s, N); // 'M', 'F', or '*', topN
				break;
				
			case 'O':
				//show_onlyonce_name( names, num);
				break;
			
			case 'P':
				printf( "Enter a prefix: ");
				char prefix[100];
				scanf("%s", prefix);
				//show_prefix_name( names, num, prefix);
				break;
		}
	}
	
	free( names);
	
	return 1;
}
