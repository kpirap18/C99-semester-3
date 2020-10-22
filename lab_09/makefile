CC = gcc
INC = ./inc/
OUT = ./out/
SRC = ./src/
UNIT = ./unit_tests/
CFLAGS = -pedantic -Wall -Werror -Wextra -Wvla -Wfloat-equal -Wfloat-conversion -std=c99

INCFILE := $(wildcard $(INC)*.h)

OBJS = $(OUT)io.o $(OUT)initializmatrix.o $(OUT)operationmatrix.o
OBJS_UNIT = $(OUT)check_main.o $(OUT)check_multi_matrix.o $(OUT)check_null_matrix.o $(OUT)check_null_one_matrix.o \
$(OUT)check_read_info_mat.o $(OUT)check_read_matrix.o $(OUT)check_sum_matrix.o

debug : CFLAGS += -g3
debug : app.exe

release : CFLAGS += -DNDEBUG -g0
release : app.exe

app.exe: $(OBJS) $(OUT)main.o
	$(CC) $^ -o $@
unit_tests.exe: $(OBJS) $(OBJS_UNIT)
	$(CC) $^ -lcheck -o $@
	
$(OUT)main.o: $(SRC)main.c $(INCFILE)
	cd out && $(CC) $(CFLAGS) -c ../$<
$(OUT)io.o: $(SRC)io.c $(INCFILE)
	cd out && $(CC) $(CFLAGS) -c ../$<
$(OUT)initializmatrix.o: $(SRC)initializmatrix.c $(INCFILE)
	cd out && $(CC) $(CFLAGS) -c ../$<
$(OUT)operationmatrix.o: $(SRC)operationmatrix.c $(INCFILE)
	cd out && $(CC) $(CFLAGS) -c ../$<

$(OUT)check_main.o: $(UNIT)check_main.c $(INCFILE)
	cd out && $(CC) $(CFLAGS) -c ../$<
$(OUT)check_multi_matrix.o: $(UNIT)check_multi_matrix.c $(INCFILE)
	cd out && $(CC) $(CFLAGS) -c ../$<
$(OUT)check_null_matrix.o: $(UNIT)check_null_matrix.c $(INCFILE)
	cd out && $(CC) $(CFLAGS) -c ../$<
$(OUT)check_null_one_matrix.o: $(UNIT)check_null_one_matrix.c $(INCFILE)
	cd out && $(CC) $(CFLAGS) -c ../$<
$(OUT)check_read_info_mat.o: $(UNIT)check_read_info_mat.c $(INCFILE)
	cd out && $(CC) $(CFLAGS) -c ../$<
$(OUT)check_read_matrix.o: $(UNIT)check_read_matrix.c $(INCFILE)
	cd out && $(CC) $(CFLAGS) -c ../$<
$(OUT)check_sum_matrix.o: $(UNIT)check_sum_matrix.c $(INCFILE)
	cd out && $(CC) $(CFLAGS) -c ../$<
	

run_unit_dr: unit_tests.exe
	drmemory -lib_blacklist "*" -batch -- unit_tests.exe

run_app_dr: app.exe
	drmemory -lib_blacklist "*" -batch -- app.exe
run_func_dr: app.exe
	drmemory -lib_blacklist "*" -batch -- ./app.exe a func_tests/pos_01_in.txt func_tests/pos_01_1_in.txt out.txt
	drmemory -lib_blacklist "*" -batch -- ./app.exe a func_tests/pos_02_in.txt func_tests/pos_02_1_in.txt out.txt
	drmemory -lib_blacklist "*" -batch -- ./app.exe a func_tests/pos_03_in.txt func_tests/pos_03_1_in.txt out.txt
	drmemory -lib_blacklist "*" -batch -- ./app.exe m func_tests/pos_04_in.txt func_tests/pos_04_1_in.txt out.txt
	drmemory -lib_blacklist "*" -batch -- ./app.exe m func_tests/pos_05_in.txt func_tests/pos_05_1_in.txt out.txt
	drmemory -lib_blacklist "*" -batch -- ./app.exe m func_tests/pos_06_in.txt func_tests/pos_06_1_in.txt out.txt
	drmemory -lib_blacklist "*" -batch -- ./app.exe o func_tests/pos_07_in.txt out.txt
	drmemory -lib_blacklist "*" -batch -- ./app.exe o func_tests/pos_08_in.txt out.txt
	drmemory -lib_blacklist "*" -batch -- ./app.exe a func_tests/neg_01_in.txt func_tests/neg_01_1_in.txt out.txt; true
	drmemory -lib_blacklist "*" -batch -- ./app.exe a func_tests/neg_01_1_in.txt func_tests/neg_01_in.txt out.txt; true
	drmemory -lib_blacklist "*" -batch -- ./app.exe m func_tests/neg_01_in.txt func_tests/neg_01_1_in.txt out.txt; true
	drmemory -lib_blacklist "*" -batch -- ./app.exe m func_tests/neg_01_1_in.txt func_tests/neg_01_in.txt out.txt; true
	drmemory -lib_blacklist "*" -batch -- ./app.exe o func_tests/neg_01_in.txt out.txt; true
	drmemory -lib_blacklist "*" -batch -- ./app.exe a func_tests/neg_02_in.txt func_tests/neg_02_1_in.txt out.txt; true
	drmemory -lib_blacklist "*" -batch -- ./app.exe a func_tests/neg_02_1_in.txt func_tests/neg_02_in.txt out.txt; true
	drmemory -lib_blacklist "*" -batch -- ./app.exe m func_tests/neg_02_in.txt func_tests/neg_02_1_in.txt out.txt; true
	drmemory -lib_blacklist "*" -batch -- ./app.exe m func_tests/neg_02_1_in.txt func_tests/neg_02_in.txt out.txt; true
	drmemory -lib_blacklist "*" -batch -- ./app.exe o func_tests/neg_02_in.txt out.txt; true
	drmemory -lib_blacklist "*" -batch -- ./app.exe a func_tests/neg_03_in.txt func_tests/neg_03_1_in.txt out.txt; true
	drmemory -lib_blacklist "*" -batch -- ./app.exe m func_tests/neg_04_in.txt func_tests/neg_04_1_in.txt out.txt; true
	drmemory -lib_blacklist "*" -batch -- ./app.exe o func_tests/neg_05_in.txt out.txt; true
	drmemory -lib_blacklist "*" -batch -- ./app.exe a func_tests/neg_06_in.txt func_tests/neg_04_1_in.txt out.txt; true
	drmemory -lib_blacklist "*" -batch -- ./app.exe m func_tests/neg_07_in.txt func_tests/neg_07_1_in.txt out.txt; true
	drmemory -lib_blacklist "*" -batch -- ./app.exe o func_tests/neg_08_in.txt out.txt; true
	drmemory -lib_blacklist "*" -batch -- ./app.exe a func_tests/neg_09_in.txt func_tests/neg_09_1_in.txt out.txt; true
	drmemory -lib_blacklist "*" -batch -- ./app.exe m func_tests/neg_10_in.txt func_tests/neg_10_1_in.txt out.txt; true
	drmemory -lib_blacklist "*" -batch -- ./app.exe o func_tests/neg_11_in.txt out.txt; true
	drmemory -lib_blacklist "*" -batch -- ./app.exe a func_tests/neg_12_in.txt func_tests/neg_12_1_in.txt out.txt; true
	drmemory -lib_blacklist "*" -batch -- ./app.exe m func_tests/neg_13_in.txt func_tests/neg_13_1_in.txt out.txt; true
	drmemory -lib_blacklist "*" -batch -- ./app.exe o func_tests/neg_14_in.txt out.txt; true
	drmemory -lib_blacklist "*" -batch -- ./app.exe o func_tests/neg_15_in.txt out.txt; true
	drmemory -lib_blacklist "*" -batch -- ./app.exe m func_tests/neg_16_in.txt; true
	drmemory -lib_blacklist "*" -batch -- ./app.exe m func_tests/neg_17_in.txt func_tests/neg_17_1_in.txt out.txt oiy u; true
	drmemory -lib_blacklist "*" -batch -- ./app.exe dg func_tests/neg_18_in.txt func_tests/neg_18_1_in.txt out.txt; true
	drmemory -lib_blacklist "*" -batch -- ./app.exe 13 func_tests/neg_19_in.txt func_tests/neg_19_1_in.txt out.txt; true

.PHONY : clean debug release
clean :
	$(RM) $(OUT)*.o *.exe
