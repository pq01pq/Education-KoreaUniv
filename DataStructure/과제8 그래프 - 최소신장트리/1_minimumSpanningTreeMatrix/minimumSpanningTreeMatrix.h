#pragma once

#include <stdbool.h>

#define MAX_INDEX	10
#define TEST_INDEX	5
#define INFINITY	255
// 2^31 - 1 = 2147483647

#define TEST		0

#if TEST
#define INDEX		TEST_INDEX
#else
#define INDEX		MAX_INDEX
#endif

int prim(int(*graphWeight)[INDEX], int(*mstWeight)[INDEX]);