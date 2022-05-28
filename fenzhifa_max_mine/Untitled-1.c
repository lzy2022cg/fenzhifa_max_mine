#include <stdio.h>
#include <stdlib.h>
#define MAX(a,b) a>b ? a:b
#define MINE(a,b) a<b ? a:b
int max_value(int a[], int m, int n);
int mine_value(int a[], int m, int n);
int main(void)
{
	int i, number, * ptr,m, n;

	printf("Input the number of array elements : ");
	scanf("%d", &number);
	if ((ptr = (int*)calloc(number, sizeof(int))) == 0) {
		printf("Not able to allocate memory");
		exit(1);
	}
	printf("Input array element:");
	for (i = 0; i < number; i++) {
		scanf("%d", ptr + i);
	}
	m = 0, n = number - 1;
	printf("max_value:%d\n", max_value(ptr,m,n));
	printf("mine_value:%d", mine_value(ptr,m,n));
	free(ptr);

	return 0;
}
int max_value(int a[], int m, int n)
{
	int mid, left, right;

	if (m == n) {
		return MAX(a[m], a[n]);
	}
	else if (m == n - 1) {
		return MAX(a[m], a[n]);
	}
	else {
		mid = (m + n) / 2;
		left = max_value(a, m, mid);
		right = max_value(a, mid, n);
		return MAX(left, right);
	}
}
int mine_value(int a[], int m, int n)
{
	int mid, left, right;

	if (m == n) {
		return MINE(a[m], a[n]);
	}
	else if (m == n - 1) {
		return MINE(a[m], a[n]);
	}
	else {
		mid = (m + n) / 2;
		left = mine_value(a, m, mid);
		right = mine_value(a, mid, n);
		return MINE(left, right);
	}
}