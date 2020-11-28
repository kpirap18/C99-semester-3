#!/bin/sh

echo "NEGATIVE"
echo "TEST 01 START"
./app.exe func_tests/neg_in_01.txt out.txt p
if cmp -s "func_tests/neg_out_01.txt" "out.txt"; then
	echo "Test 01 COMPLETED"
	read -p "Press something to continue"
else
	echo "Test 01 FAILED"
	read -p "Press something to continue"
fi

echo "TEST 02 START"
./app.exe func_tests/neg_in_02.txt out.txt s
if cmp -s "func_tests/neg_out_02.txt" "out.txt"; then
	echo "Test 02 COMPLETED"
	read -p "Press something to continue"
else
	echo "Test 02 FAILED"
	read -p "Press something to continue"
fi

echo "TEST 03 START"
./app.exe func_tests/neg_in_03.txt out.txt r
if cmp -s "func_tests/neg_out_03.txt" "out.txt"; then
	echo "Test 03 COMPLETED"
	read -p "Press something to continue"
else
	echo "Test 03 FAILED"
	read -p "Press something to continue"
fi

echo "TEST 04 START"
./app.exe func_tests/neg_in_04.txt out.txt p
if cmp -s "func_tests/neg_out_04.txt" "out.txt"; then
	echo "Test 04 COMPLETED"
	read -p "Press something to continue"
else
	echo "Test 04 FAILED"
	read -p "Press something to continue"
fi

echo "TEST 05 START"
./app.exe func_tests/neg_in_05.txt out.txt p
if cmp -s "func_tests/neg_out_05.txt" "out.txt"; then
	echo "Test 05 COMPLETED"
	read -p "Press something to continue"
else
	echo "Test 05 FAILED"
	read -p "Press something to continue"
fi

echo "TEST 06 START"
./app.exe func_tests/neg_in_06.txt out.txt s
if cmp -s "func_tests/neg_out_06.txt" "out.txt"; then
	echo "Test 06 COMPLETED"
	read -p "Press something to continue"
else
	echo "Test 06 FAILED"
	read -p "Press something to continue"
fi

echo "TEST 07 START"
./app.exe func_tests/neg_in_07.txt out.txt r
if cmp -s "func_tests/neg_out_07.txt" "out.txt"; then
	echo "Test 07 COMPLETED"
	read -p "Press something to continue"
else
	echo "Test 07 FAILED"
	read -p "Press something to continue"
fi

echo "TEST 08 START"
./app.exe func_tests/neg_in_08.txt out.txt 
if cmp -s "func_tests/neg_out_08.txt" "out.txt"; then
	echo "Test 08 COMPLETED"
	read -p "Press something to continue"
else
	echo "Test 08 FAILED"
	read -p "Press something to continue"
fi

echo "TEST 02\9 START"
./app.exe func_tests/neg_in_09.txt out.txt j k j k
if cmp -s "func_tests/neg_out_09.txt" "out.txt"; then
	echo "Test 09 COMPLETED"
	read -p "Press something to continue"
else
	echo "Test 09 FAILED"
	read -p "Press something to continue"
fi

echo "TEST 10 START"
./app.exe func_tests/neg_in_10.txt out.txt i 8
if cmp -s "func_tests/neg_out_10.txt" "out.txt"; then
	echo "Test 10 COMPLETED"
	read -p "Press something to continue"
else
	echo "Test 10 FAILED"
	read -p "Press something to continue"
fi


echo "TEST 11 START"
./app.exe func_tests/neg_in_11.txt out.txt i 6 g
if cmp -s "func_tests/neg_out_11.txt" "out.txt"; then
	echo "Test 11 COMPLETED"
	read -p "Press something to continue"
else
	echo "Test 11 FAILED"
	read -p "Press something to continue"
fi

echo "TEST 12 START"
./app.exe func_tests/neg_in_12.txt out.txt i j 9
if cmp -s "func_tests/neg_out_12.txt" "out.txt"; then
	echo "Test 12 COMPLETED"
	read -p "Press something to continue"
else
	echo "Test 12 FAILED"
	read -p "Press something to continue"
fi

