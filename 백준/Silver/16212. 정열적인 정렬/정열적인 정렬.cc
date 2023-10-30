#define _CRT_SECURE_NO_WARNINGS
#include <cstdio>

int n;
int arr[500'005], temp[500'005];

void merge(int l, int m, int r) {
	register int i = l, j = m + 1, k = l;

	while (i <= m && j <= r) 
		temp[k++] = arr[i] <= arr[j] ? arr[i++] : arr[j++];

	if (i > m)
		while (j <= r)
			temp[k++] = arr[j++];

	if (j > r)
		while (i <= m)
			temp[k++] = arr[i++];
	
	for (k = l; k <= r; ++k)
		arr[k] = temp[k];
}

void merge_sort(int l, int r) {
	if (l < r) {
		int m = (l + r) >> 1;
		merge_sort(l, m);
		merge_sort(m + 1, r);
		merge(l, m, r);
	}
}

int main() {
	scanf("%d", &n);

	for (int i = 0; i < n; ++i)
		scanf("%d", arr + i);

	merge_sort(0, n - 1);
	
	for (int i = 0; i < n; ++i)
		printf("%d ", arr[i]);

	return 0;
}