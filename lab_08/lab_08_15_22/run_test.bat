@echo off
cls
echo NEGATIVES

echo neg_01_test
app.exe a func_tests/neg_01_in.txt func_tests/neg_01_1_in.txt out.txt
fc out.txt func_tests/neg_01_out.txt
if errorlevel 0 (echo PASSED!) else (echo Failed!)
pause
echo neg_20_test
app.exe a func_tests/neg_01_1_in.txt func_tests/neg_01_in.txt out.txt
fc out.txt func_tests/neg_01_out.txt
if errorlevel 0 (echo PASSED!) else (echo Failed!)
pause

echo neg_21_test
app.exe m func_tests/neg_01_in.txt func_tests/neg_01_1_in.txt out.txt
fc out.txt func_tests/neg_01_out.txt
if errorlevel 0 (echo PASSED!) else (echo Failed!)
pause
echo neg_22_test
app.exe m func_tests/neg_01_1_in.txt func_tests/neg_01_in.txt out.txt
fc out.txt func_tests/neg_01_out.txt
if errorlevel 0 (echo PASSED!) else (echo Failed!)
pause

echo neg_23_test
app.exe o func_tests/neg_01_in.txt out.txt
fc out.txt func_tests/neg_01_out.txt
if errorlevel 0 (echo PASSED!) else (echo Failed!)
pause


echo neg_02_test
app.exe a func_tests/neg_02_in.txt func_tests/neg_02_1_in.txt out.txt
fc out.txt func_tests/neg_02_out.txt
if errorlevel 0 (echo PASSED!) else (echo Failed!)
pause
echo neg_24_test
app.exe a func_tests/neg_02_1_in.txt func_tests/neg_02_in.txt out.txt
fc out.txt func_tests/neg_02_out.txt
if errorlevel 0 (echo PASSED!) else (echo Failed!)
pause

echo neg_25_test
app.exe m func_tests/neg_02_in.txt func_tests/neg_02_1_in.txt out.txt
fc out.txt func_tests/neg_02_out.txt
if errorlevel 0 (echo PASSED!) else (echo Failed!)
pause
echo neg_26_test
app.exe m func_tests/neg_02_1_in.txt func_tests/neg_02_in.txt out.txt
fc out.txt func_tests/neg_02_out.txt
if errorlevel 0 (echo PASSED!) else (echo Failed!)
pause

echo neg_27_test
app.exe o func_tests/neg_02_in.txt out.txt
fc out.txt func_tests/neg_01_out.txt
if errorlevel 0 (echo PASSED!) else (echo Failed!)
pause

echo neg_03_test
app.exe a func_tests/neg_03_in.txt func_tests/neg_03_1_in.txt out.txt 
fc out.txt func_tests/neg_03_out.txt
if errorlevel 0 (echo PASSED!) else (echo Failed!)
pause
echo neg_04_test
app.exe m func_tests/neg_04_in.txt func_tests/neg_04_1_in.txt out.txt 
fc out.txt func_tests/neg_04_out.txt
if errorlevel 0 (echo PASSED!) else (echo Failed!)
pause
echo neg_05_test
app.exe o func_tests/neg_05_in.txt out.txt 
fc out.txt func_tests/neg_05_out.txt
if errorlevel 0 (echo PASSED!) else (echo Failed!)
pause
echo neg_06_test
app.exe a func_tests/neg_06_in.txt func_tests/neg_04_1_in.txt out.txt 
fc out.txt func_tests/neg_06_out.txt
if errorlevel 0 (echo PASSED!) else (echo Failed!)
pause
echo neg_07_test
app.exe m func_tests/neg_07_in.txt func_tests/neg_07_1_in.txt out.txt 
fc out.txt func_tests/neg_07_out.txt
if errorlevel 0 (echo PASSED!) else (echo Failed!)
pause
echo neg_08_test
app.exe o func_tests/neg_08_in.txt out.txt 
fc out.txt func_tests/neg_08_out.txt
if errorlevel 0 (echo PASSED!) else (echo Failed!)
pause
echo neg_09_test
app.exe a func_tests/neg_09_in.txt func_tests/neg_09_1_in.txt out.txt 
fc out.txt func_tests/neg_09_out.txt
if errorlevel 0 (echo PASSED!) else (echo Failed!)
pause
echo neg_10_test
app.exe m func_tests/neg_10_in.txt func_tests/neg_10_1_in.txt out.txt 
fc out.txt func_tests/neg_10_out.txt
if errorlevel 0 (echo PASSED!) else (echo Failed!)
pause
echo neg_11_test
app.exe o func_tests/neg_11_in.txt out.txt 
fc out.txt func_tests/neg_11_out.txt
if errorlevel 0 (echo PASSED!) else (echo Failed!)
pause
echo neg_12_test
app.exe a func_tests/neg_12_in.txt func_tests/neg_12_1_in.txt out.txt 
fc out.txt func_tests/neg_12_out.txt
if errorlevel 0 (echo PASSED!) else (echo Failed!)
pause
echo neg_13_test
app.exe m func_tests/neg_13_in.txt func_tests/neg_13_1_in.txt out.txt 
fc out.txt func_tests/neg_13_out.txt
if errorlevel 0 (echo PASSED!) else (echo Failed!)
pause
echo neg_14_test
app.exe o func_tests/neg_14_in.txt out.txt 
fc out.txt func_tests/neg_14_out.txt
if errorlevel 0 (echo PASSED!) else (echo Failed!)
pause
echo neg_15_test
app.exe o func_tests/neg_15_in.txt out.txt 
fc out.txt func_tests/neg_15_out.txt
if errorlevel 0 (echo PASSED!) else (echo Failed!)
pause
echo neg_16_test
app.exe m func_tests/neg_16_in.txt 
fc out.txt func_tests/neg_16_out.txt
if errorlevel 0 (echo PASSED!) else (echo Failed!)
pause
echo neg_17_test
app.exe m func_tests/neg_17_in.txt func_tests/neg_17_1_in.txt out.txt oiy u
fc out.txt func_tests/neg_17_out.txt
if errorlevel 0 (echo PASSED!) else (echo Failed!)
pause
echo neg_18_test
app.exe dg func_tests/neg_18_in.txt func_tests/neg_18_1_in.txt out.txt 
fc out.txt func_tests/neg_18_out.txt
if errorlevel 0 (echo PASSED!) else (echo Failed!)
pause
echo neg_19_test
app.exe 13 func_tests/neg_19_in.txt func_tests/neg_19_1_in.txt out.txt 
fc out.txt func_tests/neg_19_out.txt
if errorlevel 0 (echo PASSED!) else (echo Failed!)
pause


echo POSITIVE

app.exe a func_tests/pos_01_in.txt func_tests/pos_01_1_in.txt out.txt
fc out.txt func_tests/pos_01_out.txt
pause
app.exe a func_tests/pos_02_in.txt func_tests/pos_02_1_in.txt out.txt
fc out.txt func_tests/pos_02_out.txt
pause

app.exe a func_tests/pos_03_in.txt func_tests/pos_03_1_in.txt out.txt
fc out.txt func_tests/pos_03_out.txt
pause
app.exe m func_tests/pos_04_in.txt func_tests/pos_04_1_in.txt out.txt
fc out.txt func_tests/pos_04_out.txt
pause

app.exe m func_tests/pos_05_in.txt func_tests/pos_05_1_in.txt out.txt
fc out.txt func_tests/pos_05_out.txt
pause
app.exe m func_tests/pos_06_in.txt func_tests/pos_06_1_in.txt out.txt
fc out.txt func_tests/pos_06_out.txt
pause
app.exe m func_tests/pos_10_in.txt func_tests/pos_10_1_in.txt out.txt
fc out.txt func_tests/pos_10_out.txt
pause
app.exe m func_tests/pos_11_in.txt func_tests/pos_11_1_in.txt out.txt
fc out.txt func_tests/pos_11_out.txt
pause

app.exe o func_tests/pos_07_in.txt out.txt
fc out.txt func_tests/pos_07_out.txt
pause
app.exe o func_tests/pos_08_in.txt out.txt
fc out.txt func_tests/pos_08_out.txt
pause
app.exe o func_tests/pos_09_in.txt out.txt
fc out.txt func_tests/pos_09_out.txt
pause