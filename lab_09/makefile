CC = clang
INCPATH = ../inc/
INC = -I $(INCPATH)
OUT = ./out/
SRC = ./src/
UNIT = ./unit_tests/
CFLAGS = -pedantic -Wall -Werror -Wextra -Wvla -Wfloat-equal -Wfloat-conversion -std=gnu99

OBJS = $(OUT)film.o $(OUT)film_arr.o $(OUT)my_check.o
OBJS_UNIT = $(OUT)check_main.o $(OUT)check_f_count.o $(OUT)check_film_copy.o  \
$(OUT)check_film_found.o $(OUT)check_film_init.o $(OUT)check_film_read.o \
$(OUT)check_my_check_feild.o $(OUT)check_my_check_key.o

.PHONY : debug
debug : CFLAGS += -g3
debug : app.exe

.PHONY : release
release : CFLAGS += -DNDEBUG -g0
release : app.exe

app.exe: $(OBJS) $(OUT)app.o
	$(CC) $^ -o $@
unit_tests.exe: $(OBJS) $(OBJS_UNIT)
	$(CC) $^ -o $@ -lcheck -lpthread -lrt -lsubunit -lm

$(OUT)%.o: $(SRC)%.c 
	cd out && $(CC) $(CFLAGS) $(INC) -c ../$<

$(OUT)check_%.o : $(UNIT)check_%.c
	cd out && $(CC) $(CFLAGS) $(INC) -c ../$<

.PHONY : run_unit_vg 
run_unit_vg: unit_tests.exe
	valgrind --leak-check=full --leak-resolution=med ./unit_tests.exe

.PHONY : run_app_vg 
run_app_vg: app.exe
	valgrind --leak-check=full --leak-resolution=med ./app.exe

.PHONY : run_unit_vg 
run_func_vg: app.exe
	valgrind --leak-check=full --leak-resolution=med ./app.exe

.PHONY : clean
clean :
	$(RM) $(OUT)*.o *.exe

