#!/bin/bash

test1=100
test2=10000
test3=1000000
test4=100000000
test5=999999999

exe1=qsort
exe2=merge_sort
exe3=test_gen

echo "--- preparation ---"
echo "creating executable files through makefile..."

make > /dev/null 2>&1

if test -e ./$exe1; then
	echo "executable file: $exe1 created successfully"
fi
if test -e ./$exe2; then
	echo "executable file: $exe2 created successfully"
fi
if test -e ./$exe3; then
	echo "executable file: $exe3 created successfully"
fi


echo "--- first test ---"
echo "test size = $test1"
echo "generating test data ..."
./test_gen $test1 > tmp_test_data_small
echo "test data file: tmp_test_data_small created successfully"
echo "running merge sort..."
./merge_sort < tmp_test_data_small > merge_sort.out
echo "running qsort..."
./qsort < tmp_test_data_small > qsort.out
echo "checking correctness..."
string="`diff merge_sort.out qsort.out`"
if [ $string=="" ]; then
	echo "##### TEST PASSED! #####"
else
	echo "##### TEST FAILED! #####"
fi

echo "--- second test ---"
echo "test size = $test2"
echo "generating test data ..."
./test_gen $test2 > tmp_test_data_medium
echo "test data file: tmp_test_data_medium created successfully"
echo "running merge sort..."
./merge_sort < tmp_test_data_medium > merge_sort.out
echo "running qsort..."
./qsort < tmp_test_data_medium > qsort.out
echo "checking correctness..."
string="`diff merge_sort.out qsort.out`"
if [ $string=="" ]; then
	echo "##### TEST PASSED! #####"
else
	echo "##### TEST FAILED! #####"
fi

echo "--- third test ---"
echo "test size = $test3"
echo "generating test data ..."
./test_gen $test3 > tmp_test_data_large
echo "test data file: tmp_test_data_large created successfully"
echo "running merge sort..."
./merge_sort < tmp_test_data_large > merge_sort.out
echo "running qsort..."
./qsort < tmp_test_data_large > qsort.out
echo "checking correctness..."
string="`diff merge_sort.out qsort.out`"
if [ $string=="" ]; then
	echo "##### TEST PASSED! #####"
else
	echo "##### TEST FAILED! #####"
fi

echo "--- clean up ---"
echo "deleting all executable files through make clean"
make clean > /dev/null 2>&1
echo "deleting all test data"
rm -f tmp_test_data*
echo "deleting all test output"
rm -f qsort.out merge_sort.out

echo "--- done ---"
