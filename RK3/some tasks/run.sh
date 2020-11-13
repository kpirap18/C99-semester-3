#!/bin/sh

echo "TEST 01 START"
./app.exe func_tests/pos_01_in.txt out.txt p
if cmp -s "func_tests/pos_01_out.txt" "out.txt"; then
	echo "Test 01 COMPLETED"
	read -p "Press any key to continue"
else
	echo "Test 01 FAILED"
	read -p "Press any key to continue"
fi
rm results.txt
echo
