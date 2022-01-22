#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_YEAR_DURATION	10	// 기간

// 애기들 구조체 선언
typedef struct {
	char	name[20]; // 이름
	char	sex; // 성별 M or F
	int		freq[MAX_YEAR_DURATION]; // 이름의 연도별 빈도
} name;

int cmp_struct( const void *s1, const void *s2)
{
	name *p1 = (name *)s1;
	name *p2 = (name *)s2;
	
	if( strcmp( p1->name, p2->name) == 0)
		return (int)p1->sex - (int)p2->sex;
	else
		return strcmp( p1->name, p2->name);
}

int cmp_name( const void *s1, const void *s2)
{
	const char *p1 = (const char *)s1;
	name *p2 = (name *)s2;
	
	return strcmp( p1, p2->name);
}

////////////////////////////////////////////////////////////////////////////////
// 연도별 입력 파일(이름 정보)을 구조체 배열에 저장
// 이미 구조체에 존재하는(저장된) 이름은 해당 연도의 빈도만 저장
// 새로 등장한 이름은 구조체에 추가 후 정렬
// (동일 이름이 남/여 각각 사용될 수 있으므로, 정렬시 이름과 성별을 구별해야 함)
// 이름의 존재 여부는 bsearch 함수로 확인
int readnames( FILE *fp, int year_index, name *names, int num)
{
	char s[100];
	name *p;
	
	char temp_name[20];
	char temp_sex;
	int temp_freq;
	
	int pre_num = num;
	int now_num = num;
	
	// 배열 s에 파일에서 한줄씩 저장. s는 파일의 한 줄
	while( fgets( s, sizeof(s), fp) != NULL)
	{
		// ','를 ' '로 바꿈
		int i = 0;
		while( s[i] != '\0')
		{
			if( s[i] == ',')
				s[i] = ' ';
			
			i++;
		}
		
		// 현재 줄의 데이터들을 임시 변수에 저장
		sscanf( s, "%s %s %d", temp_name, &temp_sex, &temp_freq);
		
		if( pre_num == 0) // 초기에 오름차순으로 정렬할 수 없을 때 데이터가 들어오는대로 저장
		{
			strcpy( names[now_num].name, temp_name);
			names[now_num].sex = temp_sex;
			names[now_num].freq[year_index] = temp_freq;
			
			now_num++;
		}
		else
		{
			p = bsearch( temp_name, names, pre_num, sizeof(name), cmp_name); // 오름차순의 배열에서 일치하는 이름 찾음
			
			if( p != NULL)
			{
				if( p->sex == temp_sex)
					p->freq[year_index] = temp_freq;
				else if( (p + 1)->sex == temp_sex)
					(p + 1)->freq[year_index] = temp_freq;
				else
				{
					strcpy( names[now_num].name, temp_name);
					names[now_num].sex = temp_sex;
					names[now_num].freq[year_index] = temp_freq;
					
					now_num++;
				}
			}
			else
			{
				strcpy( names[now_num].name, temp_name);
				names[now_num].sex = temp_sex;
				names[now_num].freq[year_index] = temp_freq;
				
				now_num++;
			}
		}
	}
	
	return now_num;
}

////////////////////////////////////////////////////////////////////////////////
// 구조체 배열을 화면에 출력
void printnames( name *names, int num, int argc)
{
	int i, j;
	
	for( i = 0; i < num; i++)
	{
		printf("%s\t%c", names[i].name, names[i].sex);
		
		for( j = 0; j < argc - 1; j++)
			printf("\t%d", names[i].freq[j]);
		
		printf("\n");
	}
}

////////////////////////////////////////////////////////////////////////////////
int main(int argc, char **argv)
{
	name names[65000]; // 최대 130958
	int num = 0;
	FILE *fp;
	
	if (argc == 1)
	{
		printf("파일 입력이 없습니다.\n");
		
		return 0;
	}
	
	int start_year = atoi( &argv[1][3]);
	
	int i;
	for ( i = 1; i < argc; i++)
	{
		fp = fopen( argv[i], "r");
		
		int year = atoi( &argv[i][3]); // ex) "yob2009.txt" -> 2009
		
		// 연도별 입력 파일(이름 정보)을 구조체 배열에 저장
		num = readnames( fp, year - start_year, names, num);
		
		qsort( names, num, sizeof(name), cmp_struct);
		
		fclose( fp);
	}
	
	// 구조체 배열 -> 화면 출력
	printnames( names, num, argc);
	printf("성별을 고려한 이름의 수 : %d\n", num);
	
	// 구조체 배열 -> 파일 출력
	fp = fopen( "name.txt", "w");
	
	char s[100], t[10];
	int j;
	int k = 0;
	int power_ten = 1;
	int integer, rest, offset;
	for( i = 0; i < num; i++)
	{
		strcpy( s, names[i].name);
		strcat( s, "\t");
		strcat( s, &names[i].sex);
		for( j = 0; j < argc - 1; j++)
		{
			strcat( s, "\t");
			
			integer = names[i].freq[j];
			if( integer == 0)
			{
				t[0] = '0';
				t[1] = '\0';
			}
			else if( integer > 0)
			{
				while( names[i].freq[j] % power_ten < names[i].freq[j])
				{
					power_ten *= 10;
					k++;
				}
				int offset = k;
				while( power_ten > 1)
				{
					power_ten /= 10;
					rest = integer % power_ten;
					t[offset - k] = (char)( ( ( integer - rest ) / power_ten) + 48);	
					integer = rest; // n == (a * q) + r  ->  a == (n - r) / q													
					k--;            // '0' == 48, '1' == 49, ... , '9' == 57
				}
				t[offset] = '\0';
			}
			strcat( s, t);
		}
		strcat( s, "\n");
		fputs( s, fp);
	}
	//fwrite( names, sizeof(name), num, fp);
	fclose(fp);
		
	return 1;
}