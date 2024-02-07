#define _CRT_SECURE_NO_WARNINGS 1

#include <stdio.h>
#include <math.h>
#include <float.h>

int main()
{
	double a = 1.0;
	double b = 0.9;
	double x= 0.0000000000001;
	double c = 0.1;
	//if ((fabs(a - b)-c) < DBL_EPSILON)
	if(x < DBL_EPSILON && x > -DBL_EPSILON)
	{
		printf("you can see me!\n");
	}
	else
	{
		printf("oops!\n");
	}
	
	return 0;
}