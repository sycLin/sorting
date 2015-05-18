all:
	gcc test_gen.c -o test_gen
	gcc qsort.c -o qsort
	gcc merge_sort.c -o merge_sort
clean:
	rm -f test_gen qsort merge_sort
