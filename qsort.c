#include <stdio.h>
#include <stdlib.h>

int compare_int(const void* a, const void* b);

int main() {
	int i, N;
	if(!scanf("%d", &N)) {
		fprintf(stderr, "[Error] cannot get the number of integers!\n");
	}
	int* A = (int*)malloc(N*sizeof(int));
	for(i=0; i<N; i++) {
		scanf("%d", &A[i]);
	}
	qsort(A, N, sizeof(int), compare_int);
	for(i=0; i<N; i++)
		printf("%d ", A[i]);
	printf("\n");
	return 0;
}

int compare_int(const void* a, const void* b) {
	int A = *(int*)a;
	int B = *(int*)b;
	if(A > B)
		return 1;
	if(B > A)
		return -1;
	return 0;
}
