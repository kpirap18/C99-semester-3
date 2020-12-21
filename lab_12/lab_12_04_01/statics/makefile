CC = gcc
INCPATH = ../inc/
INC = -I $(INCPATH)
LIBINCPATH = ../../lib/inc/
LIBINC = -I $(LIBINCPATH)
OUT = ./out/
LIBOUT = ../lib/out/
SRC = ./src/
LIBSRC = ../lib/src/
UNIT = ./unit_tests/
FLAGA = -D STATICS
CFLAGS = -pedantic -Wall -Werror -Wextra -Wvla -Wfloat-equal -Wfloat-conversion -std=c99

OBJS = $(LIBOUT)mysort.o $(LIBOUT)key.o $(LIBOUT)parsing.o

OBJS_UNIT = $(OUT)check_avarage.o $(OUT)check_compare.o $(OUT)check_file_size.o \
$(OUT)check_key.o $(OUT)check_key_count.o $(OUT)check_mysort.o \
$(OUT)check_parsing_array.o $(OUT)check_main.o $(OUT)check_swap.o

debug : CFLAGS += -g3
debug : app.exe

release : CFLAGS += -DNDEBUG -g0
release : app.exe

func_dm : CFLAGS += -ggdb
func_dm : run_func_dm

func: libapp.a app.exe
	./run_test.bat

app.exe: libapp.a $(OUT)app.o
	$(CC) $(OUT)app.o -L. -lapp -o $@
	
unit_tests.exe: libapp.a $(OBJS_UNIT) 
	$(CC) $^ -L. -lapp -o $@ -lcheck #-lsubunit -lm -lpthread -lrt

$(OUT)check_%.o : $(UNIT)check_%.c
	cd out && $(CC) $(CFLAGS) $(INC) -c ../$<

$(OUT)%.o : $(SRC)%.c
	cd out && $(CC) $(CFLAGS) $(INC) -c ../$<
	
$(LIBOUT)%.o : $(LIBSRC)%.c
	cd ../lib/out && $(CC) $(CFLAGS) $(FLAGA) $(LIBINC) -c ../$<

%.a : $(OBJS)
	ar rc $@ $(OBJS)
	ranlib $@
	
run_unit_dm: unit_tests.exe
	drmemory -lib_blacklist "*" -batch --  ./unit_tests.exe

run_app_dm: libapp.a app.exe
	drmemory -lib_blacklist "*" -batch -- ./app.exe
	
run_func_dm: libapp.a app.exe
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
	$(RM) $(OUT)*.o *.exe *.a $(LIBOUT)*.o
