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
int lb(int a[], int s, int e, int k)
{
	int m;
	while (e > s) {
		m = (s + e) / 2;
		if (a[m] < k) s = m + 1;
		else e = m;
	}
	return e + 1;
}

int ub(int a[], int s, int e, int k)
{
	int m;
	while (e > s) {
		m = (s + e) / 2;
		if (a[m] <= k)s = m + 1;
		else e = m;
	}
	return e + 1;
}

void main(void)
{
	int i;

	int a[] = { 1,-1,0, 6,5 ,5,7,8};

	printf("origin value:{");
	for (i = 0; i < 5; i++) {
		printf(",%d", a[i]);
	}
	printf("}\n");

	quickSort(a, 0, 7);


	printf("sorted value:{");
	for (i = 0; i <=8; i++) {
		printf(",%d", a[i]);
	}
	printf("}\n");


	int k = 5;
	//lower bound 
	int val = lb(a, 0, 8, k);
	printf("lb value:%d\n", val);
	
	//upper bound
	val = ub(a, 0, 8, k);
	printf("ub value:%d\n", val);

}