#!/bin/sh

echo "POSITIVE"
for i in {01..9}; do
	echo "TEST $i START"
	touch out.txt
	./app.exe < func_tests/pos_in_$i.txt > out.txt
	if cmp -s "func_tests/pos_out_$i.txt" "out.txt"; then
		echo "Test $i COMPLETED"
		read -p "Press something to continue"
	else
		echo "Test $i FAILED"
		read -p "Press something to continue"
	fi
	rm out.txt
	echo
done