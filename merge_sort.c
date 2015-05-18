#include <stdio.h>
#include <stdlib.h>

// this function sorts part of the "array": from "start" to "end"
void merge_sort(int* array, int start, int end);

int main() {
	int i, tmp, N;
	int* A;
	// get the total number of integers to sort
	if(!scanf("%d", &N)) {
		fprintf(stderr, "[Error] getting the number of integers to sort.\n");
		exit(1);
	}
	// allocate the int-array
	A = (int*)malloc(N*sizeof(int));
	// get all N elements to sort
	for(i=0; i<N; i++) {
		scanf("%d", &A[i]);
	}

	// merge sort
	merge_sort(A, 0, N-1);

	// output the result
	for(i=0; i<N; i++) {
		printf("%d ", A[i]);
	}
	printf("\n");
	return 0;
}

void merge_sort(int* array, int start, int end) {
	int i;
	// terminal condition for recursion
	if(start >= end)
		return;
	// get half size of the current size
	int half_size = (end-start+1)/2;
	// recursively sort the two halfs
	merge_sort(array, start, start+half_size-1);
	merge_sort(array, start+half_size, end);
	// creat a temporary array to MERGE the 2 halfs
	int* tmp_array = (int*)malloc((end-start+1)*sizeof(int));
	// MERGE
	int L_index, R_index, tmp_index;
	L_index = start;
	R_index = start+half_size;
	tmp_index = 0;
	while(L_index <= (start+half_size-1) && R_index <= end && tmp_index <= (end-start+1)) {
		if(array[L_index] <= array[R_index]) {
			tmp_array[tmp_index++] = array[L_index++];
		} else {
			tmp_array[tmp_index++] = array[R_index++];
		}
	}
	while(L_index <= (start+half_size-1)) {
		tmp_array[tmp_index++] = array[L_index++];
	}
	while(R_index <= end) {
		tmp_array[tmp_index++] = array[R_index++];
	}
	// now copy the content in tmp_array[] to array[]
	for(i=0; i<(end-start+1); i++) {
		array[start+i] = tmp_array[i];
	}
}




