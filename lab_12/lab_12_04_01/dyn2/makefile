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
CFLAGS = -pedantic -Wall -Wextra -Wvla -Wfloat-equal -Wfloat-conversion -std=c99 #-Werror

OBJS = $(LIBOUT)key.o $(LIBOUT)parsing.o $(LIBOUT)mysort.o

OBJS_UNIT = $(OUT)check_main.o $(OUT)check_avarage.o $(OUT)check_compare.o \
$(OUT)check_file_size.o $(OUT)check_key.o $(OUT)check_key_count.o $(OUT)check_mysort.o \
$(OUT)check_parsing_array.o $(OUT)check_swap.o

debug : CFLAGS += -g3
debug : app.exe

release : CFLAGS += -DNDEBUG -g0
release : app.exe

func_dm : CFLAGS += -ggdb
func_dm : run_func_dm

app.exe: libapp.dll $(OUT)app.o
	$(CC) $(OUT)app.o -o $@
	
unit_tests.exe: libapp.dll $(OBJS_UNIT) 
	$(CC) $^ -o $@ -lcheck #-lsubunit -lm -lpthread -lrt

%.dll : $(OBJS)
	$(CC) -shared $^ -Wl,--subsystem,windows -o $@
	
$(OUT)check_%.o : $(UNIT)check_%.c
	cd out && $(CC)  $(INC) -c ../$<

$(OUT)app.o : $(SRC)app.c
	cd out && $(CC) $(CFLAGS) $(INC) -c ../$< # не работает
	
$(LIBOUT)%.o : $(LIBSRC)%.c
	cd ../lib/out && $(CC) $(CFLAGS) $(FLAGDLL) $(LIBINC) -c ../$<

	
run_unit_dm: unit_tests.exe
	drmemory -lib_blacklist "*" -batch --  ./unit_tests.exe

run_app_dm: app.exe
	drmemory -lib_blacklist "*" -batch -- ./app.exe
	
run_func_dm: libapp.dll app.exe
	drmemory -lib_blacklist "*" -batch -- ./app.exe func_tests/pos_01_in.txt out.txt 
	drmemory -lib_blacklist "*" -batch -- ./app.exe func_tests/pos_02_in.txt out.txt f
	drmemory -lib_blacklist "*" -batch -- ./app.exe func_tests/pos_03_in.txt out.txt 
	drmemory -lib_blacklist "*" -batch -- ./app.exe func_tests/pos_04_in.txt out.txt 
	drmemory -lib_blacklist "*" -batch -- ./app.exe func_tests/pos_05_in.txt out.txt 
	drmemory -lib_blacklist "*" -batch -- ./app.exe func_tests/pos_06_in.txt out.txt f
	drmemory -lib_blacklist "*" -batch -- ./app.exe func_tests/pos_07_in.txt out.txt 
	drmemory -lib_blacklist "*" -batch -- ./app.exe func_tests/pos_08_in.txt out.txt f
	
	drmemory -lib_blacklist "*" -batch -- ./app.exe func_tests/neg_01_in.txt out.txt ; true
	drmemory -lib_blacklist "*" -batch -- ./app.exe func_tests/neg_02_in.txt out.txt f; true
	drmemory -lib_blacklist "*" -batch -- ./app.exe func_tests/neg_03_in.txt out.txt f; true
	drmemory -lib_blacklist "*" -batch -- ./app.exe func_tests/neg_04_in.txt out.txt f; true
	drmemory -lib_blacklist "*" -batch -- ./app.exe func_tests/neg_05_in.txt out.txt f; true
	drmemory -lib_blacklist "*" -batch -- ./app.exe func_tests/neg_06_in.txt out.txt f; true
	drmemory -lib_blacklist "*" -batch -- ./app.exe func_tests/neg_07_in.txt out.txt f; true
	drmemory -lib_blacklist "*" -batch -- ./app.exe func_tests/neg_08_in.txt out.txt f; true
	drmemory -lib_blacklist "*" -batch -- ./app.exe func_tests/neg_09_in.txt out.txt f; true
	drmemory -lib_blacklist "*" -batch -- ./app.exe func_tests/neg_10_in.txt out.txt f; true
	drmemory -lib_blacklist "*" -batch -- ./app.exe func_tests/neg_11_in.txt out.txt f; true
	drmemory -lib_blacklist "*" -batch -- ./app.exe func_tests/neg_12_in.txt out.txt f; true
	
.PHONY : clean debug release
clean :
	$(RM) $(OUT)*.o *.exe *.dll $(LIBOUT)*.o
