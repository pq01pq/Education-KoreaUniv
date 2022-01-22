#include <stdio.h>

float maximum(float x, float y);

int main(void)
{
	float x, y;
	
	x = 15.0;
	y = 7.3;
	
	printf("max value between %.3f and %.3f is %.3f\n", x, y, maximum(x, y));
}

float maximum(float x, float y)
{
	if(x > y)
		return x;
	else
		return y;
}