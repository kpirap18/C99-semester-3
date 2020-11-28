#!/bin/sh

echo "NEG"
echo "TEST 01 START"
./app.exe func_tests/neg_01_in.txt > out.txt
if cmp -s "func_tests/neg_01_out.txt" "out.txt"; then
	echo "Test 01 COMPLETED"
	read -p "Press any button to continue"
else
	echo "Test 01 FAILED"
	read -p "Press any button to continue"
fi
echo


echo "TEST 02 START"
./app.exe func_tests/neg_02_in.txt > out.txt
if cmp -s "func_tests/neg_02_out.txt" "out.txt"; then
	echo "Test 02 COMPLETED"
	read -p "Press any button to continue"
else
	echo "Test 02 FAILED"
	read -p "Press any button to continue"
fi
echo


echo "TEST 03 START"
./app.exe func_tests/neg_03_in.txt > out.txt
if cmp -s "func_tests/neg_03_out.txt" "out.txt"; then
	echo "Test 03 COMPLETED"
	read -p "Press any button to continue"
else
	echo "Test 03 FAILED"
	read -p "Press any button to continue"
fi
echo


echo "TEST 04 START"
./app.exe func_tests/neg_04_in.txt > out.txt
if cmp -s "func_tests/neg_04_out.txt" "out.txt"; then
	echo "Test 04 COMPLETED"
	read -p "Press any button to continue"
else
	echo "Test 04  FAILED"
	read -p "Press any button to continue"
fi
echo


echo "TEST 05 START"
./app.exe func_tests/neg_05_in.txt > out.txt
if cmp -s "func_tests/neg_05_out.txt" "out.txt"; then
	echo "Test 05 COMPLETED"
	read -p "Press any button to continue"
else
	echo "Test 05 FAILED"
	read -p "Press any button to continue"
fi
echo


echo "TEST 06 START"
./app.exe func_tests/neg_06_in.txt > out.txt
if cmp -s "func_tests/neg_06_out.txt" "out.txt"; then
	echo "Test 06 COMPLETED"
	read -p "Press any button to continue"
else
	echo "Test 06 FAILED"
	read -p "Press any button to continue"
fi
echo

echo "TEST 07 START"
./app.exe func_tests/neg_07_in.txt > out.txt
if cmp -s "func_tests/neg_07_out.txt" "out.txt"; then
	echo "Test 07 COMPLETED"
	read -p "Press any button to continue"
else
	echo "Test 07 FAILED"
	read -p "Press any button to continue"
fi
echo

echo "POS"
echo "TEST 01 START"
./app.exe func_tests/pos_01_in.txt > out.txt
if cmp -s "func_tests/pos_01_out.txt" "out.txt"; then
	echo "Test 01 COMPLETED"
	read -p "Press any button to continue"
else
	echo "Test 01 FAILED"
	read -p "Press any button to continue"
fi
echo


echo "TEST 02 START"
./app.exe func_tests/pos_02_in.txt > out.txt
if cmp -s "func_tests/pos_02_out.txt" "out.txt"; then
	echo "Test 02 COMPLETED"
	read -p "Press any button to continue"
else
	echo "Test 02 FAILED"
	read -p "Press any button to continue"
fi
echo
