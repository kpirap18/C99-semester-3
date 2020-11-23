CC = gcc
INCPATH := ../inc/
INC := -I $(INCPATH)
OUT = ./out/
SRC = ./src/
UNIT = ./unit_tests/
CFLAGS = -pedantic -Wall -Werror -Wextra -Wvla -Wfloat-equal -Wfloat-conversion -std=gnu99


OBJS = $(OUT)io.o $(OUT)list.o $(OUT)my_getline.o $(OUT)parsing.o \
$(OUT)specialfunc.o
OBJS_UNIT = $(OUT)check_main.o  $(OUT)check_my_getline.o \
$(OUT)check_inputcommand.o $(OUT)check_inputstring.o $(OUT)check_stringtolist.o \
$(OUT)check_mycheckcommand.o $(OUT)check_findpos.o $(OUT)check_deletespice.o \
$(OUT)check_listcount.o $(OUT)check_append.o $(OUT)check_reverse.o \
$(OUT)check_listcreatenode.o $(OUT)check_listaddbegin.o 

debug : CFLAGS += -g3
debug : app.exe

release : CFLAGS += -DNDEBUG -g0
release : app.exe

app.exe: $(OBJS) $(OUT)app.o
	$(CC) $^ -o $@
unit_tests.exe: $(OBJS) $(OBJS_UNIT)
	$(CC) $^ -o $@ -lcheck -lsubunit -lm -lpthread -lrt

unit_tests1.exe: $(OBJS) $(OBJS_UNIT)
	$(CC) $^ -o $@ -lcheck -lsubunit -lm -lpthread -lrt

$(OUT)check_%.o : $(UNIT)check_%.c
	cd out && $(CC) $(CFLAGS) $(INC) -c ../$<

$(OUT)%.o : $(SRC)%.c
	cd out && $(CC) $(CFLAGS) $(INC) -c ../$<

func_tests: app.exe
	bash ./run_pos.sh
	bash ./run_neg.sh

run_unit_vg: unit_tests.exe
	valgrind --leak-check=full --leak-resolution=med --leak-check=full ./unit_tests.exe

run_app_vg: app.exe
	valgrind --leak-check=full --leak-resolution=med --track-origins=yes -s --show-reachable=yes --tool=memcheck ./app.exe
	
run_func_vg: app.exe
	touch out.txt
	valgrind --leak-check=full --leak-resolution=med --track-origins=yes -s --show-reachable=yes --tool=memcheck ./app.exe < func_tests/pos_in_01.txt > out.txt
	valgrind --leak-check=full --leak-resolution=med --track-origins=yes -s --show-reachable=yes --tool=memcheck ./app.exe < func_tests/pos_in_02.txt > out.txt
	valgrind --leak-check=full --leak-resolution=med --track-origins=yes -s --show-reachable=yes --tool=memcheck ./app.exe < func_tests/pos_in_03.txt > out.txt
	valgrind --leak-check=full --leak-resolution=med --track-origins=yes -s --show-reachable=yes --tool=memcheck ./app.exe < func_tests/pos_in_04.txt > out.txt
	valgrind --leak-check=full --leak-resolution=med --track-origins=yes -s --show-reachable=yes --tool=memcheck ./app.exe < func_tests/pos_in_05.txt > out.txt
	valgrind --leak-check=full --leak-resolution=med --track-origins=yes -s --show-reachable=yes --tool=memcheck ./app.exe < func_tests/pos_in_06.txt > out.txt
	valgrind --leak-check=full --leak-resolution=med --track-origins=yes -s --show-reachable=yes --tool=memcheck ./app.exe < func_tests/pos_in_07.txt > out.txt
	valgrind --leak-check=full --leak-resolution=med --track-origins=yes -s --show-reachable=yes --tool=memcheck ./app.exe < func_tests/pos_in_08.txt > out.txt
	valgrind --leak-check=full --leak-resolution=med --track-origins=yes -s --show-reachable=yes --tool=memcheck ./app.exe < func_tests/pos_in_09.txt > out.txt
	
	valgrind --leak-check=full --leak-resolution=med --track-origins=yes -s --show-reachable=yes --tool=memcheck ./app.exe < func_tests/neg_in_01.txt > out.txt; true
	valgrind --leak-check=full --leak-resolution=med --track-origins=yes -s --show-reachable=yes --tool=memcheck ./app.exe < func_tests/neg_in_02.txt > out.txt; true
	valgrind --leak-check=full --leak-resolution=med --track-origins=yes -s --show-reachable=yes --tool=memcheck ./app.exe < func_tests/neg_in_03.txt > out.txt; true
	valgrind --leak-check=full --leak-resolution=med --track-origins=yes -s --show-reachable=yes --tool=memcheck ./app.exe < func_tests/neg_in_04.txt > out.txt; true
	valgrind --leak-check=full --leak-resolution=med --track-origins=yes -s --show-reachable=yes --tool=memcheck ./app.exe < func_tests/neg_in_05.txt > out.txt; true
	valgrind --leak-check=full --leak-resolution=med --track-origins=yes -s --show-reachable=yes --tool=memcheck ./app.exe < func_tests/neg_in_06.txt > out.txt; true
	valgrind --leak-check=full --leak-resolution=med --track-origins=yes -s --show-reachable=yes --tool=memcheck ./app.exe < func_tests/neg_in_07.txt > out.txt; true
	valgrind --leak-check=full --leak-resolution=med --track-origins=yes -s --show-reachable=yes --tool=memcheck ./app.exe < func_tests/neg_in_08.txt > out.txt; true
	valgrind --leak-check=full --leak-resolution=med --track-origins=yes -s --show-reachable=yes --tool=memcheck ./app.exe < func_tests/neg_in_09.txt > out.txt; true
	valgrind --leak-check=full --leak-resolution=med --track-origins=yes -s --show-reachable=yes --tool=memcheck ./app.exe < func_tests/neg_in_10.txt > out.txt; true
	valgrind --leak-check=full --leak-resolution=med --track-origins=yes -s --show-reachable=yes --tool=memcheck ./app.exe < func_tests/neg_in_11.txt > out.txt; true
	valgrind --leak-check=full --leak-resolution=med --track-origins=yes -s --show-reachable=yes --tool=memcheck ./app.exe < func_tests/neg_in_12.txt > out.txt; true
	valgrind --leak-check=full --leak-resolution=med --track-origins=yes -s --show-reachable=yes --tool=memcheck ./app.exe < func_tests/neg_in_13.txt > out.txt; true
	valgrind --leak-check=full --leak-resolution=med --track-origins=yes -s --show-reachable=yes --tool=memcheck ./app.exe < func_tests/neg_in_14.txt > out.txt; true
	valgrind --leak-check=full --leak-resolution=med --track-origins=yes -s --show-reachable=yes --tool=memcheck ./app.exe < func_tests/neg_in_15.txt > out.txt; true
	valgrind --leak-check=full --leak-resolution=med --track-origins=yes -s --show-reachable=yes --tool=memcheck ./app.exe < func_tests/neg_in_16.txt > out.txt; true
	valgrind --leak-check=full --leak-resolution=med --track-origins=yes -s --show-reachable=yes --tool=memcheck ./app.exe < func_tests/neg_in_17.txt > out.txt; true

	rm out.txt
	
run_unit_dm: unit_tests.exe
	drmemory -lib_blacklist "*" -batch --  ./unit_tests.exe

run_app_dm: app.exe
	drmemory -lib_blacklist "*" -batch -- ./app.exe
	
run_func_dm: app.exe
	drmemory -lib_blacklist "*" -batch -- ./app.exe func_tests/pos_01_in.txt out.txt p
	drmemory -lib_blacklist "*" -batch -- ./app.exe func_tests/pos_02_in.txt out.txt p
	drmemory -lib_blacklist "*" -batch -- ./app.exe func_tests/pos_03_in.txt out.txt s
	drmemory -lib_blacklist "*" -batch -- ./app.exe func_tests/pos_04_in.txt out.txt s
	drmemory -lib_blacklist "*" -batch -- ./app.exe func_tests/pos_05_in.txt out.txt r
	drmemory -lib_blacklist "*" -batch -- ./app.exe func_tests/pos_06_in.txt out.txt r
	drmemory -lib_blacklist "*" -batch -- ./app.exe func_tests/pos_07_in.txt out.txt i 3 4
	drmemory -lib_blacklist "*" -batch -- ./app.exe func_tests/pos_08_in.txt out.txt i 2 1
	drmemory -lib_blacklist "*" -batch -- ./app.exe func_tests/pos_09_in.txt out.txt i 2 45
	
	drmemory -lib_blacklist "*" -batch -- ./app.exe func_tests/neg_01_in.txt out.txt; true
	drmemory -lib_blacklist "*" -batch -- ./app.exe func_tests/neg_02_in.txt out.txt; true
	drmemory -lib_blacklist "*" -batch -- ./app.exe func_tests/neg_03_in.txt out.txt; true
	drmemory -lib_blacklist "*" -batch -- ./app.exe func_tests/neg_04_in.txt out.txt; true
	drmemory -lib_blacklist "*" -batch -- ./app.exe func_tests/neg_05_in.txt out.txt; true
	drmemory -lib_blacklist "*" -batch -- ./app.exe func_tests/neg_06_in.txt out.txt; true
	drmemory -lib_blacklist "*" -batch -- ./app.exe func_tests/neg_07_in.txt out.txt; true
	drmemory -lib_blacklist "*" -batch -- ./app.exe func_tests/neg_08_in.txt out.txt; true
	drmemory -lib_blacklist "*" -batch -- ./app.exe func_tests/neg_09_in.txt out.txt; true
	drmemory -lib_blacklist "*" -batch -- ./app.exe func_tests/neg_10_in.txt out.txt; true
	drmemory -lib_blacklist "*" -batch -- ./app.exe func_tests/neg_11_in.txt out.txt; true
	drmemory -lib_blacklist "*" -batch -- ./app.exe func_tests/neg_12_in.txt out.txt; true
	
.PHONY : clean debug release func
clean :
	$(RM) $(OUT)*.o *.exe
func : app.exe
	./run_tests.sh