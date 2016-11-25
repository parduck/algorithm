#include <stdio.h>

void main(void)
{
	int i;

	int a[] = { 1,-1,0, 6,5 };

	printf("origin value:{");
	for (i = 0; i < 5; i++) {
		printf(",%d", a[i]);
	}
	printf("}\n");


	printf("sorted value:{");
	for (i = 0; i < 5; i++) {
		printf(",%d", a[i]);
	}
	printf("}\n");
}