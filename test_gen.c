#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_VALUE 100000000

int main(int argc, char* argv[]) {
	int i, tmp, N = 1000;
	// user could set the parameter through command-line arguments
	if(argc > 1) {
		N = atoi(argv[1]);
	}
	printf("%d\n", N);
	for(i=0; i<N; i++) {
		tmp = rand()%MAX_VALUE;
		printf("%d ", tmp);
	}
	printf("\n");
	return 0;
}
