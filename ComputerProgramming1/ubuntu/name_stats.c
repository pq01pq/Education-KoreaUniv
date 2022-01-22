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
////////////////////////////////////////////////////////////////////////////////
// 구조체 배열을 화면에 출력
void printnames( NAME *temps, int num)
{
	int i;
	
	for (i = 0; i < num; i++)
	{
		printf("%s\t%c", temps[i].name, temps[i].sex); // name, sex
		
		for (int j = 0; j < MAX_YEAR_DURATION; j++)
		{
			printf("\t%d", temps[i].freq[j]);
		}
		printf("\n");
	}
	printf("출력된 이름의 수 : %d개\n", num);
}
////////////////////////////////////////////////////////////////////////////////
// 빈도의 합을 비교
int cmp_sum( const void *name1, const void *name2) // 합의 내림차순, 합이 같으면 이름과 성별의 오름차순 정렬
{
	NAME *p1 = (NAME *)name1;
	NAME *p2 = (NAME *)name2;
	
	int i;
	int sum1 = 0, sum2 = 0;
	for( i = 0; i < MAX_YEAR_DURATION; i++)
	{
		sum1 += p1->freq[i];
		sum2 += p2->freq[i];
	}
	
	if( sum1 == sum2)
	{
		if( strcmp( p1->name, p2->name) == 0)
			return (int) p1->sex - (int) p2->sex;
		else
			return strcmp( p1->name, p2->name);
	}
	else
		return sum2 - sum1;
}
// 연도별 빈도 중 하나라도 N을 넘는 이름만 출력
void show_morethanN( NAME *names, int total_num, int N)
{
	NAME *temps = (NAME *)malloc( sizeof( NAME) * total_num );
	int num = 0;
	
	int i, j, k;
	for ( i = 0; i < total_num; i++)
	{
		int pass_to_next = MAX_YEAR_DURATION;
		for ( j = 0; j < pass_to_next; j++)
		{
			if( names[i].freq[j] > N)
			{
				temps[num] = names[i];
				num++;
				pass_to_next = 0;
			}
		}
	}
	
	printnames( temps, num);
	
	free( temps);
}

// 연도별 빈도의 합을 기준으로 상위 N명의 이름을 출력
void show_topN_name( NAME *names, int total_num, char sex, int topN)
{
	NAME *temps = (NAME *)malloc( sizeof( NAME) * total_num );
	int num = 0;
	
	if( sex == '*')
	{
		num = total_num;
		temps = names;
	}
	else
	{
		int i;
		for( i = 0; i < total_num; i++)
		{
			if( sex == names[i].sex)
			{
				temps[num] = names[i];
				num++;
			}
		}
	}
	
	qsort( temps, num, sizeof( NAME), cmp_sum);
	
	printnames( temps, topN);
	
	free( temps);
}

// 연도별 빈도가 지속적으로 증가하는 이름만 출력
void show_increasing_name( NAME *names, int total_num)
{
	NAME *temps = (NAME *)malloc( sizeof( NAME) * total_num );
	int num = 0;
	
	int i, j;
	for( i = 0; i < total_num; i++)
	{
		int j = 0;
		int increasing = 1;
		while( increasing)
		{
			if( names[i].freq[j + 1] > names[i].freq[j])
			{
				j++;
			}
			else
			{
				increasing = 0;
			}
			
			if( j >= MAX_YEAR_DURATION - 1)
			{
				temps[num] = names[i];
				num++;
				increasing = 0;
			}
		}
	}
	
	printnames( temps, num);
	
	free( temps);
}

// 연도별 빈도가 지속적으로 감소하는 이름만 출력
void show_decreasing_name( NAME *names, int total_num)
{
	NAME *temps = (NAME *)malloc( sizeof( NAME) * total_num );
	int num = 0;
	
	int i, j;
	for( i = 0; i < total_num; i++)
	{
		int j = 0;
		int decreasing = 1;
		while( decreasing)
		{
			if( names[i].freq[j + 1] < names[i].freq[j])
			{
				j++;
			}
			else
			{
				decreasing = 0;
			}
			
			if( j >= MAX_YEAR_DURATION - 1)
			{
				temps[num] = names[i];
				num++;
				decreasing = 0;
			}
		}
	}
	
	printnames( temps, num);
	
	free( temps);
}

// 특정 하나의 연도에만 빈도가 나타나는 이름만 출력 (나머지 연도의 빈도는 0)
void show_onlyonce_name( NAME *names, int total_num)
{
	NAME *temps = (NAME *)malloc( sizeof( NAME) * total_num );
	int num = 0;
	
	int i;
	for( i = 0; i < total_num; i++)
	{
		int j = 0;
		int cnt = 0;
		while( j < MAX_YEAR_DURATION && cnt <= 1)
		{
			if( names[i].freq[j] > 0)
				cnt++;
			
			j++;
		}
		
		if( cnt == 1)
		{
			temps[num] = names[i];
			num++;
		}
	}
	
	printnames( temps, num);
	
	free( temps);
}

// 접두사(prefix)로 시작하는 이름만 출력
void show_prefix_name( NAME *names, int total_num, char *prefix)
{
	NAME *temps = (NAME *)malloc( sizeof( NAME) * total_num );
	int num = 0;
	
	int words = 0;
	while( prefix[words] != '\0')
		words++;
	
	int i;
	for( i = 0; i < total_num; i++)
	{
		int j = 0;
		int same = 1;
		while( same)
		{
			if( names[i].name[j] == prefix[j])
			{
				j++;
			}
			else
			{
				same = 0;
			}
			
			if( j >= words)
			{
				temps[num] = names[i];
				num++;
				same = 0;
			}
		}
	}
	
	printnames( temps, num);
	
	free( temps);
}

////////////////////////////////////////////////////////////////////////////////
// 파일로부터 이름 구조체를 저장한다. 
// 구조체를 위한 메모리를 할당하고 그 주소를 반환한다.
// 구조체에 저장된 이름의 수는 num에 저장
// 실패시 NULL을 반환
NAME *loadnames( char *filename, int *total_num)
{
	FILE *fp = fopen( filename, "r");
	if (fp == NULL) return 0;
	
	fseek( fp, 0, SEEK_END); // 파일 끝으로 이동
	long size = ftell( fp); // 파일 전체 사이즈
	
	NAME *names = (NAME *)malloc( size); // 구조체 메모리 지정
	
	fseek( fp, 0, SEEK_SET); // 파일 처음으로 이동
	
	*total_num = (int) (size / sizeof( NAME)); // *num == 성별을 고려한 이름의 수
	
	fread( names, sizeof( NAME), *total_num, fp);
	
	fclose(fp);

	return names;
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
	int total_num = 0;
	FILE *fp;
	
	if (argc == 1) 
	{
		printf( "Usage: %s FILE\n", argv[0]);
		return 0;
	}
	
	names = loadnames( argv[1], &total_num); // total_num == 구조체의 명단 전체의 수로 지정
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
				show_morethanN( names, total_num, N);
				break;
			
			case 'D':
				show_decreasing_name( names, total_num);
				break;
			
			case 'I':
				show_increasing_name( names, total_num);
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
				show_topN_name( names, total_num, s, N); // 'M', 'F', or '*', topN
				break;
				
			case 'O':
				show_onlyonce_name( names, total_num);
				break;
			
			case 'P':
				printf( "Enter a prefix: ");
				char prefix[100];
				scanf("%s", prefix);
				prefix[0] = toupper( prefix[0]); // 첫글자는 대문자로
				show_prefix_name( names, total_num, prefix);
				break;
		}
	}
	
	free( names);
	
	return 1;
}