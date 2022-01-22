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
void readnames( FILE *fp, int year_index, name *names, int *num)
{
	char s[100];
	name *p;
	
	char temp_name[20];
	char temp_sex;
	int temp_freq;
	
	int pre_num = *num;
	//int now_num = num;
	
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
			strcpy( names[*num].name, temp_name);
			names[*num].sex = temp_sex;
			names[*num].freq[year_index] = temp_freq;
			
			(*num)++;
		}
		else
		{
			p = bsearch( temp_name, names, pre_num, sizeof(name), cmp_name); // 오름차순의 배열에서 일치하는 이름 찾음. 꼭 문자열과 일치하는 첫번째 포인터를 리턴하지 않음.
			
			if( p != NULL) // 일치하는 이름이 있을 때
			{
				if( p->sex == temp_sex) // 문자열과 일치하는 첫번째 포인터를 리턴했을 경우
					p->freq[year_index] = temp_freq;
				else if( ( (p + 1)->sex == temp_sex ) && ( strcmp( (p + 1)->name ,temp_name) == 0 ) ) // 문자열과 일치하는 배열의 포인터가 첫번째 포인터이고, 저장할 성별이 'M'이고 배열의 포인터의 성별이 'F'일 때
					(p + 1)->freq[year_index] = temp_freq;
				else if( ( (p - 1)->sex == temp_sex ) && ( strcmp( (p - 1)->name, temp_name) == 0 ) ) // 문자열과 일치하는 배열의 포인터가 첫번째 포인터가 아니고, 저장할 성별이 'F'이고 배열의 포인터의 성별이 'M'일 때
					(p - 1)->freq[year_index] = temp_freq;
				else // 이름은 일치하나 일치하는 성이 없을 때
				{
					strcpy( names[*num].name, temp_name);
					names[*num].sex = temp_sex;
					names[*num].freq[year_index] = temp_freq;
					
					(*num)++;
				}
			}
			else // 일치하는 이름이 없을 때
			{
				strcpy( names[*num].name, temp_name);
				names[*num].sex = temp_sex;
				names[*num].freq[year_index] = temp_freq;
				
				(*num)++;
			}
		}
	}
	
	return;
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
	
	return;
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
		readnames( fp, year - start_year, names, &num);
		
		qsort( names, num, sizeof(name), cmp_struct);
		
		fclose( fp);
	}
	
	// 구조체 배열 -> 화면 출력
	printnames( names, num, argc);
	printf("성별을 고려한 이름의 수 : %d\n", num);
	
	// 구조체 배열 -> 파일 출력
	fp = fopen( "name.dat", "w");
	fwrite( names, sizeof( name), num, fp);
	fclose(fp);
		
	return 1;
}