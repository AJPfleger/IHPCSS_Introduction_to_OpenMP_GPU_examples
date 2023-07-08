#include <stdio.h>
#include <stdlib.h>
#include <omp.h>
 
int main(int argc, char* argv[])
{
	int a = 1;
	int x = 10;
	int b = 10;
	int result = 0;
	#pragma omp target map(to:a,x) map(tofrom:b) map(from:result)
	{
		b = 20;
		result = a * x + b;
	}
	printf("%d * %d + %d = %d.\n", a, x, b, result);

	return EXIT_SUCCESS;
}
