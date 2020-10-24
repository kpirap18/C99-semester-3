#!/bin/sh

echo POSITIVES
echo POS_01
./app.exe func_tests/pos_01_in.txt year > out.txt
if cmp -s out.txt func_tests/pos_01_out.txt ; then
 echo OK
fi

echo POS_02
./app.exe func_tests/pos_02_in.txt title > out.txt
if cmp -s out.txt func_tests/pos_02_out.txt ; then
 echo OK
fi

echo POS_03
./app.exe func_tests/pos_03_in.txt name > out.txt
if cmp -s out.txt func_tests/pos_03_out.txt ; then
 echo OK
fi

echo POS_04
./app.exe func_tests/pos_04_in.txt year > out.txt
if cmp -s out.txt func_tests/pos_04_out.txt ; then
 echo OK
fi

echo POS_05
./app.exe func_tests/pos_05_in.txt year 2017> out.txt
if cmp -s out.txt func_tests/pos_05_out.txt ; then
 echo OK
fi

echo POS_06
./app.exe func_tests/pos_06_in.txt title Avatar > out.txt
if cmp -s out.txt func_tests/pos_06_out.txt ; then
 echo OK
fi

echo POS_07
./app.exe func_tests/pos_07_in.txt name "James Cameron" > out.txt
if cmp -s out.txt func_tests/pos_07_out.txt ; then
 echo OK
fi

echo POS_08
./app.exe func_tests/pos_08_in.txt year 1984 > out.txt
if cmp -s out.txt func_tests/pos_08_out.txt ; then
 echo OK
fi

echo POS_09
./app.exe func_tests/pos_09_in.txt title "The Terminal" > out.txt
if cmp -s out.txt func_tests/pos_09_out.txt ; then
 echo OK
fi

echo POS_10
./app.exe func_tests/pos_10_in.txtname "Olivier Nakache" > out.txt
if cmp -s out.txt func_tests/pos_10_out.txt ; then
 echo OK
fi

echo POS_11
./app.exe func_tests/pos_11_in.txt year 2020 > out.txt
if cmp -s out.txt func_tests/pos_11_out.txt ; then
 echo OK
fi

echo POS_12
./app.exe func_tests/pos_12_in.txt title AdM > out.txt
if cmp -s out.txt func_tests/pos_12_out.txt ; then
 echo OK
fi

echo POS_13
./app.exe func_tests/pos_13_in.txt name Fedor > out.txt
if cmp -s out.txt func_tests/pos_13_out.txt ; then
 echo OK
fi

echo POS_14
./app.exe func_tests/pos_14_in.txt year > out.txt
if cmp -s out.txt func_tests/pos_14_out.txt ; then
 echo OK
fi

echo POS_15
./app.exe func_tests/pos_15_in.txt year > out.txt
if cmp -s out.txt func_tests/pos_15_out.txt ; then
 echo OK
fi

echo NEGATIVES
echo NEG_01
./app.exe func_tests/neg_01_in.txt year > out.txt
if cmp -s out.txt func_tests/neg_01_out.txt ; then
 echo OK
fi

echo NEG_02
./app.exe func_tests/neg_02_in.txt year > out.txt
if cmp -s out.txt func_tests/neg_02_out.txt ; then
 echo OK
fi

echo NEG_03
./app.exe func_tests/neg_03_in.txt year > out.txt
if cmp -s out.txt func_tests/neg_03_out.txt ; then
 echo OK
fi

echo NEG_04
./app.exe func_tests/neg_04_in.txt year > out.txt
if cmp -s out.txt func_tests/neg_04_out.txt ; then
 echo OK
fi

echo NEG_05
./app.exe func_tests/neg_05_in.txt year > out.txt
if cmp -s out.txt func_tests/neg_05_out.txt ; then
 echo OK
fi

echo NEG_07
./app.exe func_tests/neg_07_in.txt year > out.txt
if cmp -s out.txt func_tests/neg_07_out.txt ; then
 echo OK
fi

echo NEG_08
./app.exe func_tests/neg_08_in.txt year > out.txt
if cmp -s out.txt func_tests/neg_08_out.txt ; then
 echo OK
fi

echo NEG_09
./app.exe func_tests/neg_09_in.txt year 0> out.txt
if cmp -s out.txt func_tests/neg_09_out.txt ; then
 echo OK
fi

echo NEG_10
./app.exe func_tests/neg_10_in.txt year ee> out.txt
if cmp -s out.txt func_tests/neg_10_out.txt ; then
 echo OK
fi

echo NEG_11
./app.exe func_tests/neg_11_in.txt year -4> out.txt
if cmp -s out.txt func_tests/neg_11_out.txt ; then
 echo OK
fi

echo NEG_12
./app.exe func_tests/neg_12_in.txt year asd ASD qww> out.txt
if cmp -s out.txt func_tests/neg_12_out.txt ; then
 echo OK
fi

echo NEG_13
./app.exe > out.txt
if cmp -s out.txt func_tests/neg_13_out.txt ; then
 echo OK
fi

echo NEG_14
./app.exe func_tests/neg_14_in.txt years > out.txt
if cmp -s out.txt func_tests/neg_14_out.txt ; then
 echo OK
fi
