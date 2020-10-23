CC = gcc
INC = ./inc/
OUT = ./out/
SRC = ./src/
UNIT = ./unit_tests/
CFLAGS = -pedantic -Wall -Werror -Wextra -Wvla -Wfloat-equal -Wfloat-conversion -std=gnu99

INCFILE := $(wildcard $(INC)*.h)

OBJS = $(OUT)film.o $(OUT)film_arr.o $(OUT)my_check.o
OBJS_UNIT = $(OUT)check_main.o $(OUT)check_f_count.o $(OUT)check_film_copy.o  \
$(OUT)check_film_found.o $(OUT)check_film_init.o $(OUT)check_film_read.o \
$(OUT)check_my_check_feild.o $(OUT)check_my_check_key.o

debug : CFLAGS += -g3
debug : app.exe

release : CFLAGS += -DNDEBUG -g0
release : app.exe

app.exe: $(OBJS) $(OUT)app.o
	$(CC) $^ -o $@
unit_tests.exe: $(OBJS) $(OBJS_UNIT)
	$(CC) $^ -lcheck -o $@

$(OUT)app.o: $(SRC)main.c $(INCFILE)
	cd out && $(CC) $(CFLAGS) -c ../$<
$(OUT)film.o: $(SRC)film.c $(INCFILE)
	cd out && $(CC) $(CFLAGS) -c ../$<
$(OUT)film_arr.o: $(SRC)film_arr.c $(INCFILE)
	cd out && $(CC) $(CFLAGS) -c ../$<
$(OUT)my_check.o: $(SRC)my_check.c $(INCFILE)
	cd out && $(CC) $(CFLAGS) -c ../$<

$(OUT)check_main.o: $(UNIT)check_main.c $(INCFILE)
	cd out && $(CC) $(CFLAGS) -c ../$<
$(OUT)check_f_count.o: $(UNIT)check_f_count.c $(INCFILE)
	cd out && $(CC) $(CFLAGS) -c ../$<
$(OUT)check_film_copy.o: $(UNIT)check_film_copy.c $(INCFILE)
	cd out && $(CC) $(CFLAGS) -c ../$<
$(OUT)check_film_found.o: $(UNIT)check_film_found.c $(INCFILE)
	cd out && $(CC) $(CFLAGS) -c ../$<
$(OUT)check_film_init.o: $(UNIT)check_film_init.c $(INCFILE)
	cd out && $(CC) $(CFLAGS) -c ../$<
$(OUT)check_film_read.o: $(UNIT)check_film_read.c $(INCFILE)
	cd out && $(CC) $(CFLAGS) -c ../$<
$(OUT)check_my_check_feild.o: $(UNIT)check_my_check_feild.c $(INCFILE)
	cd out && $(CC) $(CFLAGS) -c ../$<
$(OUT)check_my_check_key.o: $(UNIT)check_my_check_key.c $(INCFILE)
	cd out && $(CC) $(CFLAGS) -c ../$<


run_unit_dr: unit_tests.exe
	drmemory -lib_blacklist "*" -batch -- unit_tests.exe

run_app_dr: app.exe
	drmemory -lib_blacklist "*" -batch -- app.exe
run_func_dr: app.exe


.PHONY : clean debug release
clean :
	$(RM) $(OUT)*.o *.exe
