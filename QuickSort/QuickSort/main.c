#include <stdio.h>

//
void quickSort(int a[], int l, int r)
{
	if (l < r) {
		int pivot, s, e;
		int tmp;

		// partitioning
		pivot = a[l];
		s = l + 1;
		e = r;

		while (s <= e) {
			while (s <= r && a[s] <= pivot) s++;
			while (e >= l + 1 && a[e] >= pivot) e--;

			if (s < e) {
				tmp = a[s]; a[s] = a[e]; a[e] = tmp;
			}
		}

		tmp = a[e]; a[e] = pivot; a[l] = tmp;


		quickSort(a, l, e - 1);
		quickSort(a, e + 1, r);
	}
}

void main(void)
{
	int i;

	int a[] = { 1,-1,0, 6,5 };

	printf("origin value:{");
	for (i = 0; i < 5; i++) {
		printf(",%d", a[i]);
	}
	printf("}\n");

	quickSort(a, 0, 4);


	printf("sorted value:{");
	for (i = 0; i < 5; i++) {
		printf(",%d", a[i]);
	}
	printf("}\n");
}