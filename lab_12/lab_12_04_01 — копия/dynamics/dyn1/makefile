CC = gcc
INCPATH = ../inc/
INC = -I $(INCPATH)
LIBINCPATH = ../../lib/inc/
LIBINC = -I $(LIBINCPATH)
LIBOUT = ../lib/out/
OUT = ./out/
SRC = ./src/
UNIT = ./unit_tests/
LIBSRC = ../lib/src/
FLAGDLL = -D EXPORTS
CFLAGS = -pedantic -Wall -Werror -Wextra -Wvla -Wfloat-equal -Wfloat-conversion -std=c99

OBJS = $(LIBOUT)key.o $(LIBOUT)parsing.o $(LIBOUT)mysort.o

#OBJS_UNIT = $(OUT)check_main.o  $(OUT)check_pop.o $(OUT)check_comparator.o \
#$(OUT)check_task_02.o $(OUT)check_task_03.o $(OUT)check_my_check.o \
#$(OUT)check_find.o $(OUT)check_filelen.o $(OUT)check_insert.o \
#$(OUT)check_listcreatenode.o $(OUT)check_listread.o $(OUT)check_listaddbegin.o \
#$(OUT)check_copy.o $(OUT)check_front_back_split.o $(OUT)check_sorted_merge.o 

debug : CFLAGS += -g3
debug : app.exe

release : CFLAGS += -DNDEBUG -g0
release : app.exe

func_dm : CFLAGS += -ggdb
func_dm : run_func_dm

app.exe: libapp.dll $(OUT)app.o
	$(CC) $(OUT)app.o -L. -lapp -o $@
	
unit_tests.exe: $(OBJS) $(OBJS_UNIT)
	$(CC) $^ -o $@ -lcheck #-lsubunit -lm -lpthread -lrt

%.dll : $(OBJS)
	$(CC) -shared $^ -Wl,--subsystem,windows -o $@
	
$(OUT)check_%.o : $(UNIT)check_%.c
	cd out && $(CC) $(CFLAGS) $(INC) -c ../$<

$(OUT)app.o : $(SRC)app.c
	cd out && $(CC) $(CFLAGS) $(INC) -c ../$<
	
$(LIBOUT)%.o : $(LIBSRC)%.c
	cd ../lib/out && $(CC) $(CFLAGS) $(FLAGDLL) $(LIBINC) -c ../$<


	
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
	
	drmemory -lib_blacklist "*" -batch -- ./app.exe func_tests/neg_01_in.txt out.txt p; true
	drmemory -lib_blacklist "*" -batch -- ./app.exe func_tests/neg_02_in.txt out.txt s; true
	drmemory -lib_blacklist "*" -batch -- ./app.exe func_tests/neg_03_in.txt out.txt r; true
	drmemory -lib_blacklist "*" -batch -- ./app.exe func_tests/neg_04_in.txt out.txt p; true
	drmemory -lib_blacklist "*" -batch -- ./app.exe func_tests/neg_05_in.txt out.txt p; true
	drmemory -lib_blacklist "*" -batch -- ./app.exe func_tests/neg_06_in.txt out.txt s; true
	drmemory -lib_blacklist "*" -batch -- ./app.exe func_tests/neg_07_in.txt out.txt r; true
	drmemory -lib_blacklist "*" -batch -- ./app.exe func_tests/neg_08_in.txt out.txt ; true
	drmemory -lib_blacklist "*" -batch -- ./app.exe func_tests/neg_09_in.txt out.txt j k j k; true
	drmemory -lib_blacklist "*" -batch -- ./app.exe func_tests/neg_10_in.txt out.txt i 8; true
	drmemory -lib_blacklist "*" -batch -- ./app.exe func_tests/neg_11_in.txt out.txt i 6 g; true
	drmemory -lib_blacklist "*" -batch -- ./app.exe func_tests/neg_12_in.txt out.txt i j 9; true
	
.PHONY : clean debug release
clean :
	$(RM) $(OUT)*.o *.exe *.dll $(LIBOUT)*.o
