#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_YEAR_DURATION	10	// 기간

// 학생 구조체 선언
typedef struct {
	char	name[20]; // 이름
	char	sex; // 성별 M or F
	int		freq[MAX_YEAR_DURATION]; // 이름의 연도별 빈도
} name;

////////////////////////////////////////////////////////////////////////////////
// 연도별 입력 파일(이름 정보)을 구조체 배열에 저장
// 이미 구조체에 존재하는(저장된) 이름은 해당 연도의 빈도만 저장
// 새로 등장한 이름은 구조체에 추가 후 정렬
// (동일 이름이 남/여 각각 사용될 수 있으므로, 정렬시 이름과 성별을 구별해야 함)
// 이름의 존재 여부는 bsearch 함수로 확인
void readnames( FILE *fp, int year_index, name *names, int *num)
{
	
}

////////////////////////////////////////////////////////////////////////////////
// 구조체 배열을 화면에 출력
void printnames( name *names, int num)
{
	
}

////////////////////////////////////////////////////////////////////////////////
int main(int argc, char **argv)
{
	name names[65000];
	int num = 0;
	FILE *fp;
	
	if (argc == 1) return 0;
	
	int start_year = atoi( &argv[1][3]);
	
	for (int i = 1; i < argc; i++)
	{
		fp = fopen( argv[i], "r");
		
		int year = atoi( &argv[i][3]); // ex) "yob2009.txt" -> 2009
		
		// 연도별 입력 파일(이름 정보)을 구조체 배열에 저장
		readnames( fp, year-start_year, names, &num);
		
		fclose( fp);
	}
	
	// 구조체 배열 -> 화면 출력
	printnames( names, num);

	// 구조체 배열 -> 파일 출력
	fp = fopen( "name.dat", "w");
	fwrite( names, sizeof( name), num, fp);
	fclose(fp);
		
	return 1;
}

