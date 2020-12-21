@echo off
cls
NUL> out.txt
echo NEGATIVES
echo neg_01_test
app.exe func_tests/neg_01_in.txt out.txt
fc out.txt func_tests/neg_01_out.txt
if errorlevel 0 (echo PASSED!) else (echo Failed!)
pause
echo neg_02_test
app.exe func_tests/neg_02_in.txt out.txt f
fc out.txt func_tests/neg_02_out.txt
if errorlevel 0 (echo PASSED!) else (echo Failed!)
pause
echo neg_03_test
app.exe func_tests/neg_03_in.txt out.txt f
fc out.txt func_tests/neg_03_out.txt
if errorlevel 0 (echo PASSED!) else (echo Failed!)
pause
echo neg_04_test
app.exe func_tests/neg_04_in.txt out.txt f
fc out.txt func_tests/neg_04_out.txt
if errorlevel 0 (echo PASSED!) else (echo Failed!)
pause
echo neg_05_test
app.exe func_tests/neg_05_in.txt out.txt f
fc out.txt func_tests/neg_05_out.txt
if errorlevel 0 (echo PASSED!) else (echo Failed!)
pause
echo neg_06_test
app.exe func_tests/neg_06_in.txt out.txt f
fc out.txt func_tests/neg_06_out.txt
if errorlevel 0 (echo PASSED!) else (echo Failed!)
pause
echo neg_07_test
app.exe func_tests/neg_07_in.txt out.txt f
fc out.txt func_tests/neg_07_out.txt
if errorlevel 0 (echo PASSED!) else (echo Failed!)
pause
echo neg_08_test
app.exe func_tests/neg_08_in.txt out.txt f
fc out.txt func_tests/neg_08_out.txt
if errorlevel 0 (echo PASSED!) else (echo Failed!)
pause
echo neg_09_test
app.exe func_tests/neg_09_in.txt out.txt f
fc out.txt func_tests/neg_09_out.txt
if errorlevel 0 (echo PASSED!) else (echo Failed!)
pause
echo neg_10_test
app.exe func_tests/neg_10_in.txt out.txt f
fc out.txt func_tests/neg_10_out.txt
if errorlevel 0 (echo PASSED!) else (echo Failed!)
pause


app.exe func_tests/pos_01_in.txt out.txt
fc out.txt func_tests/pos_01_out.txt
if errorlevel 0 (echo PASSED!) else (echo Failed!)
pause
app.exe func_tests/pos_02_in.txt out.txt f
fc out.txt func_tests/pos_02_out.txt
if errorlevel 0 (echo PASSED!) else (echo Failed!)
pause
app.exe func_tests/pos_03_in.txt out.txt
fc out.txt func_tests/pos_03_out.txt
if errorlevel 0 (echo PASSED!) else (echo Failed!)
pause
app.exe func_tests/pos_04_in.txt out.txt
fc out.txt func_tests/pos_04_out.txt
if errorlevel 0 (echo PASSED!) else (echo Failed!)
pause

app.exe func_tests/pos_05_in.txt out.txt
fc out.txt func_tests/pos_05_out.txt
if errorlevel 0 (echo PASSED!) else (echo Failed!)
pause
app.exe func_tests/pos_06_in.txt out.txt f
fc out.txt func_tests/pos_06_out.txt
if errorlevel 0 (echo PASSED!) else (echo Failed!)
pause

app.exe func_tests/pos_07_in.txt out.txt
fc out.txt func_tests/pos_07_out.txt
if errorlevel 0 (echo PASSED!) else (echo Failed!)
pause
app.exe func_tests/pos_08_in.txt out.txt f
fc out.txt func_tests/pos_08_out.txt
if errorlevel 0 (echo PASSED!) else (echo Failed!)
rm out.txt
pause
